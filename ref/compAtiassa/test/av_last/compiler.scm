(define match
  (letrec ((match
	    (lambda (pat e ret-vals ret-fail)
	      (cond ((and (pair? pat) (pair? e))
		     (match (car pat) (car e)
			    (lambda (vals-car)
			      (match (cdr pat) (cdr e)
				     (lambda (vals-cdr)
				       (ret-vals
					(append vals-car vals-cdr)))
				     ret-fail))
			    ret-fail))
		    ((and (vector? pat) (vector? e)
			  (= (vector-length pat) (vector-length e))
			  (match (vector->list pat) (vector->list e)
				 ret-vals ret-fail)))
		    ((procedure? pat)
		     (let ((v (pat e)))
		       (if v (ret-vals v) (ret-fail))))
		    ((equal? pat e) (ret-vals '()))
		    (else (ret-fail))))))
    (lambda (pat e ret-with ret-fail)
      (match pat e
	     (lambda (vals) (apply ret-with vals))
	     ret-fail))))

(define ?
  (lambda (name . guards)
    (let ((guard?
	   (lambda (e)
	     (andmap 
	      (lambda (g?) (g? e))
	      guards))))
      (lambda (value)
	(if (guard? value)
	    (list value)
	    #f)))))

(define _ (? 'dont-care))

;;; composing patterns

(define pattern-rule
  (lambda (pat handler)
    (lambda (e failure)
      (match pat e handler failure))))

(define compose-patterns
  (letrec ((match-nothing
	    (lambda (e failure)
	      (failure)))
	   (loop
	    (lambda (s)
	      (if (null? s)
		  match-nothing
		  (let ((match-rest
			 (loop (cdr s)))
			(match-first (car s)))
		    (lambda (e failure)
		      (match-first e
		       (lambda ()
			 (match-rest e failure)))))))))
    (lambda patterns
      (loop patterns))))

(print-gensym #f)

(define simple-const?
  (let ((options (list boolean? char? number? string? null?)))
    (lambda (input)
      (or (ormap (lambda (check?) (check? input)) options)
	      (equal? (void) input)))))

(define *reserved-words*
  '(and begin cond define do else if lambda
    let let* letrec or quasiquote unquote 
    unquote-splicing quote set!))

(define var?
  (lambda (input)
    (and (symbol? input)
	 (not (is-reserved? input)))))

(define is-reserved?
  (lambda (input)
    (ormap
     (lambda (check) (eq? input check))
     *reserved-words*)))

(define is-not-reserved?
  (lambda (input)
   (not (ormap
     (lambda (check) (eq? input check))
     *reserved-words*))))

(define *void-object* (if #f #f))

(define check-lambda
  (lambda (v ret-pro ret-imp ret-symbol)
    (cond ((pair? v)
               (check-lambda (cdr v) 
                              ret-pro
                             (lambda (s a)
                                (ret-imp (cons (car v) s) a))
                             (lambda ()
                                (ret-imp (list (car v)) (cdr v)))
            ))
    ((null? v) (ret-pro))
    ((symbol? v) (ret-symbol))
    (else (error 'Input "Lambda syntax error")))
    ))

(define beginify
  (lambda (exprs)
    (cond ((null? exprs) *void-object*)
          ((null? (cdr exprs)) (car exprs))
          (else `(begin ,@exprs)))
    ))

(define is-member?
  (lambda (var lst)
    (ormap (lambda (l)(equal? var l)) lst)))

(define is-duplicate?
  (lambda (vars)
    (if (null? vars) #f
        (if (not (pair? vars)) #f
            (if (is-member? (car vars) (cdr vars)) #t
                (is-duplicate? (cdr vars)))))))

(define with
  (lambda (s f) 
    (apply f s))) 

(define Ym
  (lambda fs
    (let ((ms (map
		(lambda (fi)
		  (lambda ms
		    (apply fi (map (lambda (mi)
				     (lambda args
				       (apply (apply mi ms) args))) ms))))
		fs)))
      (apply (car ms) ms))))

(define expand-letrec
  (lambda (letrec-expr)
    (with letrec-expr
      (lambda (_letrec ribs . exprs)
	(let* ((fs (map car ribs))
	       (lambda-exprs (map cdr ribs))
	       (nu (gensym))
	       (nu+fs `(,nu ,@fs))
	       (body-f `(lambda ,nu+fs ,@exprs))
	       (hofs
		(map (lambda (lambda-expr) `(lambda ,nu+fs ,@lambda-expr))
		  lambda-exprs)))
	  `(Ym ,body-f ,@hofs))))))


(define expand-qq
  (lambda (e)
    (cond ((unquote? e) (cadr e))
	  ((unquote-splicing? e)
	   (error 'expand-qq "unquote-splicing here makes no sense!"))
	  ((pair? e)
	   (let ((a (car e))
		 (b (cdr e)))
	     (cond ((unquote-splicing? a) `(append ,(cadr a) ,(expand-qq b)))
		   ((unquote-splicing? b) `(cons ,(expand-qq a) ,(cadr b)))
		   (else `(cons ,(expand-qq a) ,(expand-qq b))))))
	  ((vector? e) `(list->vector ,(expand-qq (vector->list e))))
	  ((or (null? e) (symbol? e)) `',e)
	  (else e))))

(define ^quote?
  (lambda (tag)
    (lambda (e)
      (and (pair? e)
	   (eq? (car e) tag)
	   (pair? (cdr e))
	   (null? (cddr e))))))

(define unquote? (^quote? 'unquote))
(define unquote-splicing? (^quote? 'unquote-splicing))
    
(define parse
  (let ((run
	 (compose-patterns
          (pattern-rule
	   (? 'c simple-const?)
	   (lambda (c) `(const ,c)))          
          (pattern-rule
   	   `(quote ,(? 'c))
            	   (lambda (c) `(const ,c)))
          (pattern-rule
	   (? 'v var?)
	   (lambda (v) `(var ,v)))
    	  (pattern-rule
	   `(if ,(? 'test) ,(? 'dit) ,(? 'dif))
	   (lambda (test dit dif)
	     `(if3 ,(parse test) ,(parse dit) ,(parse dif))))
          (pattern-rule
	   `(if ,(? 'test) ,(? 'dit))
	   (lambda (test dit)
	     `(if3 ,(parse test) ,(parse dit) (const ,*void-object*))))
	  (pattern-rule
           `(lambda ,(? 'v) ,(? 'e) . ,(? 'es list?))
           (lambda (v e es)
             (check-lambda v
               (lambda () `(lambda-simple ,v ,(parse (beginify (cons e es)))))
               (lambda (s a) `(lambda-opt ,s ,a  ,(parse (beginify (cons e es)))))
               (lambda () `(lambda-variadic ,v ,(parse (beginify (cons e es)))))
                 )))
    	  (pattern-rule
	   `(define ,(? 'var var?) ,(? 'value))
	   (lambda (var value)
	     `(define ,(parse var) ,(parse value)))) 
    	  (pattern-rule
	   `(define (,(? 'var var?) . ,(? 'vars)) ,(? 'value))
	   (lambda (var vars value)
	     `(define ,(parse var) ,(parse (list 'lambda vars value)))))
        	  (pattern-rule
	   `(,(? 'var is-not-reserved?) . ,(? 'vars))
	   (lambda (var vars)
	     `(applic ,(parse var) ,(map parse vars))))
           (pattern-rule
	   `(begin . ,(? 'exprssions list?))
	   (lambda (exprssions)
           (if (not (pair? exprssions)) `(const ,*void-object*)
               (if (null? (cdr exprssions)) (parse (car exprssions))
	                                `(seq ,(map parse exprssions))))))
        	  (pattern-rule
	   `(let ,(? 'var list?) . ,(? 'expr))
	   (lambda (var expr)
             (if (is-duplicate? (map car var)) (error 'Input "There is one or more variables with the same name")
	     (parse `((lambda ,(map car var) ,(beginify expr)) ,@(map cadr var))))))          
           (pattern-rule
	   `(let* () ,(? 'expr) . ,(? 'exprs list?))
	     (lambda (expr exprs)
	      (parse (beginify (cons expr exprs)))))
	   (pattern-rule
	   `(let* ((,(? 'var var?) ,(? 'val)) . ,(? 'rest)) . ,(? 'exprs))
	     (lambda (var val rest exprs)
	      (parse `(let ((,var ,val))
		       (let* ,rest . ,exprs)))))
	   (pattern-rule
	   `(letrec ,(?'var list?). ,(? 'expr))
	     (lambda (var expr)
        (if (is-duplicate? (map car var)) (error 'letrec "There is one or more variables with the same name")  
	      (parse (expand-letrec `(letrec ,var . ,expr))))))
    
          (pattern-rule
	   `(and . ,(? 'expr))
	     (lambda (expr)
               (if (null? expr) `(const #t)
                  (if (null? (cdr expr)) `,(parse (car expr))
                      (parse `(if ,(car expr) (and ,@(cdr expr)) #f))))))			
          (pattern-rule
	   `(cond (else . ,(? 'rule list?)))
	     (lambda (rule)
                  (parse `,(beginify rule))))
          (pattern-rule
	   `(cond ,(? 'rule list?) . ,(? 'rules))
	     (lambda (rule rules)
                  (if (null? rules) (parse `(if ,(car rule) ,(beginify (cdr rule))))
                      (parse `(if ,(car rule) ,(beginify (cdr rule)) (cond ,@rules))))))
	  (pattern-rule
	   `(,'quasiquote . ( ,(? 'expr)))
	   (lambda (expr) (parse `,(expand-qq expr))))
    (pattern-rule
      '(or)
      (lambda () `(const #f)))
    	  (pattern-rule
	   `(or ,(? 'expr). ,(? 'exprs))
	   (lambda (expr exprs) 
                  (if (null? exprs) (parse expr)
                      (if (list? exprs)
                          `(or ,(map parse (cons expr exprs)))
                          `(or ,(parse expr) ,(parse exprs))))))
    )))
    (lambda (e)
      (run e
	   (lambda ()
	     (error 'parse
		    (format "I can't recognize this: ~s" e)))))))

;;-------------------------------------------------------------------------------------------------------------------------
(define search-parameter
  (lambda (var param_list minor not-found)
    (cond 
      ((null? param_list) (not-found))
      ((eq? (car param_list) var) (minor 0))
      (else (search-parameter 
              var 
              (cdr param_list)
              (lambda(min) (minor (+ 1 min)))
              not-found)))))

(define search-env
  (lambda (var env major-minor not-found)
    (if (null? env) (not-found)
        (search-parameter
          var
          (car env)
          (lambda(min) (major-minor 0 min))
          (lambda() (search-env
                     	var
                      (cdr env)
                      (lambda (maj min)
                        (major-minor (+ 1 maj) min))
                      not-found))))))

(define map-on-loop
  (lambda (op params env pe)
    (if (null? pe)	'()
        (cons (op (car pe) params env)
              (map-on-loop op params env (cdr pe))))))


(define pe->lex-pe
  (letrec ((loop
             (lambda (pe params env)
               (cond
                 ((not (pair? pe)) pe)
                 ((eq? (car pe) 'var)
                  (with pe
                    (lambda (w v)
                      (search-parameter 
                        v 
                       	params
                        (lambda (min) `(pvar ,v ,min))
                        (lambda ()
                          (search-env
                           	v
                           	env
                            (lambda (maj min)
                              `(bvar ,v ,maj ,min))
                            (lambda ()
                              `(fvar ,v))))))))
                 ((eq? (car pe) 'lambda-simple)
                  (with pe
                    (lambda (w args body)
                      `(lambda-simple ,args ,(loop body args (cons params env))))))
                 ((eq? (car pe) 'lambda-opt)
                  (with pe
                    (lambda (w args opt body)
                      `(lambda-opt ,args ,opt ,(loop body `(,@args ,opt) (cons params env))))))
                 ((eq? (car pe) 'lambda-variadic)
                  (with pe
                    (lambda (w args body)
                      `(lambda-variadic ,args ,(loop body (list args) (cons params env))))))
                 ((eq? (car pe) 'const) pe)
                 ((eq? (car pe) 'if3)
                  `(if3 ,(loop (cadr pe) params env) ,(loop (caddr pe) params env) ,(loop (cadddr pe) params env)))
                 ((eq? (car pe) 'define)
                  `(define ,(loop (cadr pe) params env) ,(loop (caddr pe) params env)))
                 ((eq? (car pe) 'applic)
                  `(applic ,(loop (cadr pe) params env) ,(map-on-loop loop params env (caddr pe))))
                 ((eq? (car pe) 'tc-applic)
                  `(tc-applic ,(loop (cadr pe) params env) ,(map-on-loop loop params env (caddr pe))))
                 ((eq? (car pe) 'seq)
                  `(seq ,(map-on-loop loop params env (cadr pe))))
                 ((eq? (car pe) 'or)
                  `(or ,(map-on-loop loop params env (cadr pe))))
                 (else (cons (loop (car pe) params env) (loop (cdr pe) params env)))			                 
 		))))		
		(lambda (pe)
			(loop pe '() '()))))


(define map-on-annotate
  (lambda (pe tp?)
    (if (null? pe) '()
        (if (null? (cdr pe)) (list (loop-annotate-tc (car pe) tp?))
            (cons (loop-annotate-tc (car pe) #f) (map-on-annotate (cdr pe) tp?))))))


(define loop-annotate-tc
  (lambda (pe tp?)
    (cond
      ((null? pe) pe)
      ((not (pair? pe)) pe)
      ((eq? (car pe) 'var) pe)
      ((eq? (car pe) 'fvar) pe)
      ((eq? (car pe) 'bvar) pe)
      ((eq? (car pe) 'pvar) pe)
      ((eq? (car pe) 'or)
       `(or ,(map-on-annotate (cadr pe) tp?)))
      ((eq? (car pe) 'if3)
       `(if3 ,(loop-annotate-tc (cadr pe) #f)
             ,(loop-annotate-tc (caddr pe) tp?)
             ,(loop-annotate-tc (cadddr pe) tp?)))
      ((eq? (car pe) 'seq)
       `(seq ,(map-on-annotate (cadr pe) tp?)))
      ((eq? (car pe) 'lambda-simple)
       `(lambda-simple ,(cadr pe) ,(loop-annotate-tc (caddr pe) #t)))
      ((eq? (car pe) 'lambda-opt)
       `(lambda-opt ,(cadr pe) ,(caddr pe) ,(loop-annotate-tc (cadddr pe) #t)))
      ((eq? (car pe) 'lambda-variadic)
       `(lambda-variadic ,(cadr pe) ,(loop-annotate-tc (caddr pe) #t)))
      ((eq? (car pe) 'applic)
       (if tp?
       `(tc-applic ,(loop-annotate-tc (cadr pe) #f) ,(loop-annotate-tc (caddr pe) #f))
       `(applic ,(loop-annotate-tc (cadr pe) #f) ,(map-on-annotate (caddr pe) #f))))
      ((eq? (car pe) 'define)
       `(define ,(loop-annotate-tc (cadr pe) #f) ,(loop-annotate-tc (caddr pe) #f)))
      (else (cons (loop-annotate-tc (car pe) tp?) (loop-annotate-tc (cdr pe) tp?) )))))
      
      
(define annotate-tc
  (lambda (pe)
    (loop-annotate-tc pe #f)))

;;--------------------------------------------------------------------------------------------------------------------------------
(define pe-const?
  (lambda (e)
    (if (eq? (car e) 'const) #t #f)))
		
(define pe-bvar?
  (lambda (e)
    (if (eq? (car e) 'bvar) #t #f)))
		
(define pe-pvar?
  (lambda (e)
    (if (eq? (car e) 'pvar) #t #f)))

(define pe-fvar?
  (lambda (e)
    (if (eq? (car e) 'fvar) #t #f)))

(define pe-if3?
  (lambda (e)
    (if (eq? (car e) 'if3) #t #f)))
		
(define pe-or?
  (lambda (e)
    (if (eq? (car e) 'or) #t #f)))
		
(define pe-seq?
  (lambda (e)
    (if (eq? (car e) 'seq) #t #f)))

(define pe-lambda-simple?
  (lambda (e)
   (if (eq? (car e) 'lambda-simple) #t #f)))

(define pe-lambda-opt?
  (lambda (e)
    (if (eq? (car e) 'lambda-opt) #t #f)))
		
(define pe-lambda-variadic?
  (lambda (e)
    (if (eq? (car e) 'lambda-variadic) #t #f)))

(define pe-applic?
  (lambda (e)
    (if (eq? (car e) 'applic) #t #f)))

(define pe-tc-applic?
  (lambda (e)
    (if (eq? (car e) 'tc-applic) #t #f)))

(define pe-define?
  (lambda (e)
    (if (eq? (car e) 'define) #t #f)))


;;--------------------------------------------------------------------------------------------------------------------------------
;;Used to save all the const and the fvar
(define index 101)

;;Global list of all the fvar
(define f_table '())

;; Label Genaretor
(define label-gen
    (let ((n 0))
      (lambda (name)
        (set! n (+ n 1))
        (string-append name (number->string n)))))

(define error
  (lambda (msg)
    (display msg)))

;; Topological sort for the code
(define topological-sort
  (lambda (e)
    (cond
      ((or (null? e) (equal? e *void-object*) (boolean? e) (number? e) (char? e) (string? e))
       `(,e))
      ((symbol? e)
      	`(,@(topological-sort (symbol->string e)) ,e))
      ((pair? e)
       `(,@(topological-sort (car e)) ,@(topological-sort (cdr e)) ,e))
      ((vector? e)
       `(,@(apply append (map topological-sort (vector->list e))) ,e))
      ;;TODO-error
      (else `(,e)))))

;; Remove duplicates, booleans, void, null from list
(define list->set
  (lambda (c_list set)
    (cond
      ((null? c_list) set)
      ((or (boolean? (car c_list))
           (null? (car c_list))
           (equal? (car c_list) *void-object*)
           (list? (member (car c_list) set)))
       (list->set (cdr c_list) set))
      (else
        (list->set (cdr c_list) (append set (list (car c_list)))))
      )))

;; Extract all the const from the parsed expression
(define consts-from-e
  (lambda (e c_e)
    (cond 
      ((or (null? e) (not (list? e))) c_e)
      ((and (pe-const? e) (or 
                              (boolean? (cadr e)) 
                              (eq? *void-object* (cadr e)) 
                              (null? (cadr e)))) c_e)
      ((and (pe-const? e) 
            (or (pair? (cadr e)) 
                (vector? (cadr e)) 
                (symbol? (cadr e))))
       (append c_e (topological-sort (cadr e))))
      ((pe-const? e)
       (append c_e (cdr e)))
      (else (consts-from-e (cdr e) (consts-from-e (car e) c_e)))
      )))
	  
(define fvar-from-e
  (lambda (e f_e)
    (cond 
      ((or (null? e) (not (list? e))) f_e)
      ((pe-fvar? e)
       (append f_e (list (cadr e))))
      (else (fvar-from-e (cdr e) (fvar-from-e (car e) f_e)))
      )))

;; Add to each const his type and his index
(define set-i-t-to-const
  (lambda (c_e i-v-t_e i)
    (if (null? c_e) (begin (set! index i) i-v-t_e)
        (let ((car_c_e (car c_e)))
          (cond
            ((number? car_c_e)
             (set-i-t-to-const
               (cdr c_e)
               (append i-v-t_e (list (list i car_c_e 'number)))
               (+ i 2)))
            ((char? car_c_e)
             (set-i-t-to-const
               (cdr c_e)
               (append i-v-t_e (list (list i car_c_e 'char)))
                 (+ i 2)))
            ((string? car_c_e)
             (set-i-t-to-const
               (cdr c_e)
               (append i-v-t_e (list (list i car_c_e 'string)))
               (+ i (+ 2 (string-length car_c_e)))))
            ((vector? car_c_e)
             (set-i-t-to-const
               (cdr c_e)
               (append i-v-t_e (list (list i car_c_e 'vector)))
               (+ i (+ 2 (vector-length car_c_e)))))
            ((pair? car_c_e)
             (set-i-t-to-const
               (cdr c_e)
               (append i-v-t_e (list (list i car_c_e 'pair)))
               (+ i 3)))
            ((symbol? car_c_e)
             (set-i-t-to-const
               (cdr c_e)
               (append i-v-t_e (list (list i car_c_e 'symbol)))
               (+ i 2)))
            ((or (boolean? car_c_e) (eq? *void-object* car_c_e) (null? car_c_e)) (set-i-t-to-const (cdr c_e) i-v-t_e i))
            ;;TODO : Inser Error Code
            (else (list)))
          ))))
            
(define string->push_chars
  (lambda (e i)
    (if (eq? i -1) ""
        (string-append
          (string->push_chars e (- i 1))
          "PUSH(IMM(" (number->string (char->integer (string-ref e i))) "));\n"))))

(define vector->push_elements
  (lambda (e i c_table)
    (if (eq? i -1) ""
        (string-append
          (vector->push_elements e (- i 1) c_table)
          "PUSH(IMM(" (number->string (get-const-index (vector-ref e i) c_table)) "));\n" ))))	            
            
(define get-const-index
  (lambda (c c_table)
    (cond
      ((null? c) 2)
      ((boolean? c) (if c 5 3))
      ((eq? *void-object* c) 1)
      ((equal? c (cadar c_table)) (caar c_table))
      (else (get-const-index c (cdr c_table))))))

(define cg-consts_table
  (lambda (c_table current_c_table)
    (if (null? current_c_table) ""
        (let ((type_current (caddar current_c_table))
              (index_current (caar current_c_table))
              (value_current (cadar current_c_table)))
          (cond
            ((eq? 'number type_current)
             (string-append
               "PUSH(IMM(" (number->string value_current) "));\n"
               "CALL(MAKE_SOB_INTEGER);\n"
               "DROP(IMM(1));\n"
               (cg-consts_table c_table (cdr current_c_table))))
            ((eq? 'char type_current)
             (string-append
               "PUSH(IMM(" (number->string (char->integer value_current)) "));\n"
               "CALL(MAKE_SOB_CHAR);\n"
               "DROP(IMM(1));\n"
               (cg-consts_table c_table (cdr current_c_table))))
            ((eq? 'string type_current)
             (string-append
               (string->push_chars value_current (- (string-length value_current) 1))
               "PUSH(IMM(" (number->string (string-length value_current)) "));\n"
               "CALL(MAKE_SOB_STRING);\n"
               "DROP(IMM(" (number->string (+ 1 (string-length value_current))) "));\n"
               (cg-consts_table c_table (cdr current_c_table))))
            ((eq? 'vector type_current)
             (string-append
               (vector->push_elements value_current (- (vector-length value_current) 1) c_table)
               "PUSH(IMM(" (number->string (vector-length value_current)) "));\n"
               "CALL(MAKE_SOB_VECTOR);\n"
               "DROP(IMM(" (number->string (+ 1 (vector-length value_current))) "));\n"
               (cg-consts_table c_table (cdr current_c_table))))
            ((eq? 'pair type_current)
             (string-append
               "PUSH(" (number->string (get-const-index (cdr value_current) c_table)) ");\n"
               "PUSH(" (number->string (get-const-index (car value_current) c_table)) ");\n"
               "CALL(MAKE_SOB_PAIR);\n"
               "DROP(IMM(2));\n"
               (cg-consts_table c_table (cdr current_c_table))))
            ((eq? 'symbol type_current)
             (string-append
               "PUSH(IMM(2));\n"
               "CALL(MALLOC);\n"
               "DROP(IMM(1));\n"
               "MOV(IND(R0), IMM(T_SYMBOL));\n"
               ;; TODO: search the symbol string and insert the index to the next line
               "MOV(INDD(R0,1), IMM(0));\n"
               (cg-consts_table c_table (cdr current_c_table))))
           (else  (cg-consts_table c_table (cdr current_c_table))	))))))


(define cg-add-value-to-symbol
  (lambda (c_table current_c_table)
    (if (null? current_c_table) ""
        (let ((type_current (caddar current_c_table))
              (index_current (caar current_c_table))
              (value_current (cadar current_c_table)))
          (if (eq? 'symbol type_current)
              (string-append
                "MOV (R0,"(number->string (+ 1 index_current))");\n"
                "MOV (IND(R0),"(number->string (get-const-index (symbol->string value_current) c_table))");\n"
                (cg-add-value-to-symbol c_table (cdr current_c_table)))
              (cg-add-value-to-symbol c_table (cdr current_c_table)))))))

;;Each fvar will be represented as symbol, currently fvar is undifiend
(define code-gen-start-fvar
	(lambda (curr_f_table)
		(if (null? curr_f_table) ""
			(let ((type_current (caddar curr_f_table))
				  (index_current (caar curr_f_table))
				  (value_current (cadar curr_f_table)))
             (string-append
               "PUSH(IMM(2));\n"
               "CALL(MALLOC);\n"
               "DROP(IMM(1));\n"
               "MOV(IND(R0), IMM(T_SYMBOL));\n"
               "MOV(INDD(R0,1), IMM(T_UNDEF));\n"
			   (code-gen-start-fvar (cdr curr_f_table)))))))
(define code-gen
  (lambda (expr)
    (code-gen-rec expr 0 0)))

(define code-gen-rec
  (lambda (expr c_table env p_size)
    (cond
      ((pe-const? expr) (code-gen-const expr c_table))
      ((pe-if3? expr) (code-gen-if3 expr env p_size c_table))
      ((pe-or? expr) (code-gen-or (cadr expr) env p_size c_table))
      ((pe-seq? expr) (code-gen-seq (cadr expr) env p_size c_table))
      ((pe-pvar? expr) (code-gen-pvar (cdr expr)))
      ((pe-bvar? expr) (code-gen-bvar (cdr expr)))
      ((pe-fvar? expr) (code-gen-fvar (cdr expr) c_table))
      ((pe-lambda-simple? expr) (code-gen-lambda-simple expr env p_size c_table))
      ((pe-lambda-opt? expr) (code-gen-lambda-opt (cdr expr) env p_size c_table))
      ((pe-lambda-variadic? expr) (code-gen-lambda-variadic (cdr expr) env p_size c_table))
      ((pe-applic? expr) (code-gen-applic (cdr expr) env p_size c_table))
      ((pe-tc-applic? expr) (code-gen-tc-applic (cdr expr) env p_size c_table))
      ((pe-define? expr) (code-gen-define (cdr expr) env p_size c_table))
      (else "")
      )))

(define code-gen-if3
  (lambda (expr env param c_table)
    (with expr
      (lambda (if3 test dit dif)
        (let ((dif_label (label-gen "dif"))
              (exit_label (label-gen "exit"))
              (dit_label (label-gen "dit"))
              (code-gen-test (code-gen-rec test c_table env param))
              (code-gen-dit (code-gen-rec dit c_table env param ))
              (code-gen-dif (code-gen-rec dif c_table env param )))
          (string-append
            code-gen-test 
            "CMP (IND(R0), T_BOOL);\n"
            "JUMP_NE("dit_label");\n"
            "CMP (INDD(R0,1),IMM(0));\n"
            "JUMP_EQ("dif_label");\n"
            dit_label":\n"
            code-gen-dit "\n"
            "JUMP("exit_label");\n"
            dif_label":\n"
            code-gen-dif "\n"
            exit_label ":"))))))
            
(define code-gen-const
  (lambda (expr c_table)
    (with expr
      (lambda (const c_expr)
        (cond ((boolean? c_expr) 
              (if (equal? c_expr #t)
                  "MOV(R0, IMM(SOB_TRUE));\n"
                  "MOV(R0, IMM(SOB_FALSE));\n"))
              ((equal? c_expr *void-object*) 
               "MOV(R0, IMM(SOB_VOID));\n")
              ((null? c_expr)
               "MOV(R0, IMM(SOB_NIL));\n")
              ((or (number? c_expr) (char? c_expr) (string? c_expr) 
                   (symbol? c_expr) (vector? c_expr) (pair? c_expr))
               (string-append "MOV(R0,IMM(" 
                              (number->string (get-const-index c_expr c_table)) "));\n"))
              (else
               (error "Bad const type!")))))))


(define code-gen-or
  (lambda (expr env param c_table)
    (let ((or_label (label-gen "or_"))
          (exit_from_or (label-gen "exit_from_or_")))
      (string-append
        (map-on-or-elements expr env param "" exit_from_or c_table)
       	exit_from_or ":\n"))))

(define map-on-or-elements
  (lambda (expr env param curr_or_gen exit c_table)
    (if (null? expr) curr_or_gen
        (cond 
          ((not (list? expr))
           (string-append
             curr_or_gen
             (code-gen-rec expr c_table env param)
             "CMP(INDD(R0,1),IMM(0));\n"
             "JUMP_NE("exit");\n"))
          ((list? expr)
           (map-on-or-elements
             (cdr expr)
             env
             param
             (string-append
               curr_or_gen
               (code-gen-rec (car expr) c_table env param)
               "CMP(INDD(R0,1),IMM(0));\n"
               "JUMP_NE("exit");\n")
             exit c_table))
          ;;TODO: Insert Error
          (else curr_or_gen)))))

(define code-gen-seq
  (lambda (expr env param c_table)
      (string-append
        "/* START sequance  */\n"
        (map-on-seq-elements expr env param "" c_table)
       	)))

(define map-on-seq-elements
  (lambda (expr env param curr_seq_gen c_table)
    (if (null? expr) curr_seq_gen
        (cond 
          ((not (list? expr))
           (string-append
             curr_seq_gen
             (code-gen-rec expr c_table env param)
             ))
          ((list? expr)
           (map-on-seq-elements
             (cdr expr)
             env
             param
             (string-append
               curr_seq_gen
               (code-gen-rec (car expr) c_table env param)
               )
             c_table
             ))
         
          (else (error "Error in seq"))))))

(define code-gen-pvar
  (lambda (expr)
    (string-append
      "MOV(R0,FPARG(" (number->string (+ 2 (cadr expr))) "));\n")))
							
(define code-gen-bvar
  (lambda (expr)
    (string-append
      "MOV(R0,FPARG(0));\n"
      "MOV(R0,INDD(R0," (number->string (cadr expr)) "));\n"
      "MOV(R0,INDD(R0," (number->string (caddr expr)) "));\n")))

(define code-gen-fvar
  (lambda (expr c_table)
      (string-append
        "/*Find the fvar index in the const table*/\n"
        "MOV(R0," (number->string (get-const-index (car expr) f_table))  ");\n"
        "/*Check if we found the fvar*/\n"
        "CMP(R0,IMM(SOB_NIL));\n"
        "JUMP_EQ(ERROR_VAR_NOT_FOUND);\n"
        "/*Put the value of the fvar in R0*/\n"
        "MOV(R0,INDD(R0,1));\n"
		"CMP(R0,T_UNDEF);\n"
		"JUMP_EQ(UNDEF_VAR);\n"
)))

(define create-lambda-closure
  (lambda (expr env p_size code_label)
    (let ((extend_env (label-gen "extend_env_"))
          (end_extend_env (label-gen "end_extend_env_"))
          (add_param (label-gen "add_param_"))
          (end_add_param (label-gen "end_add_param_")))      
    (string-append
      "/*Save current registers value*/\n"
      "PUSH(R1); PUSH(R2); PUSH(R3); PUSH(R4); PUSH(R5);\n"
      
      "/*Create Place for new clouser-T_CLOUSRE,env pointer, code_pointer*/\n"
      "PUSH(IMM(3));\n"
      "CALL(MALLOC);\n"
      "DROP(IMM(1));\n"
      "MOV(IND(R0),IMM(T_CLOSURE));\n"
      
      "/*Save the pointer for the new clouser*/\n"
      "MOV(R1,R0);\n" 
      
      "/*extend the env*/\n"
      "PUSH(IMM(" (number->string (+ env 1)) "));\n"
      "CALL(MALLOC);\n"
      "DROP(IMM(1));\n"
      
      "/*Save pointer to the new env*/\n"
      "MOV(INDD(R1,1),R0);\n"
      
      "/*Define iterator to copy env pointers*/\n"
      "MOV(R2,IMM(0));\n"
      "MOV(R3,IMM(1));\n"
      extend_env":\n"
      
      "/*Check if we end to copy all the env*/\n"
      "CMP(R2,IMM(" (number->string env) "));\n"
      "JUMP_GE("end_extend_env");\n"
      
      "/*Get the last env pointer from the stack*/\n"
      "MOV(R4,FPARG(0));\n"
      
      "/*Copy from the last env to the new env in index+1*/\n"
      "MOV(INDD(R0,R3),INDD(R4,R2));\n"
      
      "/*Increase Iterators*/\n"
      "ADD(R2,IMM(1));\n"
      "ADD(R3,IMM(1));\n"
      "JUMP("extend_env");\n"
      end_extend_env":\n"
      
      "/*Save in r2 the new env pointer*/\n"
      "MOV(R2,R0);\n"
      
      "/*Create place to the lambda parameters*/\n"
      "PUSH(" (number->string p_size) ");\n"
      "CALL(MALLOC);\n"
      "DROP(IMM(1));\n"
      
      "/*Connect the env in place 0 to the lambda params*/\n"
      "MOV(IND(R2),R0);\n"
      
      "/*Define iterators to copy parameters*/\n"
      "MOV(R4,IMM(0));\n"
      "MOV(R5,IMM(2));\n"
      add_param":\n"
      
      "/*Check if we copy all the parameters*/\n"
      "CMP(R4," (number->string  p_size) ");\n"
      "JUMP_GE("end_add_param");\n"
      
      "/*Copy the current parameter from the stack*/\n"
      "MOV(INDD(R0,R4),FPARG(R5));\n"
      "/*Increase iterators*/\n"
      "ADD(R5,IMM(1));\n"
      "ADD(R4,IMM(1));\n"
      "JUMP("add_param");\n"
      end_add_param":\n"
      
      "/*Save pointer to the lambda body in the clousre we created*/\n"
      "MOV(INDD(R1,2),LABEL("code_label"));\n"
      
      "/*R0 will hold the pointer to the new clouser*/\n"
      "MOV(R0,R1);\n"
      
      "/*Return the registers to the previous state*/\n"
      "POP(R5); POP(R4); POP(R3); POP(R2); POP(R1);\n"
      "JUMP(end_"code_label");\n"
))))

(define code-gen-lambda-opt
  (lambda (expr env p_size c_table)
    (let
      ((lambda-body-lbl (label-gen "lambda_opt_body_lbl_"))
      (generate_body (label-gen "generate_body_"))
      (add_param_to_list (label-gen "add_param_to_list_"))
      (end_add_param_to_list (label-gen "end_add_param_to_list_"))
      (params (car expr))
      (opt-param (number->string (+ (length (car expr)) 2)))
      (body (caddr expr)))
      (string-append
        (create-lambda-closure expr env p_size lambda-body-lbl)
        lambda-body-lbl ":\n"
        "/*Save current FP,R5 value and move fp to the start of the stack */\n"
        "PUSH(FP);\n"
        "MOV(FP,SP);\n"
        "PUSH(R5);\n"
        "/* Get the parameters number*/\n"
        "MOV(R5,FPARG(1));\n"
        "/*Check if there are parameters you dont know about them */\n"
        "CMP(R5,IMM(" (number->string(length params)) "));\n"
        "JUMP_EQ("generate_body");\n"
        "/*Create list of pairs and save the parameters value on the last known parameter*/\n"
        "/*Create the last pair, magic+nill*/\n"
        "ADD(R5,IMM(1));\n"
        "PUSH(IMM(SOB_NIL));\n"
        "PUSH(FPARG(R5));\n"
        "CALL(MAKE_SOB_PAIR);\n"
        "DROP(IMM(2));\n"
        "/*Return to r5 the paramters number*/\n"
        "SUB(R5,IMM(1));\n"
        "/*foreach parameter create pair with his value and pointer to the next parameter backward*/\n"
        add_param_to_list ":\n"
        "/*check if we finish to over all the parameters we dont know about them*/\n"
        "CMP(R5,IMM(" opt-param"));\n"
        "JUMP_LT("end_add_param_to_list");\n"
        "/*Else, add the current parameter to the list*/\n"
        "/*Push the pointer to the next parameter in the list*/\n"
        "PUSH(R0);\n"
        "/*push the current parameter value*/\n"
        "PUSH(FPARG(R5));\n"
        "/*Make pair of them, R0 will be the pointer to the pair*/\n"
        "CALL(MAKE_SOB_PAIR);\n"
        "DROP(IMM(2));\n"
        "/*next parameter backward*/\n"
        "SUB(R5,IMM(1));\n"
        "JUMP("add_param_to_list");\n"
        "/*Finished to add all the opt parameter*/\n"
        end_add_param_to_list ":\n"
        "/*put the list on the first unknown parameter*/\n"
        "MOV(FPARG(" opt-param "),R0);\n"
        generate_body ":\n"
        "POP(R5);\n"
        "/* Genreate code for the lambda body */\n"
        (code-gen-rec body c_table (+ env 1) (+ 1 (length params)))
        "/* Return to the old frame pointer*/\n"
        "POP(FP);\n"
        "RETURN;\n"
        "end_"lambda-body-lbl":\n"
      ))))

(define code-gen-lambda-simple
  (lambda (expr env p_size c_table)
    (with expr
      (lambda (l params body)
        (let
          ((lambda_body_lbl (label-gen "lambda_body_")))
          (string-append
            "/*Create closure to the current lambda*/\n"
            (create-lambda-closure expr env p_size lambda_body_lbl)
            lambda_body_lbl":\n"
            "/*Save FP,SP current value*/\n"
            "\tPUSH(FP);\n"
            "\tMOV(FP,SP);\n"
            "/*Generate code for the body of the lambda*/\n"
            (code-gen-rec body c_table (+ env 1) (length params))
            "/*Return the FP to the previous place*/\n"
            "\tPOP(FP);\n"
            "RETURN;\n"
            "end_"lambda_body_lbl":\n"))
        ))))

(define code-gen-applic
  (lambda (expr env param c_table)
    (let 
      ((lblapplic (label-gen "applic"))
      (oprnds (cadr expr))
      (body (car expr)))
    (string-append
      "/* START_" lblapplic "*/\n"
      "/* backup R1 */"
      "PUSH(R1);\n"
      "/* MAGIC - after the operands */"
      "PUSH(IMM(SOB_NIL));\n" ;magic
      "\n"
      "/* pushes the operands to stack */ \n\t /* -------------------- */\n"
      (map-cg-applic oprnds env param lblapplic 0 c_table) ; params
      "\n /* -------------------- */\n"
      "\n"
      "/* pushing number of operands to stack */\n"
      "PUSH(IMM(" (number->string (length oprnds)) "));\n" ; n-params
      "/* generate applic's operator code */\n"
      (code-gen-rec body c_table env param)
      "/* final stage of the procedure */\n"
      "CMP(IND(R0),IMM(T_CLOSURE));\n"
      "JUMP_NE(ERROR_APPLIC);\n"
      "PUSH(INDD(R0,1));\n" ; env
      "/* stack is ready - call the code address */\n"
      "CALLA(INDD(R0,2));\n"
      "/* calculate sum of \"push\"es to the stack and drop */ \n"
      "MOV(R1,STARG(0));\n"
      "ADD(R1,IMM(3));\n"
      "DROP(IMM(R1));\n"
      "POP(R1);\n\n"
      ))))

(define map-cg-applic
  (lambda (params_lst env param lbl index c_table)
    (if (null? params_lst)
        ""
        (string-append
          (map-cg-applic (cdr params_lst) env param lbl (+ index 1) c_table)
          "/* generating " lbl " - operand #" (number->string (+ index 1)) " value */\n"
          (code-gen-rec (car params_lst) c_table env param )
          "/*push operand #" (number->string (+ index 1)) " evaluated result*/\n"
          "PUSH(R0);\n"
          )
        )))

(define code-gen-tc-applic
  (lambda (expr env param c_table)
    (let 
	((lblapplic (label-gen "applic"))
	(lbl_start_loop (label-gen "start_loop"))
	(lbl_end_loop (label-gen "end_loop"))
	(oprnds (cadr expr))
	(body (car expr)))
	(string-append

	; prepare the new frame
	"\t/* START_" lblapplic "*/\n"
	
	"/* MAGIC - after the operands */"
	"\tPUSH(IMM(SOB_NIL));\n" ;magic
	
	" \t/* pushes the operands to stack */ \n\t /* -------------------- */\n"
	(map-cg-applic oprnds env param lblapplic 0 c_table) ; params
	"\n\t /* -------------------- */\n"
	"\n"
	
	"\t/* pushing number of operands to stack */\n"
	"\tPUSH(IMM(" (number->string (length oprnds)) "));\n" ; n-params

	"\t/* generate tc-applic's operator code */\n"
	(code-gen-rec body c_table env param)

	"\t/* check it is a closure */\n"
	"\tCMP(IND(R0),IMM(T_CLOSURE));\n"
	"\tJUMP_NE(ERROR_APPLIC);\n"
	;"printf(\"NOT_ERROR!!!\");\nfflush(stdout);"
	"\tPUSH(INDD(R0,1));\n" ; env
	
	;---------------------------------------------------------------------------------
	; "PUSH(R5);PUSH(R6);PUSH(R7);PUSH(R8);PUSH(R9);"
	; Save FP - "old frame state"
	"\tMOV(R7,FP);\n"
      
	; save old frame parameters number
	"\tMOV(R9,FP);\n"
	"\tSUB(R9,4);\n"
	"\tMOV(R9,STACK(R9));\n"
	
	;copy and push the return address from the old-frame
	"\tMOV(R8,R7);\n"
	"\tSUB(R8,2);\n"
	"\tPUSH(STACK(R8));\n"       
	
	"\tMOV(R8,R7);\n"
	"\tDECR(R8);\n"
	"\tMOV(FP,STACK(R8));\n"

	; R6 = fp - 4 - STACK(fp-4)==num_of_parameters_in_old_frame
	"\tMOV(R6, R7);\n"        
	"\tSUB(R6, 4);\n"    
	"\tSUB(R6, STACK(R6));\n"
	
	; calculate dest address in stack = R6. source address = F7
	"\t/*replace the old frame*/\n"
	; loop r5 = SP-R7+1 = SP-source+1
	"\tMOV(R5,SP);\tSUB(R5,R7);\tINCR(R5);\n"
	
	; calculate shift for SP adjustment
	"\tMOV(R9,R7);\n"
	"\tSUB(R9,R6);\n"
					
	;"printf(\"\\n$| loop_size: %ld | $\", R5);\n"
	;"printf(\"BEFORE loop\");\n"
	;"printStack((long*)machine->stack);fflush(stdout);"
	
	"\t" lbl_start_loop ": CMP(R5,IMM(0));\n"
	"\tJUMP_EQ(" lbl_end_loop ");\n"
	"\tMOV(STACK(R6), STACK(R7));\n"
	"\tINCR(R6);\n"
	"\tINCR(R7);\n"
	"\tDECR(R5);\n"
	"\tJUMP(" lbl_start_loop ");\n"
	"\t" lbl_end_loop ":\n\n"
	
	; "printf(\"\\n$| SP-before: %ld | $\", SP);\n"
	
	; update SP - substruct the shift size made insidr the loop
	"\tSUB(SP,R9);\n"
	; "printf(\"\\n$| SP-after: %ld | $\", SP);\n"
	
	; "POP(R9);POP(R8);POP(R7);POP(R6);POP(R5);"

	;"printStack((long*)machine->stack);fflush(stdout);"
	"\t/* stack and frame(tc) are ready - jump to the code address */\n"
	"\tJUMPA(INDD(R0,2));\n"
))))


(define code-gen-lambda-variadic
  (lambda (expr env p_size c_table)
    (let 
      ((lambda-body-lbl (label-gen "lambda_var_body_lbl_"))
       (generate_body (label-gen "generate_var_body_"))
       (add_param_to_list (label-gen "add_param_to_list_"))
       (body (cadr expr)))
      (string-append
        (create-lambda-closure expr env p_size lambda-body-lbl)
        lambda-body-lbl ":\n"
        "/*Save current FP,R6 value and move fo to the start of the stack*/\n"
        "PUSH(FP);\n"
        "MOV(FP,SP);\n"
        "PUSH(R6);\n"
        "/* Get the parameters number*/\n"
        "MOV(R6,FPARG(1));\n"
        "/*Check if there are parameters*/\n"
        "CMP(R6,IMM(0));\n"
        "/*If there is not any parameters generate body*/\n"
        "JUMP_EQ("generate_body");\n"
        "/*Else create a list of pairs from the parameters*/\n"
        "/*Create the last pair, magic +nil*/\n"
        "ADD(R6,IMM(1));\n"
        "PUSH(IMM(SOB_NIL));\n"
        "PUSH(FPARG(R6));\n"
        "CALL(MAKE_SOB_PAIR);\n"
        "DROP(IMM(2));\n"
        "/*Return to r6 the parameters number*/\n"
        "SUB(R6,IMM(1));\n"
        "/*Loop over all the parameters backward*/\n"
        add_param_to_list ":\n"
        "/*Check if we finished to over all the parameters*/\n"
        "CMP(R6,IMM(2));\n"
        "JUMP_LT(end_"add_param_to_list");\n"
        "/*Push the pointer to the next parameter in the list*/\n"
        "PUSH(R0);\n"
        "/*Push the current parameter value*/\n"
        "PUSH(FPARG(R6));\n"
        "/*Make pair of them , R0 will be the pointer to the pair*/\n"
        "CALL(MAKE_SOB_PAIR);\n"
        "DROP(IMM(2));\n"
        "/*move the next parameter backward*/\n"
        "SUB(R6,IMM(1));\n"
        "JUMP("add_param_to_list");\n"
        "end_"add_param_to_list":\n"
        "MOV(FPARG(2),R0);\n"
        generate_body ":\n"
        "/*Return r6 to the value before we start the lambda*/\n"
        "POP(R6);\n"
        "/*Genrate CISC code for the body*/\n"
        (code-gen-rec body c_table (+ env 1) 1)
        "/*Return to the old frame pointer, R0 hold the lambda value*/\n"
        "POP(FP);\n"
        "RETURN;\n"
        "end_"lambda-body-lbl":\n"
		))))

(define code-gen-define
  (lambda (expr env p_size c_table)
	(let ((c_index (if (pe-const? (car expr)) (get-const-index (cadar expr) c_table) (get-const-index (cadar expr) f_table)) ))
    (string-append
      "/*Genrate code foe the definition and save the pointer to the result in R0*/\n"
      (code-gen-rec (cadr expr) c_table env p_size)
      "/*Get the symbol index we want to define, add 1 for the index of his value*/\n"
      "MOV(R1," (number->string (+ 1 c_index))  ");\n"
      "/*Save in his value the pointer to the definition result*/\n"
      "MOV(IND(R1),R0);\n"
      "/*Return void in R0*/\n"
      "MOV(R0,T_VOID);\n"
      ))
    ))

(define get-name-from-primitives
  (lambda (name)
    (cond
      ((equal? name 'bin+) "BIN_PLUS")
      ((equal? name 'bin-) "BIN_MINUS")
      ((equal? name 'bin*) "BIN_MUL")
      ((equal? name 'bin/) "BIN_DIVIDE")
      ((equal? name 'apply) "APPLY")
      ((equal? name 'bin<?) "BIN_LESS")
      ((equal? name 'bin=?) "BIN_EQUAL")
      ((equal? name 'boolean?) "IS_BOOLEAN")
      ((equal? name 'car) "CAR")
      ((equal? name 'cdr) "CDR")
      ((equal? name 'char->integer) "CHAR_TO_INT")
      ((equal? name 'char?) "IS_CHAR")
      ((equal? name 'cons) "CONS")
      ((equal? name 'eq?) "IS_EQ")
      ((equal? name 'integer?) "IS_INT")
      ((equal? name 'integer->char) "INT_TO_CHAR")
      ((equal? name 'make-string) "MAKE_STRING")
      ((equal? name 'make-vector) "MAKE_VECTOR")
      ((equal? name 'null?) "IS_NULL")
      ((equal? name 'number?) "IS_NUMBER")
      ((equal? name 'pair?) "IS_PAIR")
      ((equal? name 'procedure?) "IS_PROCEDURE")
      ((equal? name 'remainder) "REMAINDER")
      ((equal? name 'set-car!) "SET_CAR")
      ((equal? name 'set-cdr!) "SET_CDR")
      ((equal? name 'string-length) "STRING_LENGTH")
      ((equal? name 'string-ref) "STRING_REF")
      ((equal? name 'string-set!) "STRING_SET")
      ((equal? name 'string->symbol) "STRING_TO_SYMBOL")
      ((equal? name 'string?) "IS_STRING")
      ((equal? name 'symbol?) "IS_SYMBOL")
      ((equal? name 'symbol->string) "SYMBOL_TO_STRING")
      ((equal? name 'vector-length) "VECTOR_LEN")
      ((equal? name 'vector-ref) "VECTOR_REF")
      ((equal? name 'vector-set!) "VECTOR_SET")
      ((equal? name 'vector?) "IS_VECTOR")
      ((equal? name 'zero?) "IS_ZERO")
      (else '()))))

(define generate-fvar-primitive-closure
  (lambda (f_table)
    (if (null? f_table) ""
        (let ((func_name (get-name-from-primitives (cadar f_table))))
          (if (null? func_name) (generate-fvar-primitive-closure (cdr f_table))
              (string-append
                "PUSH(IMM(3));\n"
                "CALL(MALLOC);\n"
                "DROP(1);\n"
                "MOV(IND(R0),IMM(T_CLOSURE));\n"
                "MOV(INDD(R0,1),IMM(0));\n"
                "MOV(INDD(R0,2),LABEL("func_name"));\n"
                "MOV(R1," (number->string (caar f_table))");\n"
                "MOV(INDD(R1,1),R0);\n"
                (generate-fvar-primitive-closure (cdr f_table))))))))
                
				
;; Just for check some cases
(define check-status
  (lambda (parsed)
    (let ((c_table (set-i-t-to-const(consts-from-e parsed '()) '() 100)))
      (display
        (string-append
          (cg-consts_table c_table c_table)
          (cg-add-value-to-symbol c_table c_table))))))

(define code-gen-over-sexprs
  (lambda (e c_table)
    (if (null? e)
        ""
        (string-append
          (code-gen-rec (car e) c_table 0 0)
          (let ((next_lbl (label-gen "next_")))
            (string-append
              "CMP(R0,T_VOID);\n"
              "JUMP_EQ("next_lbl");\n"
              "PUSH(R0);\n"
              "CALL(WRITE_SOB);\n"
              "DROP(IMM(1));\n"
              next_lbl ":\n"))
          (code-gen-over-sexprs (cdr e) c_table)
          ))))

(define file->sexprs
  (lambda (filename)
    (let ((input (open-input-file filename)))
      (letrec ((run
                (lambda ()
                  (let ((e (read input)))
                    (if (eof-object? e)
                        (begin (close-input-port input)
                               '())
                        (cons e (run)))))))
      (run)))))

(define compile-scheme-file
  (lambda (inputFileName outputFileName)
    (let* ((output (open-output-file outputFileName 'replace))
           (input (map (lambda (x) (pe->lex-pe x))
		       (map parse
                                     (append
                                      (file->sexprs (string-append (path-parent inputFileName) "/support-code.scm"))
                                      (file->sexprs inputFileName))
                                   	)))
           (c_table (set-i-t-to-const (list->set (consts-from-e input '()) '()) '() index))
           (end_c_table_index index)
           (fvar_table (set-i-t-to-const (list->set (fvar-from-e input '()) '() ) '() index))
           )
      (begin
	  (set! f_table fvar_table)
	  (display
        (string-append
"	
#include <stdio.h>
#include <stdlib.h>
#include \"cisc.h\"

void printStack(long* arr){
  printf(\"\\n**************** STACK **********************\\n\");
  int i;
  for (i = 0; i < 130; i++){
     if (i % 10 == 0){
      printf(\"\\n\");
    }
    
    printf(\"[%d]: %ld\\t\", i, arr[i]);
  }
  printf(\"\\n\");
}

int main()
{
	START_MACHINE;
	
	JUMP(CONTINUE);

	#include \"scheme.lib\"
	#include \"char.lib\"
	#include \"io.lib\"
	#include \"math.lib\"
	#include \"string.lib\"
	#include \"system.lib\"
	
	#include \"debug_macros.h\"
	
	#define SOB_VOID 1
	#define SOB_NIL 2
	#define SOB_FALSE 3
	#define SOB_TRUE 5

	"
"
CONTINUE:
	
	/* Initialize stack with default values */\n
	
	/* Void */
	MOV(ADDR(1), IMM(T_VOID));
	
	/* Nil (Empty List) */
	MOV(ADDR(2), IMM(T_NIL));
	
	/* False (Boolean) */
	MOV(ADDR(3), IMM(T_BOOL));
	MOV(ADDR(4), IMM(0));
	
	/* True (Boolean) */
	MOV(ADDR(5), IMM(T_BOOL));
	MOV(ADDR(6), IMM(1));
	/*Place of run-time symbol list*/
 	MOV(ADDR(10),IMM(2));
	/* Increase address */
	ADD(ADDR(0), IMM(100))\n;
	MOV(R15,"(number->string end_c_table_index)");\n
	/* create constants table*/\n
	"
	
	  (cg-consts_table c_table c_table)
	
	"/* end of constants table creation */\n"
		
	"/* Add values to symbols */\n"
      
      (cg-add-value-to-symbol c_table c_table)
      (code-gen-start-fvar f_table)
      (generate-fvar-primitive-closure fvar_table)

     	"/* end insert values to symbols */\n"
	"
	/* Fake Env */\n
	PUSH(IMM(0));
	PUSH(IMM(SOB_NIL));
	PUSH(LABEL(END));
	PUSH(FP);
	MOV(FP,SP);

	/* code generation */
	"
	(code-gen-over-sexprs input c_table)	
	"
JUMP(END);

ERROR_APPLIC:
PUSH(49);
JUMP(WRITE_ERROR);

UNDEF_VAR:
PUSH(50);
JUMP(WRITE_ERROR);

ERROR_VAR_NOT_FOUND:
PUSH(51);
JUMP(WRITE_ERROR);

ARGS_FAULT:
PUSH(52);
JUMP(WRITE_ERROR);

NOT_INTEGER_ERROR:
PUSH(53);
JUMP(WRITE_ERROR);

NOT_PAIR_ERROR:
PUSH(54);
JUMP(WRITE_ERROR);

NOT_STRING_ERROR:
PUSH(55);
JUMP(WRITE_ERROR);

NOT_SYMBOL_ERROR:
PUSH(56);
JUMP(WRITE_ERROR);

NOT_CLOSURE_ERROR:
PUSH(57);
JUMP(WRITE_ERROR);

NOT_VECTOR_ERROR:
PUSH(58);
JUMP(WRITE_ERROR);

NOT_CHAR_ERROR:
PUSH(59);
JUMP(WRITE_ERROR);

INDEXES_MISMATCH:
PUSH(60);
JUMP(WRITE_ERROR);

WRITE_ERROR:
PUSH(69);
PUSH(82);
PUSH(82);
PUSH(79);
PUSH(82);
PUSH(6);
CALL(MAKE_SOB_STRING);
DROP(6);
PUSH(R0);
CALL(WRITE_SOB_STRING);
return 1;


END:			
	STOP_MACHINE;

	return 0;
}
")
				output)
(set! index 101)				;; check write / display
			(close-output-port output)))))