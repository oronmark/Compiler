(print-graph #f) ; display circular structures
(print-gensym #f) ; print gensym as g1234
(case-sensitive #f) ; ditto
(print-brackets #f) ; do not use brackets when pretty-printing

(revert-interaction-semantics) ; allow builtins to be redefined

;;; fix bug in optimizer
(#%$sputprop 'append '*flags* 122)
(#%$sputprop 'append! '*flags* 34)
(#%$sputprop 'list* '*flags* 1250)
(#%$sputprop 'cons* '*flags* 1250)

;;; And just for good luck :-)
(define with (lambda (s f) (apply f s)))

(load "pattern-matcher.scm")

(print-gensym #f)

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

(define *void-object* (if #f #f))

(define *reserved-words*
  '(and begin cond define do else if lambda
    let let* letrec or quasiquote unquote 
    unquote-splicing quote set!))
	
 (define simple-const?
	(lambda (e)
	  (or (boolean? e) (char? e) (number? e) (string? e))))
	  
(define var?
	(lambda (e) 
	  (and (symbol? e) (not (member e *reserved-words*)))))

(define var2?
	(lambda (e) 
	  (not (member e *reserved-words*))))

(define beginify
	(lambda (es)
			(cond ((null? es) 
					*void-object*)
				  ((null? (cdr es)) 
					(car es))
				  (else 
				  `(begin ,@es)))))
(define tail
	(lambda (lst)
		(if (or (not (pair? lst)) (null? (cdr lst)))
			lst
			(tail (cdr lst)))))

(define tail2
	(lambda (lst)
		(if (or (not (pair? lst)) (null? (cdr lst)))
			(car lst)
			(tail2 (cdr lst)))))
			
(define all-but-tail
	(lambda (lst acc)
		(if (or (not (pair? lst)) (null? (cdr lst)))
			acc
			(all-but-tail (cdr lst) (append acc (list (car lst)))))))

(define with (lambda (s f) (apply f s)))

(define expand-letrec
  (lambda (ribs exprs)
    (let* ((fs (map car ribs))
	   (lambda-exprs (map cdr ribs))
	   (nu (gensym))
	   (nu+fs `(,nu ,@fs))
	   (body-f `(lambda ,nu+fs ,@exprs))
	   (hofs
	    (map (lambda (lambda-expr) `(lambda ,nu+fs ,@lambda-expr))
	      lambda-exprs)))
      `(Ym ,body-f ,@hofs))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;Parse;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  
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
	  ;;if
	  (pattern-rule
	   `(if ,(? 'test) ,(? 'dit))
	   (lambda (test dit)
	     `(if3 ,(parse test) ,(parse dit) (const ,*void-object*))))
	  (pattern-rule
	   `(if ,(? 'test) ,(? 'dit) ,(? 'dif))
	   (lambda (test dit dif)
	     `(if3 ,(parse test) ,(parse dit) ,(parse dif))))
	  ;; let*
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
	   `(let ,(? 'defs) ,@(? 'body))
	   (lambda (defs body)
	     (parse `((lambda ,(map car defs) . ,body) ,@(map cadr defs)))))
	  (pattern-rule
	   `(letrec ,(? 'defs) . ,(? 'body))
	   (lambda (defs body) 
			 (parse (expand-letrec defs body))))
	  ;;and
	  (pattern-rule
	  `(and ,@(? 'args))
	   (lambda (args)
		(cond ((null? args) `(const , #t))
			  ((null? (cdr args)) (parse (car args)))
			  (else (parse `(if ,(car args) (and . ,(cdr args)) ,#f))))))
	  ;;cond
	  (pattern-rule
	  `(cond ,@(? 'args))
	   (lambda (args)
			(cond ((equal? (caar args) 'else) (parse (beginify (cdar args)))) 
				  ((null? (cdr args)) (parse `(if ,(caar args) ,(beginify (cdar args)))))
				  ;((equal? (caadr args) 'else) (parse `(if ,(caar args) ,(cadar args)  ,(cadadr args) )))
				  (else (parse `(if ,(caar args) ,(beginify (cdar args)) (cond . ,(cdr args))))))))
	  (pattern-rule
	   `(or)
	   (lambda () (parse #f)))
	  (pattern-rule
	   `(or ,(? 'expr))
	   (lambda (expr)
	     (parse expr)))
	  (pattern-rule
	   `(or . ,(? 'exprs list?))
	   (lambda (exprs)
	     `(or ,(map parse exprs))))
	  (pattern-rule
	   `(,'quasiquote ,(? 'expr))
	   (lambda (expr)
	     (parse (expand-qq expr))))
	  ;;begin
	  (pattern-rule
		`(begin ,@(? 'exprs))
		(lambda (exprs)
		(cond ((equal? exprs '()) `(const ,*void-object*)) 
			  ((equal? (length exprs) 1) (parse (car exprs)))
			  (else `(seq ,(map parse exprs))))))
	  ;;define-MIT
	  (pattern-rule
		`(define ,(? 'varv pair?) ,(? 'e))
		(lambda (varv e)
			(parse `(define ,(car varv) (lambda ,(cdr varv) ,e)))))
	  ;;define
	  (pattern-rule
	     `(define ,(? 'var var?) ,(? 'val))
		 (lambda (var val)
			`(define ,(parse var) ,(parse val))))
	  ;;lambda-simple
	 (pattern-rule
		`(lambda ,(? 'args list?)  ,@(? 'e))
		(lambda (args e)
			`(lambda-simple ,args ,(parse (beginify e)))))
	  ;;lambda-opt
	  (pattern-rule
	  `(lambda ,(? 'args pair? (lambda (x) (not (list? x))))  ,@(? 'e))
		(lambda (args e)
					`(lambda-opt ,(all-but-tail args '()) ,(tail args) ,(parse (beginify e)))))
	  ;;lambda-variadic
	  (pattern-rule
		`(lambda ,(? 'args var?) ,@(? 'e))
		(lambda (args e)
			`(lambda-variadic ,args ,(parse (beginify e)))))
	  ;;applic
	  #;(pattern-rule
		 `( ,(? 'app var?))
		 (lambda (app)
			`(applic ,(parse app) ,(list))))
	  (pattern-rule
	   `( ,(? 'proc) . ,(? 'exprs list?))
	   (lambda (proc exprs)
	     `(applic ,(parse proc) ,(map parse exprs))))
	  )))
	 
    (lambda (e)
      (run e
	   (lambda ()
	     (error 'parse
		    (format "I can't recognize this: ~s" e)))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;Assignment 2;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define pe->lex-pe
	(lambda (pe)
		(helper pe '())))
		
(define helper
	(lambda (pe env)
		(cond ((eq? (car pe) 'const) pe)
			  ((eq? (car pe) 'if3) `(if3 ,(helper (cadr pe) env) ,(helper (caddr pe) env) ,(helper (cadddr pe) env)))
			  ((eq? (car pe) 'var) (env-lookup (cadr pe) env 0))
			  ((eq? (car pe) 'or) `(or ,(map (lambda (x) (helper x env)) (cadr pe))))
			  ((eq? (car pe) 'seq) `(seq ,(map (lambda (x) (helper x env)) (cadr pe))))
			  ((eq? (car pe) 'define) `(define ,(helper (cadr  pe) '()) ,(helper (caddr pe) env))) 
			  ((eq? (car pe) 'applic) `(applic ,(helper (cadr pe) env) ,(map (lambda (x) (helper x env)) (caddr pe))))
			  ((eq? (car pe) 'tc-applic) `(tc-applic ,(helper (cadr pe) env) ,(map (lambda (x) (helper x env)) (caddr pe))))
			  ((eq? (car pe) 'lambda-simple) `(lambda-simple ,(cadr pe) ,(helper (caddr pe) (append (list (cadr pe)) env))))
			  ((eq? (car pe) 'lambda-opt) `(lambda-opt ,(cadr pe) ,(caddr pe) ,(helper (cadddr pe) (append (list (append (cadr pe) (list (caddr pe)))) env))))
			  ((eq? (car pe) 'lambda-variadic) `(lambda-variadic ,(cadr pe) ,(helper (caddr pe) (append (list (list (cadr pe))) env))))
			  (else pe))))

(define env-lookup
	(lambda (var env level)
		(cond ((null? env) `(fvar ,var))
			  ((member var (car env)) (if (zero? level) `(pvar ,var ,(find-var-index var (car env) 0))
														`(bvar ,var ,(- level 1) ,(find-var-index var (car env) 0))))
			  (else (env-lookup var (cdr env) (+ 1 level))))))
			  
(define find-var-index
	(lambda (var env i)
		(if (eq? (car env) var) i (find-var-index var (cdr env) (+ i 1)))))

(define annotate-tc
	(lambda (pe)
		(helper2 pe #f)))

(define helper2
	(lambda (pe tp?)
		(cond ((or (eq? (car pe) 'const) (eq? (car pe) 'var) (eq? (car pe) 'bvar) (eq? (car pe) 'pvar) (eq? (car pe) 'fvar)) pe)
			  ((eq? (car pe) 'or) `(or ,(append (map annotate-tc (all-but-tail (cadr pe) '())) (list (helper2 (tail2 (cadr pe)) tp?)))))
			  ((eq? (car pe) 'applic) (if tp? `(tc-applic ,(annotate-tc (cadr pe)) ,(map annotate-tc (caddr pe))) `(applic ,(annotate-tc (cadr pe)) ,(map annotate-tc (caddr pe)))))
			  ((eq? (car pe) 'if3) `(if3 ,(annotate-tc (cadr pe)) ,(helper2 (caddr pe) tp?) ,(helper2 (cadddr pe) tp?)))
			  ((eq? (car pe) 'define) `(define ,(cadr  pe) ,(annotate-tc (caddr pe))))
			  ((eq? (car pe) 'lambda-simple) `(lambda-simple ,(cadr pe) ,(helper2 (caddr pe) #t)))
			  ((eq? (car pe) 'lambda-opt) `(lambda-opt ,(cadr pe) ,(caddr pe) ,(helper2 (cadddr pe) #t)))
			  ((eq? (car pe) 'lambda-variadic) `(lambda-variadic ,(cadr pe) ,(helper2 (caddr pe) #t)))
			  ((eq? (car pe) 'seq) `(seq ,(append (map annotate-tc (all-but-tail (cadr pe) '())) (list (helper2 (tail2 (cadr pe)) tp?)))))
			  (else pe))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;Code Generator;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define consts-table (list))

(define fvars-table (list))

(define next-available-addr 500)

(define is-void?
	(lambda (pe)
		(equal? pe *void-object*)))

(define ^^label
  (lambda (name)
    (let ((n 0))
      (lambda ()
	(set! n (+ n 1))
	(string-append name
		       (number->string n))))))

(define set-next-available-addr
	(lambda ()
		(let ((last-const (tail2 consts-table)))
			(set! next-available-addr 
				(+ (car last-const) (length (caddr last-const)))))))

(define pre-processing
	(lambda (input-file output-file)
		(let ((sexprs (append (file->sexprs "support-code.scm") (file->sexprs input-file))))
		(begin (set! consts-table (constants-table sexprs))
  		(set-next-available-addr)
  		(let ((table (init-fvars-table next-available-addr)))
  			(set! fvars-table (mk-fvars-table (list->set (fvars-list sexprs) '()) table (+ (length table) next-available-addr))))))))

(define compile-scheme-file
  (lambda (input-file output-file)
  	(begin (if (file-exists? output-file) (delete-file output-file))
  	(pre-processing input-file output-file)
    (let ((output (open-output-file output-file))
    	  (consts-stmt (mk-c-constants-stmt consts-table)))
    	(begin 
    		   (display (prolog consts-stmt) output)
    		   (display (apply string-append (map 
    		   	(lambda (e) (string-append (code-gen (annotate-tc (pe->lex-pe (parse e))) 0) (print-sexpr))) 
    		   	(append (file->sexprs "support-code.scm") (file->sexprs input-file)))) output)
    		   (display (epilog) output)
    		   (close-output-port output))))))

(define ^pe?
  (lambda (key)
    (lambda (pe)
      (eq? (car pe) key))))

(define pe-const? (^pe? 'const))
(define pe-pvar? (^pe? 'pvar))
(define pe-bvar? (^pe? 'bvar))
(define pe-fvar? (^pe? 'fvar))
(define pe-const? (^pe? 'const))
(define pe-or? (^pe? 'or))
(define pe-applic? (^pe? 'applic))
(define pe-lambda-simple? (^pe? 'lambda-simple))
(define pe-tc-applic? (^pe? 'tc-applic))
(define pe-lambda-variadic? (^pe? 'lambda-variadic))
(define pe-lambda-opt? (^pe? 'lambda-opt))
(define pe-define? (^pe? 'define))
(define pe-seq? (^pe? 'seq))
(define pe-if3? (^pe? 'if3))

(define not-yet
  (lambda (pe)
    (error 'code-gen
	   (format "~a is not yet implemented" (car pe)))))

;;;;;;;;;;;;;;;;;;;;;;code-gen const;;;;;;;;;;;;;;;;;;;;;;
(define code-gen-const 
	(lambda (pe) 
			(string-append 
				"/* const */" nl 
				"\tMOV(R0,IMM(" (number->string (lookup-const pe consts-table)) "));" nl
				"/* const end */" nl)))
	;(cond ((null? pe) (string-append "\tMOV(R0,SOB_NIL);" nl))
	;	  ((and (boolean? pe) pe) (string-append "\tMOV(R0,SOB_BOOLEAN_TRUE);" nl))
	;	  ((and (boolean? pe) (not pe)) (string-append "\tMOV(R0,SOB_BOOLEAN_FALSE);" nl))
	;	  ((is-void? pe) (string-append "\tMOV(R0,SOB_VOID);" nl))
	;	  (else (display "blaaaaa")))))

;;;;;;;;;;;;;;;;;;;;;;code-gen or;;;;;;;;;;;;;;;;;;;;;;
(define code-gen-or 
	(lambda (e env-size) 
		(with e
			(lambda (or exprs)
				(let ((code-exprs (map (lambda (expr) (code-gen expr env-size)) exprs))
					  (label-exit (^label-orexit)))
					(apply string-append 
						(append 
							(list "/* or */" nl)
						    (map 
						    	(lambda (x) 
						    	 (string-append x "\tCMP(R0,SOB_BOOLEAN_FALSE);" nl
											     "\tJUMP_NE(" label-exit ");" nl)) 
						    	(all-but-tail code-exprs '()))
						    (tail code-exprs) 
						    (list label-exit ":" nl 
						    "/* or end */" nl))))))))

;;;;;;;;;;;;;;;;;;;;;;code-gen applic;;;;;;;;;;;;;;;;;;;;;;
(define code-gen-applic
	(lambda (e env-size)
		(with e
			(lambda (applic proc params)
				(let ((code-proc (code-gen proc env-size))
					  (code-params (reverse (map (lambda (e) (code-gen e env-size)) params)))
					  (m (number->string (+ 1 (length params))))) ;plus 1 magic
						(string-append 
							"/* applic */" nl
							"	PUSH(SOB_NIL);" nl
							(apply string-append (map (lambda (x) (string-append x "\tPUSH(R0);" nl)) code-params))
							"	PUSH(IMM(" m "));" nl
							code-proc
							"	CMP(INDD(R0,0), T_CLOSURE);" nl
							;"JUMP_NE(appplic_error);"
							"	PUSH(INDD(R0,1));" nl
							"	CALLA(INDD(R0,2));" nl
							"	DROP(IMM(2)+STARG(0));" nl
							"/* applic end */" nl))))))

;;;;;;;;;;;;;;;;;;;;;;code-gen lambda-simple;;;;;;;;;;;;;;;;;;;;;;
(define code-gen-lambda-simple 
	(lambda (e env-size) 
		(with e
			(lambda (lambda-simple params body)
				(let ((code-body (code-gen body (+ 1 env-size)))
					(label-exit (^label-closexit))
					(label-clos (^label-clos))
					(label-first-env-loop (^label-first-env-loop))
					(label-first-env-loop-end (^label-first-env-loop-end))
					(label-second-env-loop (^label-second-env-loop))
					(label-second-env-loop-end (^label-second-env-loop-end)))
				 (string-append
				 	"/* lambda-simple */" nl
				 	"	PUSH(IMM(" (number->string (+ 1 env-size)) "));" nl
				 	"	CALL(MALLOC);" nl
				 	"	DROP(1);" nl
				 	"	MOV(R1, R0);" nl
	       			"	MOV(R2,FPARG(0)); // env" nl

					"	MOV(R4,IMM(0));" nl
					"	MOV(R5,IMM(1));" nl
					label-first-env-loop ":" nl
					"	CMP(R4,IMM(" (number->string env-size) "));" nl
					"	JUMP_EQ(" label-first-env-loop-end ");" nl
					"	MOV(INDD(R1,R5),INDD(R2,R4));" nl
					"	ADD(R4,IMM(1));" nl
					"	ADD(R5,IMM(1));" nl
					"	JUMP(" label-first-env-loop ");" nl
					label-first-env-loop-end ":" nl

	       			"	// create new environment" nl
	       			"	PUSH(FPARG(1));" nl
	       			"	CALL(MALLOC);" nl
	       			"	DROP(1);" nl
	       			"	MOV(R3, R0);" nl

	       			"	MOV(R4,IMM(0));" nl
	       			label-second-env-loop ":" nl
	       			"	CMP(R4,FPARG(1));" nl
	       			"	JUMP_EQ(" label-second-env-loop-end ");" nl
	       			"	MOV(R5,R4);" nl
	       			"	ADD(R5,IMM(2));" nl
	       			"	MOV(INDD(R3,R4),FPARG(R5));" nl
	       			"	ADD(R4,IMM(1));" nl
	       			"	JUMP(" label-second-env-loop ");" nl
	       			label-second-env-loop-end ":" nl

	       			"	MOV(INDD(R1,0),R3); // Now R1 holds the environment" nl
	       			"	PUSH(IMM(3));" nl
	       			"	CALL(MALLOC);" nl
	       			"	DROP(1);" nl
	       			"	// create T_CLOSURE" nl
	       			"	MOV(INDD(R0,0), T_CLOSURE);" nl
	       			"	MOV(INDD(R0,1), R1);" nl
	       			"	MOV(INDD(R0,2), (long)&&" label-clos ");" nl
	       			"	JUMP(" label-exit ");" nl
	       			label-clos ":" nl
	       			"	PUSH(FP);" nl
	       			"	MOV(FP,SP);" nl
	       			"	" code-body nl
	       			"	POP(FP);" nl
	       			"	RETURN;" nl
	       			label-exit ":" nl
	       			"/* lambda-simple end */" nl)
				)))))

;;;;;;;;;;;;;;;;;;;;;;code-gen lambda-opt;;;;;;;;;;;;;;;;;;;;;;
(define ^label-clos-loop (^^label "Lclos_loop"))
(define ^label-clos-loop-end (^^label "Lclos_loop_end"))
(define ^label-second-env-loop (^^label "Lsecond_env_loop"))
(define ^label-second-env-loop-end (^^label "Lsecond_env_loop_end"))
(define ^label-first-env-loop (^^label "Lfirst_env_loop"))
(define ^label-first-env-loop-end (^^label "Lfirst_env_loop_end"))

(define code-gen-lambda-opt
	(lambda (e env-size) 
		(with e
			(lambda (lambda-opt params rest body)
				(let ((code-body (code-gen body (+ 1 env-size)))
					(label-exit (^label-closexit))
					(label-clos (^label-clos))
					(label-loop (^label-clos-loop))
					(label-end-loop (^label-clos-loop-end))
					(label-first-env-loop (^label-first-env-loop))
					(label-first-env-loop-end (^label-first-env-loop-end))
					(label-second-env-loop (^label-second-env-loop))
					(label-second-env-loop-end (^label-second-env-loop-end))
					(n (length params)))
				 (string-append
				 	"/* lambda opt */" nl
				 	"	PUSH(IMM(" (number->string (+ 1 env-size)) "));" nl
				 	"	CALL(MALLOC);" nl
				 	"	DROP(1);" nl
				 	"	MOV(R1, R0);" nl
	       			"	MOV(R2,FPARG(0)); // env" nl
					"	MOV(R4,IMM(0));" nl
					"	MOV(R5,IMM(1));" nl
					label-first-env-loop ":" nl
					"	CMP(R4,IMM(" (number->string env-size) "));" nl
					"	JUMP_EQ(" label-first-env-loop-end ");" nl
					"	MOV(INDD(R1,R5),INDD(R2,R4));" nl
					"	ADD(R4,IMM(1));" nl
					"	ADD(R5,IMM(1));" nl
					"	JUMP(" label-first-env-loop ");" nl
					label-first-env-loop-end ":" nl
	       			"	PUSH(FPARG(1));" nl
	       			"	CALL(MALLOC);" nl
	       			"	DROP(1);" nl
	       			"	MOV(R3, R0);" nl
	       			"	MOV(R4,IMM(0));" nl
	       			label-second-env-loop ":" nl
	       			"	CMP(R4,FPARG(1));" nl
	       			"	JUMP_EQ(" label-second-env-loop-end ");" nl
	       			"	MOV(R5,R4);" nl
	       			"	ADD(R5,IMM(2));" nl
	       			"	MOV(INDD(R3,R4),FPARG(R5));" nl
	       			"	ADD(R4,IMM(1));" nl
	       			"	JUMP(" label-second-env-loop ");" nl
	       			label-second-env-loop-end ":" nl
	       			"	MOV(INDD(R1,0),R3); // Now R1 holds the environment" nl	       			
	       			"	PUSH(IMM(3));" nl
	       			"	CALL(MALLOC);" nl
	       			"	DROP(1);" nl
	       			"	MOV(INDD(R0,0), T_CLOSURE);" nl
	       			"	MOV(INDD(R0,1), R1);" nl
	       			"	MOV(INDD(R0,2), (long)&&" label-clos ");" nl
	       			"	JUMP(" label-exit ");" nl
					label-clos ":" nl
	       			"	PUSH(FP);" nl
	       			"	MOV(FP,SP);" nl
					"	MOV(R2,FPARG(1)-" (number->string n) "); // R2 holds number of optional args + 1" nl
					"	MOV(R3,FPARG(1));" nl
					"	ADD(R3,IMM(1)); // FPARG(R3) = SOB_NIL" nl
					"	// loop that stores rest in list" nl
					"	MOV(R1,FPARG(R3));" nl
					"	SUB(R3,IMM(1));" nl
					"	SUB(R2,IMM(1)); // R2 - loop variable" nl
					label-loop ":" nl
					"	CMP(R2,IMM(0));" nl
					"	JUMP_EQ(" label-end-loop ");" nl
					"	PUSH(R1);" nl
					"	PUSH(FPARG(R3));" nl
					"	CALL(MAKE_SOB_PAIR);" nl
					"	DROP(2);" nl
					"	MOV(R1,R0);" nl
					"	SUB(R2,IMM(1));" nl
					"	SUB(R3,IMM(1));" nl
					"	JUMP(" label-loop ");" nl
					label-end-loop ":" nl
					"	MOV(FPARG(2+" (number->string n) "),R1);" nl
	       			code-body nl
	       			"	POP(FP);" nl
	       			"	RETURN;" nl
	       			label-exit ":" nl
	       			"/* lambda opt end */" nl))))))

;;;;;;;;;;;;;;;;;;;;;;code-gen lambda-variadic;;;;;;;;;;;;;;;;;;;;;;
(define code-gen-lambda-variadic 
	(lambda (e env-size) 
		(with e
			(lambda (lambda-variadic params body)
				(let ((code-body (code-gen body (+ 1 env-size)))
					(label-exit (^label-closexit))
					(label-clos (^label-clos))
					(label-loop (^label-clos-loop))
					(label-end-loop (^label-clos-loop-end))
					(label-first-env-loop (^label-first-env-loop))
					(label-first-env-loop-end (^label-first-env-loop-end))
					(label-second-env-loop (^label-second-env-loop))
					(label-second-env-loop-end (^label-second-env-loop-end)))
				 (string-append
				 	"/* lambda variadic */" nl
				 	"	PUSH(IMM(" (number->string (+ 1 env-size)) "));" nl
				 	"	CALL(MALLOC);" nl
				 	"	DROP(1);" nl
				 	"	MOV(R1, R0);" nl
	       			"	MOV(R2,FPARG(0)); // env" nl
					"	MOV(R4,IMM(0));" nl
					"	MOV(R5,IMM(1));" nl
					label-first-env-loop ":" nl
					"	CMP(R4,IMM(" (number->string env-size) "));" nl
					"	JUMP_EQ(" label-first-env-loop-end ");" nl
					"	MOV(INDD(R1,R5),INDD(R2,R4));" nl
					"	ADD(R4,IMM(1));" nl
					"	ADD(R5,IMM(1));" nl
					"	JUMP(" label-first-env-loop ");" nl
					label-first-env-loop-end ":" nl
	       			"	PUSH(FPARG(1));" nl
	       			"	CALL(MALLOC);" nl
	       			"	DROP(1);" nl
	       			"	MOV(R3, R0);" nl
	       			"	MOV(R4,IMM(0));" nl
	       			label-second-env-loop ":" nl
	       			"	CMP(R4,FPARG(1));" nl
	       			"	JUMP_EQ(" label-second-env-loop-end ");" nl
	       			"	MOV(R5,R4);" nl
	       			"	ADD(R5,IMM(2));" nl
	       			"	MOV(INDD(R3,R4),FPARG(R5));" nl
	       			"	ADD(R4,IMM(1));" nl
	       			"	JUMP(" label-second-env-loop ");" nl
	       			label-second-env-loop-end ":" nl
	       			"	MOV(INDD(R1,0),R3); // Now R1 holds the environment" nl	       			
	       			"	PUSH(IMM(3));" nl
	       			"	CALL(MALLOC);" nl
	       			"	DROP(1);" nl
	       			"	MOV(INDD(R0,0), T_CLOSURE);" nl
	       			"	MOV(INDD(R0,1), R1);" nl
	       			"	MOV(INDD(R0,2), (long)&&" label-clos ");" nl
	       			"	JUMP(" label-exit ");" nl
					label-clos ":" nl
	       			"	PUSH(FP);" nl
	       			"	MOV(FP,SP);" nl
					"	MOV(R2,FPARG(1)); // R2 holds number of optional args + 1" nl
					"	MOV(R3,FPARG(1));" nl
					"	ADD(R3,IMM(1)); // FPARG(R3) = SOB_NIL" nl
					"	// loop that stores params in list" nl
					"	MOV(R1,FPARG(R3));" nl
					"	SUB(R3,IMM(1));" nl
					"	SUB(R2,IMM(1)); // R2 - loop variable" nl
					label-loop ":" nl
					"	CMP(R2,IMM(0));" nl
					"	JUMP_EQ(" label-end-loop ");" nl
					"	PUSH(R1);" nl
					"	PUSH(FPARG(R3));" nl
					"	CALL(MAKE_SOB_PAIR);" nl
					"	DROP(2);" nl
					"	MOV(R1,R0);" nl
					"	SUB(R2,IMM(1));" nl
					"	SUB(R3,IMM(1));" nl
					"	JUMP(" label-loop ");" nl
					label-end-loop ":" nl
					"	MOV(FPARG(2),R1);" nl
	       			code-body nl
	       			"	POP(FP);" nl
	       			"	RETURN;" nl
	       			label-exit ":" nl
	       			"/* lambda variadic end */" nl))))))

;;;;;;;;;;;;;;;;;;;;;;code-gen tc-applic;;;;;;;;;;;;;;;;;;;;;;
(define ^label-tc-applic (^^label "Ltc_applic"))
(define ^label-tc-loop (^^label "Ltc_loop"))
(define ^label-tc-exit (^^label "Ltc_exit"))

(define code-gen-tc-applic 	
	(lambda (e env-size)
		(with e
			(lambda (tc-applic proc params)
				(let ((code-proc (code-gen proc env-size))
					  (code-params (reverse (map (lambda (e) (code-gen e env-size)) params)))
					  (m (number->string (+ 1 (length params)))) ;plus 1 magic
					  (label-tc-applic (^label-tc-applic))
					  (label-tc-loop (^label-tc-loop))
					  (label-tc-exit (^label-tc-exit)))
						(string-append 
							"/* tc-applic */" nl
							"	PUSH(SOB_NIL);" nl
							(apply string-append (map (lambda (x) (string-append x "\tPUSH(R0);" nl)) code-params))
							"	PUSH(IMM(" m "));" nl
							code-proc
							"	// check if proc type is closure" nl
							"	CMP(INDD(R0,0), T_CLOSURE);" nl
							;"JUMP_NE(appplic_error);"
							"	PUSH(INDD(R0,1)); //push env" nl
							"	PUSH(FPARG(-1)); // push ret" nl
							"	MOV(R7,FPARG(-2));" nl
							"	MOV(R1,FPARG(1));" nl
							"	MOV(R4,R1);" nl
							"	ADD(R4,IMM(4));" nl
							"	ADD(R1,IMM(1)); //FPARG(R1) - BOTTOM OF OLD FRAME" nl
							"	MOV(R2,IMM(" m ")); //R2 HOLDS NUM OF PARAMS OF NEW FRAME" nl
							"	ADD(R2,IMM(4)); //R2 HOLDS NUM OF ITEMS TO COPY" nl
							"	MOV(R3,FP);" nl
							"	// loop to override stack" nl
							label-tc-loop ":" nl
  							"	CMP(R2,IMM(0));" nl
  							"	JUMP_EQ("label-tc-exit");" nl
  							"	MOV(FPARG(R1),STACK(R3));" nl
  							"	SUB(R1,IMM(1));" nl
  							"	ADD(R3,IMM(1));" nl
  							"	SUB(R2,IMM(1));" nl
  							"	JUMP("label-tc-loop");" nl

							label-tc-exit ":" nl
  							"	DROP(R4);" nl
  							"	MOV(FP,R7);" nl
							"	JUMPA(INDD(R0,2));" nl
							"/* tc-applic end */"))))))

;;;;;;;;;;;;;;;;;;;;;;code-gen define;;;;;;;;;;;;;;;;;;;;;;
(define code-gen-define 
	(lambda (e env-size) 
		(with e
			(lambda (define var val)
				(let ((fvar (cadr var))
					  (val-code (code-gen val env-size)))
					(string-append
					val-code
					"MOV(IND(" (number->string (lookup-fvar fvar fvars-table)) "),R0);" nl
					"MOV(R0,SOB_VOID);" nl))))))

;;;;;;;;;;;;;;;;;;;;;;code-gen seq;;;;;;;;;;;;;;;;;;;;;;
(define code-gen-seq 	
	(lambda (e env-size)
    (with e
	  (lambda (seq exprs)
	    (let ((code-exprs (map (lambda (expr) (code-gen expr env-size)) exprs)))
	      (string-append
	       	"/* seq */" nl 
	       (apply string-append code-exprs)
	       	"/* seq end */" nl))))))

;;;;;;;;;;;;;;;;;;;;;;code-gen pvar;;;;;;;;;;;;;;;;;;;;;;
(define code-gen-pvar
	(lambda (e env-size)
		(with e
			(lambda (pvar x j)
				(string-append 
					"/* pvar */" nl 
					"	MOV(R0,FPARG(2+" (number->string j) "));" nl 
					"/* pvar end */")))))

;;;;;;;;;;;;;;;;;;;;;;code-gen bvar;;;;;;;;;;;;;;;;;;;;;;
(define code-gen-bvar
	(lambda (e env-size)
		(with e
			(lambda (bvar x i j)
				(string-append 
					"/* bvar */" nl
					"	MOV(R0,FPARG(0));" nl
					"	MOV(R0,INDD(R0," (number->string i) "));" nl
					"	MOV(R0,INDD(R0," (number->string j) "));" nl
					"/* bvar end */" nl)))))

;;;;;;;;;;;;;;;;;;;;;;code-gen fvar;;;;;;;;;;;;;;;;;;;;;;
(define code-gen-fvar 
	(lambda (e) 
		(with e
			(lambda (fvar x)
				(string-append
					"/* fvar */" nl
					"	MOV(R0,IND(" (number->string (lookup-fvar x fvars-table)) "));" nl
					"/* fvar end */" nl)))))

;params-size env-size
(define code-gen 
  (lambda (pe env-size)
    (cond 
     ((pe-const? pe) (code-gen-const (cadr pe)))
     ((pe-pvar? pe) (code-gen-pvar pe env-size))
     ((pe-bvar? pe) (code-gen-bvar pe env-size))
     ((pe-fvar? pe) (code-gen-fvar pe))
     ((pe-or? pe) (code-gen-or pe env-size))
     ((pe-applic? pe) (code-gen-applic pe env-size))
     ((pe-tc-applic? pe) (code-gen-tc-applic pe env-size))
     ((pe-if3? pe) (code-gen-if3 pe env-size))
     ((pe-define? pe) (code-gen-define pe env-size))
     ((pe-lambda-simple? pe) (code-gen-lambda-simple pe env-size))
     ((pe-lambda-opt? pe) (code-gen-lambda-opt pe env-size))
     ((pe-lambda-variadic? pe) (code-gen-lambda-variadic pe env-size))
     ((pe-seq? pe) (code-gen-seq pe env-size))
     (else (error 'code-gen "Error in code gen!")))))


(define ^label-clos (^^label "Lclos"))

(define ^label-closexit (^^label "Lclosexit"))

(define ^label-orexit (^^label "Lorexit"))

(define ^label-if3else (^^label "Lif3else"))

(define ^label-if3exit (^^label "Lif3exit"))

(define nl (list->string (list #\newline)))

(define code-gen-if3
  (lambda (e env-size)
    (with e
	  (lambda (if3 test do-if-true do-if-false)
	    (let ((code-test (code-gen test env-size))
		  (code-dit (code-gen do-if-true env-size))
		  (code-dif (code-gen do-if-false env-size))
		  (label-else (^label-if3else))
		  (label-exit (^label-if3exit)))
	      (string-append
	       "/* if */" nl
	       code-test nl ; when run, the result of the test will be in R0
	       "\tCMP(R0, SOB_BOOLEAN_FALSE);" nl
	       "\tJUMP_EQ(" label-else ");" nl
	       code-dit nl
	       "\tJUMP(" label-exit ");" nl
	       label-else ":" nl
	       code-dif nl
	       label-exit ":" nl
	       "/* if end */" nl))))))

(define prolog
	(lambda (consts)
		(string-append 
		"#include <stdio.h>" nl 
		"#include <stdlib.h>" nl
		"#define DO_SHOW 0" nl
		"#include \"cisc.h\"" nl
		"#include \"debug_macros.h\"" nl
		"int main()" nl
		"{" nl
		"\tint i, j;" nl
		"\tSTART_MACHINE;" nl
		consts nl
		"JUMP(CONTINUE);" nl
		"#include \"char.lib\"" nl
		"#include \"io.lib\"" nl
		"#include \"math.lib\"" nl
		"#include \"string.lib\"" nl
		"#include \"system.lib\"" nl
		"#include \"scheme.lib\"" nl nl
		"CONTINUE:" nl
		"#define SOB_VOID 500" nl
		"#define SOB_NIL 501" nl
		"#define SOB_BOOLEAN_FALSE 502" nl
		"#define SOB_BOOLEAN_TRUE 504" nl
		"#define SCMENV (FPARG(0))" nl
		"#define SCMNARGS (FPARGS(1))" nl
		"\tMOV(IND(100),SOB_NIL);" nl
		"\tADD(IND(0),IMM(" (number->string next-available-addr) "));" nl
		"\tPUSH(IMM(" (number->string (length fvars-table)) "));" nl
		"\tCALL(MALLOC);" nl
		"\tDROP(1);" nl nl
		(symbol-table) nl
		(prim-cons) nl nl
		(prim-car) nl nl
		(prim-cdr) nl nl
		(prim-is-boolean) nl nl
		(prim-is-integer) nl nl
		(prim-is-char) nl nl
		(prim-is-nil) nl nl
		(prim-is-number) nl nl
		(prim-is-pair) nl nl
		(prim-is-procedure) nl nl
		(prim-is-string) nl nl
		(prim-is-symbol) nl nl
		(prim-is-vector) nl nl
		(prim-str-length) nl nl
		(prim-vec-length) nl nl
		(prim-is-zero) nl nl
		(prim-str-ref) nl nl
		(prim-make-str) nl nl
		(prim-str-set) nl nl
		(prim-vec-ref) nl nl
		(prim-make-vec) nl nl
		(prim-vec-set) nl nl
		(prim-set-car) nl nl
		(prim-set-cdr) nl nl
		(prim-char-to-integer) nl nl
		(prim-integer-to-char) nl nl
		(prim-remainder) nl nl 
		(prim-plus) nl nl
		(prim-minus) nl nl
		(prim-mul) nl nl
		(prim-div) nl nl
		(prim-smaller) nl nl
		(prim-greater) nl nl
		(prim-equal) nl nl
		(prim-apply) nl nl
		(prim-string-symbol) nl nl
		(prim-symbol-string) nl nl
		(prim-eq) nl nl)))

(define ^label-printsexpr (^^label "Lprintsexpr"))

(define print-sexpr
	(lambda ()
		(let ((end (^label-printsexpr)))
		(string-append
			"\tCMP(R0,SOB_VOID);" nl
			"\tJUMP_EQ(" end ");" nl
			"\tPUSH(R0);" nl
			"\tCALL(WRITE_SOB);" nl
			"\tDROP(1);" nl
			"\tCALL(NEWLINE);" nl
			end ":" nl))))

(define epilog
	(lambda ()
		"	STOP_MACHINE; 
	return 0;
}"))

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


(define list->set 
	(lambda (in-lst out-lst)
		(cond ((null? in-lst) out-lst)
			  ((member (car in-lst) out-lst) (list->set (cdr in-lst) out-lst))
			  (else (list->set (cdr in-lst) (append out-lst (list (car in-lst))))))))

;;;;;;;;;;;;;;;;;;;;;;Constants handeling;;;;;;;;;;;;;;;;;;;;;;
(define topological-sort
  (lambda (e)
    (cond 
      ((or (number? e) (char? e) (string? e)) `(,e))
	  ((symbol? e) `(,@(topological-sort (symbol->string e)) ,e))
	  ((pair? e) `(,@(topological-sort (car e)) ,@(topological-sort (cdr e)) ,e))
	  ((vector? e) `(,@(apply append (map topological-sort (vector->list e))) ,e))
	  ((or (null? e) (is-void? e) (boolean? e)) '())
	  (else (display "error in topological-sort")))))

(define consts-list
	(lambda (sexprs)
		(apply append (map (lambda (e) (run1 (annotate-tc (pe->lex-pe (parse e))) '())) sexprs))))
		
(define run1
	(lambda (pe consts)
		(cond ((pe-const? pe) (cdr pe))
			  ((pe-if3? pe) (append (run1 (cadr pe) consts) (run1 (caddr pe) consts) (run1 (cadddr pe) consts)))
			  ((or (pe-bvar? pe) (pe-pvar? pe) (pe-fvar? pe)) '())
			  ((or (pe-or? pe) (pe-seq? pe)) (apply append (map (lambda (x) (run1 x consts)) (cadr pe))))
			  ((pe-define? pe) (run1 (caddr pe) consts)) 
			  ((or (pe-applic? pe) (pe-tc-applic? pe)) (apply append (run1 (cadr pe) consts) (map (lambda (x) (run1 x consts)) (caddr pe))))
			  ((pe-lambda-simple? pe) (run1 (caddr pe) consts))
			  ((pe-lambda-opt? pe) (run1 (cadddr pe) consts))
			  ((pe-lambda-variadic? pe) (run1 (caddr pe) consts))
			  (else '()))))

(define constants-table
	(lambda (sexprs)
		(let ((consts-set (list->set (apply append (map topological-sort (consts-list sexprs))) '()))
			 (const-void `(500 ,*void-object* ,(list 937610)))
			 (const-nil `(501 ,(list) ,(list 722689)))
			 (const-bool-false `(502 #f ,(list 741553 0)))
			 (const-bool-true `(504 #t ,(list 741553 1))))
			(update-table consts-set `(,const-void ,const-nil ,const-bool-false ,const-bool-true) 506))))

(define lookup-const
	(lambda (const table)
		(cond ((null? table) 'error)
			  ((equal? (cadar table) const) (caar table))
			  (else (lookup-const const (cdr table))) 
			)))

(define update-table
	(lambda (consts table addr)
		(cond 
		((null? consts) table)
		((number? (car consts)) 
			(update-table 
				(cdr consts) 
				(append table (list (list addr (car consts) 
					(list 945311 (car consts))))) 
				(+ addr 2)))
		((char? (car consts)) 
			(update-table 
				(cdr consts) 
				(append table (list (list addr (car consts) 
					(list 181048 (char->integer (car consts))))))
				(+ addr 2)))
		((string? (car consts)) 
			(update-table 
				(cdr consts) 
				(append table (list (list addr (car consts) (append 
					(list 799345 (length (string->list (car consts)))) (map char->integer (string->list (car consts))))))) 
				(+ addr 2 (length (string->list (car consts))))))
  		((symbol? (car consts)) 
  			(update-table 
  				(cdr consts) 
  				(append table (list (list addr (car consts) 
  					(list 368031 (lookup-const (symbol->string (car consts)) table))))) 
  				(+ addr 2)))
  		((pair? (car consts)) 
  			(update-table 
  				(cdr consts) 
  				(append table (list (list addr (car consts) 
  					(list 885397 (lookup-const (caar consts) table) (lookup-const (cdar consts) table)))))
  			 	(+ addr 3)))
  		((vector? (car consts)) 
  			(update-table 
  				(cdr consts) 
  				(append table (list (list addr (car consts) 
  					`(335728 ,(length (vector->list (car consts))) ,@(map (lambda (e) (lookup-const e table)) (vector->list (car consts))))))) 
  				(+ 2 addr (length (vector->list (car consts))))))
  		((or (null? (car consts)) (is-void? (car consts)) (boolean? (car consts)))
  			(update-table (cdr consts) table addr))
  		(else (display "error in topological-sort")))))

(define mk-c-constants-stmt
	(lambda (constants-table)
		(let ((consts-table-size (number->string (length (apply append (map caddr constants-table))))))
		(string-append "\tlong CONSTANTS[" consts-table-size "] = {"
			(apply string-append
				(cdr (apply append (map (lambda (c) `(", " ,(number->string c)))
					 (apply append (map caddr constants-table))))))
				"\t};" nl
				"\tmemcpy(&IND(500), CONSTANTS, " consts-table-size " * WORD_SIZE);" nl))))

;;;;;;;;;;;;;;;;;;;;;;fvars handeling;;;;;;;;;;;;;;;;;;;;;;

(define init-fvars-table
	(lambda (addr)
		(list 
			(list 'cons addr)
			(list 'car (+ 1 addr))
			(list 'cdr (+ 2 addr))
			(list 'boolean? (+ 3 addr))
			(list 'integer? (+ 4 addr))
			(list 'char? (+ 5 addr))
			(list 'null? (+ 6 addr))
			(list 'number? (+ 7 addr))
			(list 'pair? (+ 8 addr))
			(list 'procedure? (+ 9 addr))
			(list 'string? (+ 10 addr))
			(list 'symbol? (+ 11 addr))
			(list 'vector? (+ 12 addr))
			(list 'string-length (+ 13 addr))
			(list 'vector-length (+ 14 addr))
			(list 'zero? (+ 15 addr))
			(list 'string-ref (+ 16 addr))
			(list 'make-string (+ 17 addr))
			(list 'string-set! (+ 18 addr))
			(list 'vector-ref (+ 19 addr))
			(list 'make-vector (+ 20 addr))
			(list 'vector-set! (+ 21 addr))
			(list 'set-car! (+ 22 addr))
			(list 'set-cdr! (+ 23 addr))
			(list 'char->integer (+ 24 addr))
			(list 'integer->char (+ 25 addr))
			(list 'remainder (+ 26 addr))
			(list '+ (+ 27 addr))
			(list '- (+ 28 addr))
			(list '* (+ 29 addr))
			(list '/ (+ 30 addr))
			(list '< (+ 31 addr))
			(list '> (+ 32 addr))
			(list '= (+ 33 addr))
			(list 'apply (+ 34 addr))
			(list 'string->symbol (+ 35 addr))
			(list 'symbol->string (+ 36 addr))
			(list 'eq? (+ 37 addr)))))

(define lookup-fvar
	(lambda (fvar table)
		(cond ((null? table) 'error)
			  ((equal? (caar table) fvar) (cadar table))
			  (else (lookup-fvar fvar (cdr table))) 
			)))

(define mk-fvars-table
	(lambda (fvars table addr)
		(if
			(null? fvars) 
			table
			(mk-fvars-table 
				(cdr fvars)
				(append table (list (list (car fvars) addr)))
				(+ 1 addr)))))

(define fvars-list
	(lambda (sexprs)
		(apply append (map (lambda (e) (run2 (annotate-tc (pe->lex-pe (parse e))))) sexprs))))
		
(define is-prim?
	(lambda (pe)
		(or (equal? (cadr pe) 'cons) (equal? (cadr pe) 'car))))

(define run2
	(lambda (pe)
		(cond ((pe-fvar? pe) (if (not (is-prim? pe)) (cdr pe) (list)))
			  ((pe-if3? pe) (append (run2 (cadr pe)) (run2 (caddr pe)) (run2 (cadddr pe))))
			  ((or (pe-bvar? pe) (pe-pvar? pe) (pe-const? pe)) '())
			  ((or (pe-or? pe) (pe-seq? pe)) (apply append (map (lambda (x) (run2 x)) (cadr pe))))
			  ((pe-define? pe) (run2 (cadr pe))) 
			  ((or (pe-applic? pe) (pe-tc-applic? pe)) (apply append (run2 (cadr pe)) (map (lambda (x) (run2 x)) (caddr pe))))
			  ((pe-lambda-simple? pe) (run2 (caddr pe)))
			  ((pe-lambda-opt? pe) (run2 (cadddr pe)))
			  ((pe-lambda-variadic? pe) (run2 (caddr pe)))
			  (else '()))))
;;;;;;;;;;;;;;;;;;;;;;;Symbols;;;;;;;;;;;;;;;;;;;;;;
(define symbol-table
	(lambda ()
		(apply string-append 
			(map (lambda (e) (if (equal? (caaddr e) '368031) 
			(string-append 
			"\tPUSH(IND(100));" nl
			"\tPUSH(" (number->string (car e)) ");" nl
			"\tCALL(MAKE_SOB_PAIR);" nl
			"\tMOV(IND(100),R0);" nl) "")) 
			consts-table))))


;;;;;;;;;;;;;;;;;;;;;;;Libs;;;;;;;;;;;;;;;;;;;;;;;;;

(define prim-string-symbol
	(lambda ()
		(let ((addr (lookup-fvar 'string->symbol fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_string_to_symbol);" nl
			"Lprim_string_to_symbol:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
"	MOV(R0,IND(100)); // R0 holds symbol table
	MOV(R1,FPARG(2)); // R1 holds the string
	MOV(R2,INDD(R1,1)); // R2 holds string length;
Lsymbol_table_loop:
	CMP(R0,SOB_NIL);
	JUMP_EQ(Lsymbol_not_found);
	MOV(R3,INDD(R0,1)); 
	MOV(R3,INDD(R3,1));
	MOV(R3,INDD(R3,1)); // R3 holds curr symbol string length
	CMP(R2,R3);
	JUMP_EQ(Lstr_sym_compare);
	JUMP(Lstr_sym_not_succ);
Lstr_sym_compare:
	MOV(R5,INDD(R0,1));
	MOV(R5,INDD(R5,1)); // R5 holds curr symbol string
	MOV(R4,IMM(0)); // R4 loop (i)
Lstr_sym_compare_loop:
	CMP(R2,R4);
	JUMP_EQ(Lend_compare_loop_succ);
	MOV(R6,IMM(2));
	ADD(R6,R4);
	CMP(INDD(R1,R6), INDD(R5,R6));
	JUMP_NE(Lstr_sym_not_succ);
	ADD(R4,1);
	JUMP(Lstr_sym_compare_loop)
Lstr_sym_not_succ:
	CMP(INDD(R0,2), SOB_NIL);
	JUMP_EQ(Lsymbol_not_found);
	MOV(R0,INDD(R0,2));
	JUMP(Lsymbol_table_loop);
Lsymbol_not_found:
	ADD(R2,IMM(1));
	MOV(R10,IMM(2));
Lpush_string_chars:
	CMP(R10,R2);
	JUMP_GT(Lend_push_string_chars);
	PUSH(INDD(R1,R10));
	ADD(R10,IMM(1));
	JUMP(Lpush_string_chars);
Lend_push_string_chars:
	PUSH(INDD(R1,1)); // push string length

	CALL(MAKE_SOB_STRING)

	MOV(R8,IMM(1));
	ADD(R8,INDD(R1,1));
	DROP(R8);
	MOV(R8,R0);
	PUSH(2);
	CALL(MALLOC);
	DROP(1);
	MOV(IND(R0),T_SYMBOL);
	MOV(INDD(R0,1),R8);

	MOV(R9,R0);
	PUSH(IND(100));
	PUSH(R0);
	CALL(MAKE_SOB_PAIR);
	DROP(2);
	MOV(IND(100),R0);
	MOV(R0,R9);

	JUMP(Lend_string_to_symbol);
Lend_compare_loop_succ:
	MOV(R0,INDD(R0,1));
Lend_string_to_symbol:" nl

			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_string_to_symbol:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_string_to_symbol));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-symbol-string
	(lambda ()
		(let ((addr (lookup-fvar 'symbol->string fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_symbol_string);" nl
			"Lprim_symbol_string:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_symbol_string:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_symbol_string));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-eq
	(lambda ()
		(let ((addr (lookup-fvar 'eq? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_eq);" nl
			"Lprim_eq:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R1,FPARG(3));" nl
			"	CMP(INDD(R0,0),INDD(R1,0));" nl
			"	JUMP_NE(Lnot_eq);" nl
			"	CMP(INDD(R0,0),T_CHAR);" nl
			"	JUMP_EQ(Lcompare_val);" nl
			"	CMP(INDD(R0,0),T_SYMBOL);" nl
			"	JUMP_EQ(Lcompare_val);" nl
			"	CMP(INDD(R0,0),T_INTEGER);" nl
			"	JUMP_EQ(Lcompare_val);" nl
			"	CMP(INDD(R0,0),T_STRING);" nl
			"	JUMP_EQ(Lcompare_addr);" nl
			"	CMP(INDD(R0,0),T_VECTOR);" nl
			"	JUMP_EQ(Lcompare_addr);" nl
			"	CMP(INDD(R0,0),T_PAIR);" nl
			"	JUMP_EQ(Lcompare_addr);" nl
			"	CMP(INDD(R0,0),T_CLOSURE);" nl
			"	JUMP_EQ(Lcompare_addr);" nl
			"	CMP(INDD(R0,0),T_BOOL);" nl
			"	JUMP_EQ(Lcompare_addr);" nl
			"	CMP(INDD(R0,0),T_VOID);" nl
			"	JUMP_EQ(Lis_eq);" nl
			"	CMP(INDD(R0,0),T_NIL);" nl
			"	JUMP_EQ(Lis_eq);" nl
			"	JUMP(Lnot_eq);" nl
			"Lcompare_addr:" nl
			"	CMP(R0,R1);" nl
			"	JUMP_EQ(Lis_eq);" nl
			"	JUMP(Lnot_eq);" nl
			"Lcompare_val:" nl
			"	CMP(INDD(R0,1),INDD(R1,1));" nl
			"	JUMP_EQ(Lis_eq);" nl
			"Lnot_eq:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"	JUMP(Lend_prim_eq);" nl
			"Lis_eq:" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"Lend_prim_eq:" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_eq:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_eq));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-cons
	(lambda ()
		(let ((addr (lookup-fvar 'cons fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_cons);" nl
			"Lprim_cons:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	PUSH(FPARG(3));" nl
			"	PUSH(FPARG(2));" nl
			"	CALL(MAKE_SOB_PAIR);" nl
			"	DROP(2);" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_cons:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_cons));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-car
	(lambda ()
		(let ((addr (lookup-fvar 'car fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_car);" nl
			"Lprim_car:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,1))" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_car:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_car));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-cdr
	(lambda ()
		(let ((addr (lookup-fvar 'cdr fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_cdr);" nl
			"Lprim_cdr:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,2))" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_cdr:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_cdr));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-boolean
	(lambda ()
		(let ((addr (lookup-fvar 'boolean? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_boolean);" nl
			"Lprim_is_boolean:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,0))" nl
			"	CMP(R0,T_BOOL);" nl
			"	JUMP_NE(Lnot_boolean);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_is_boolean);" nl
			"Lnot_boolean:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_is_boolean:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_boolean:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_boolean));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-integer
	(lambda ()
		(let ((addr (lookup-fvar 'integer? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_integer);" nl
			"Lprim_is_integer:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,0))" nl
			"	CMP(R0,T_INTEGER);" nl
			"	JUMP_NE(Lnot_integer);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_is_integer);" nl
			"Lnot_integer:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_is_integer:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_integer:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_integer));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-char
	(lambda ()
		(let ((addr (lookup-fvar 'char? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_char);" nl
			"Lprim_is_char:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,0))" nl
			"	CMP(R0,T_CHAR);" nl
			"	JUMP_NE(Lnot_char);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_is_char);" nl
			"Lnot_char:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_is_char:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_char:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_char));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-nil
	(lambda ()
		(let ((addr (lookup-fvar 'null? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_nil);" nl
			"Lprim_is_nil:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,0))" nl
			"	CMP(R0,T_NIL);" nl
			"	JUMP_NE(Lnot_nil);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_is_nil);" nl
			"Lnot_nil:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_is_nil:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_nil:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_nil));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-number
	(lambda ()
		(let ((addr (lookup-fvar 'number? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_number);" nl
			"Lprim_is_number:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,0))" nl
			"	CMP(R0,T_INTEGER);" nl
			"	JUMP_NE(Lnot_number);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_is_number);" nl
			"Lnot_number:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_is_number:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_number:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_number));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-pair
	(lambda ()
		(let ((addr (lookup-fvar 'pair? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_pair);" nl
			"Lprim_is_pair:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,0))" nl
			"	CMP(R0,T_PAIR);" nl
			"	JUMP_NE(Lnot_pair);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_is_pair);" nl
			"Lnot_pair:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_is_pair:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_pair:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_pair));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-procedure
	(lambda ()
		(let ((addr (lookup-fvar 'procedure? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_procedure);" nl
			"Lprim_is_procedure:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,0))" nl
			"	CMP(R0,T_CLOSURE);" nl
			"	JUMP_NE(Lnot_procedure);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_is_procedure);" nl
			"Lnot_procedure:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_is_procedure:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_procedure:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_procedure));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-string
	(lambda ()
		(let ((addr (lookup-fvar 'string? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_string);" nl
			"Lprim_is_string:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,0))" nl
			"	CMP(R0,T_STRING);" nl
			"	JUMP_NE(Lnot_string);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_is_string);" nl
			"Lnot_string:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_is_string:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_string:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_string));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-symbol
	(lambda ()
		(let ((addr (lookup-fvar 'symbol? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_symbol);" nl
			"Lprim_is_symbol:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,0))" nl
			"	CMP(R0,T_SYMBOL);" nl
			"	JUMP_NE(Lnot_symbol);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_is_symbol);" nl
			"Lnot_symbol:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_is_symbol:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_symbol:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_symbol));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-vector
	(lambda ()
		(let ((addr (lookup-fvar 'vector? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_vector);" nl
			"Lprim_is_vector:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,0));" nl
			"	CMP(R0,T_VECTOR);" nl
			"	JUMP_NE(Lnot_vector);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_is_vector);" nl
			"Lnot_vector:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_is_vector:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_vector:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_vector));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-str-length
	(lambda ()
		(let ((addr (lookup-fvar 'string-length fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_string_length);" nl
			"Lprim_string_length:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,1))" nl
			"	PUSH(R0);" nl
			"	CALL(MAKE_SOB_INTEGER);" nl
			"	DROP(1);" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_string_length:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_string_length));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-vec-length
	(lambda ()
		(let ((addr (lookup-fvar 'vector-length fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_vector_length);" nl
			"Lprim_vector_length:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,1))" nl
			"	PUSH(R0);" nl
			"	CALL(MAKE_SOB_INTEGER);" nl
			"	DROP(1);" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_vector_length:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_vector_length));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-is-zero
	(lambda ()
		(let ((addr (lookup-fvar 'zero? fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_is_zero);" nl
			"Lprim_is_zero:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,1))" nl
			"	CMP(R0,IMM(0));" nl
			"	JUMP_NE(Lnot_zero);" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_is_zero);" nl
			"Lnot_zero:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_is_zero:" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_is_zero:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_is_zero));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-str-ref
	(lambda ()
		(let ((addr (lookup-fvar 'string-ref fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_string_ref);" nl
			"Lprim_string_ref:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R1,FPARG(3));" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	ADD(R1,IMM(2));" nl
			"	MOV(R0,INDD(R0,R1));" nl
			"	PUSH(R0);" nl
			"	CALL(MAKE_SOB_CHAR);" nl
			"	DROP(1);" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_string_ref:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_string_ref));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-make-str
	(lambda ()
		(let ((addr (lookup-fvar 'make-string fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_make_string);" nl
			"Lprim_make_string:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	CMP(FPARG(1),IMM(3));" nl
			"	JUMP_EQ(Lmake_string_two_params);" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R1,IMM(0));" nl
			"	MOV(R2,R0);" nl
			"	JUMP(Lmake_string_loop);" nl
			"Lmake_string_two_params:" nl
			"	MOV(R0,FPARG(2));" nl
			"	MOV(R1,FPARG(3));" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R2,R0);" nl
			"Lmake_string_loop:" nl
			"	CMP(R0,IMM(0));" nl
			"	JUMP_EQ(Lend_make_string);" nl
			"	PUSH(R1);" nl
			"	SUB(R0,IMM(1));" nl
			"	JUMP(Lmake_string_loop);" nl
			"Lend_make_string:" nl
			"	PUSH(R2);"	nl
			"	CALL(MAKE_SOB_STRING);" nl
			"	ADD(R2,IMM(1));" nl
			"	DROP(R2);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_make_string:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_make_string));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))


(define prim-str-set
	(lambda ()
		(let ((addr (lookup-fvar 'string-set! fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_str_set);" nl
			"Lprim_str_set:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2)); // string" nl
			"	MOV(R1,FPARG(3)); // n" nl
			"	MOV(R2,FPARG(4)); // char" nl
			"	MOV(R2,INDD(R2,1));" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	ADD(R1,IMM(2));" nl
			"	MOV(INDD(R0,R1),R2);" nl
			"	MOV(R0,SOB_VOID);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_str_set:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_str_set));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-vec-ref
	(lambda ()
		(let ((addr (lookup-fvar 'vector-ref fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_vector_ref);" nl
			"Lprim_vector_ref:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2)); // vector" nl
			"	MOV(R1,FPARG(3)); // n" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	ADD(R1,IMM(2));" nl
			"	MOV(R0,INDD(R0,R1));" nl
			"	POP(FP);" nl
			"	RETURN;" nl

			"Lcreate_prim_vector_ref:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_vector_ref));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-make-vec
	(lambda ()
		(let ((addr (lookup-fvar 'make-vector fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_make_vector);" nl
			"Lprim_make_vector:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	CMP(FPARG(1),IMM(3));" nl
			"	JUMP_EQ(Lmake_vector_two_params);" nl
			"	MOV(R0,FPARG(2)); // n" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R1,SOB_VOID);" nl
			"	MOV(R2,R0);" nl
			"	JUMP(Lmake_vector_loop);" nl
			"Lmake_vector_two_params:" nl
			"	MOV(R0,FPARG(2)); // n" nl
			"	MOV(R1,FPARG(3)); // obj" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R2,R0);" nl
			"Lmake_vector_loop:" nl
			"	CMP(R0,IMM(0));" nl
			"	JUMP_EQ(Lend_make_vector);" nl
			"	PUSH(R1);" nl
			"	SUB(R0,IMM(1));" nl
			"	JUMP(Lmake_vector_loop);" nl
			"Lend_make_vector:" nl
			"	PUSH(R2);"	nl
			"	CALL(MAKE_SOB_VECTOR);" nl
			"	ADD(R2,IMM(1));" nl
			"	DROP(R2);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_make_vector:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_make_vector));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-vec-set
	(lambda ()
		(let ((addr (lookup-fvar 'vector-set! fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_vector_set);" nl
			"Lprim_vector_set:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2)); // vector" nl
			"	MOV(R1,FPARG(3)); // n" nl
			"	MOV(R2,FPARG(4)); // obj" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	ADD(R1,IMM(2));" nl
			"	MOV(INDD(R0,R1),R2);" nl
			"	MOV(R0,SOB_VOID);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_vector_set:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_vector_set));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-set-car
	(lambda ()
		(let ((addr (lookup-fvar 'set-car! fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_set_car);" nl
			"Lprim_set_car:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2)); // pair" nl
			"	MOV(R1,FPARG(3)); // obj" nl
			"	MOV(INDD(R0,1),R1);" nl
			"	MOV(R0,SOB_VOID);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_set_car:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_set_car));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-set-cdr
	(lambda ()
		(let ((addr (lookup-fvar 'set-cdr! fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_set_cdr);" nl
			"Lprim_set_cdr:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2)); // pair" nl
			"	MOV(R1,FPARG(3)); // obj" nl
			"	MOV(INDD(R0,2),R1);" nl
			"	MOV(R0,SOB_VOID);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_set_cdr:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_set_cdr));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-char-to-integer
	(lambda ()
		(let ((addr (lookup-fvar 'char->integer fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_char_to_integer);" nl
			"Lprim_char_to_integer:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2)); // char" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	PUSH(R0);" nl
			"	CALL(MAKE_SOB_INTEGER);" nl
			"	DROP(1);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_char_to_integer:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_char_to_integer));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-integer-to-char
	(lambda ()
		(let ((addr (lookup-fvar 'integer->char fvars-table)))
		(string-append
			"JUMP(Lcreate_prim_integer_to_char);" nl
			"Lprim_integer_to_char:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2)); // int" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	PUSH(R0);" nl
			"	CALL(MAKE_SOB_CHAR);" nl
			"	DROP(1);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_integer_to_char:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_integer_to_char));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-remainder
	(lambda ()
		(let ((addr (lookup-fvar 'remainder fvars-table)))
			(string-append
			"JUMP(Lcreate_prim_remainder);" nl
			"Lprim_remainder:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R0,FPARG(2)); // int1" nl
			"	MOV(R1,FPARG(3)); // int2" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	REM(R0,R1);" nl
			"	PUSH(R0);" nl
			"	CALL(MAKE_SOB_INTEGER);" nl
			"	DROP(1);"
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_remainder:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_remainder));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-plus
	(lambda ()
		(let ((addr (lookup-fvar '+ fvars-table)))
			(string-append
			"JUMP(Lcreate_prim_plus);" nl
			"Lprim_plus:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R2,FPARG(1)); // number of params" nl
			"	CMP(R2,IMM(1));" nl
			"	JUMP_EQ(Lprim_plus_zero_params);" nl
			"	MOV(R0,FPARG(2)); // int1" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R3,IMM(3));" nl
			"	ADD(R2,IMM(1));" nl
			"Lprim_plus_loop:" nl
			"	CMP(R3,R2);" nl
			"	JUMP_EQ(Lend_prim_plus);" nl
			"	MOV(R1,FPARG(R3)); // next-int" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	ADD(R0,R1);" nl
			"	ADD(R3,IMM(1));" nl
			"	JUMP(Lprim_plus_loop);" nl
			"Lprim_plus_zero_params:" nl
			"	MOV(R0,IMM(0));" nl
			"Lend_prim_plus:" nl
			"	PUSH(R0);" nl
			"	CALL(MAKE_SOB_INTEGER);" nl
			"	DROP(1);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_plus:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_plus));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-minus
	(lambda ()
		(let ((addr (lookup-fvar '- fvars-table)))
			(string-append
			"JUMP(Lcreate_prim_minus);" nl
			"Lprim_minus:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R2,FPARG(1)); // number of params" nl
			"	CMP(R2,IMM(1));" nl
			"	JUMP_EQ(Lprim_minus_zero_params);" nl
			"	CMP(R2,IMM(2));" nl
			"	JUMP_EQ(Lprim_minus_one_param);" nl
			"	MOV(R0,FPARG(2)); // int1" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R3,IMM(3));" nl
			"	ADD(R2,IMM(1));" nl
			"Lprim_minus_loop:" nl
			"	CMP(R3,R2);" nl
			"	JUMP_EQ(Lend_prim_minus);" nl
			"	MOV(R1,FPARG(R3)); // next-int" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	SUB(R0,R1);" nl
			"	ADD(R3,IMM(1));" nl
			"	JUMP(Lprim_minus_loop);" nl
			"Lprim_minus_one_param:" nl
			"	MOV(R0,IMM(0));" nl
			"	MOV(R1,FPARG(2));" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	SUB(R0,R1);" nl
			"	JUMP(Lend_prim_minus);" nl
			"Lprim_minus_zero_params:" nl
			"	MOV(R0,IMM(0));" nl
			"Lend_prim_minus:" nl
			"	PUSH(R0);" nl
			"	CALL(MAKE_SOB_INTEGER);" nl
			"	DROP(1);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_minus:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_minus));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-mul
	(lambda ()
		(let ((addr (lookup-fvar '* fvars-table)))
			(string-append
			"JUMP(Lcreate_prim_mul);" nl
			"Lprim_mul:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R2,FPARG(1)); // number of params" nl
			"	CMP(R2,IMM(1));" nl
			"	JUMP_EQ(Lprim_mul_zero_params);" nl
			"	MOV(R0,FPARG(2)); // int1" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R3,IMM(3));" nl
			"	ADD(R2,IMM(1));" nl
			"Lprim_mul_loop:" nl
			"	CMP(R3,R2);" nl
			"	JUMP_EQ(Lend_prim_mul);" nl
			"	MOV(R1,FPARG(R3)); // next-int" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	MUL(R0,R1);" nl
			"	ADD(R3,IMM(1));" nl
			"	JUMP(Lprim_mul_loop);" nl
			"Lprim_mul_zero_params:" nl
			"	MOV(R0,IMM(1));" nl
			"Lend_prim_mul:" nl
			"	PUSH(R0);" nl
			"	CALL(MAKE_SOB_INTEGER);" nl
			"	DROP(1);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_mul:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_mul));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-div
	(lambda ()
		(let ((addr (lookup-fvar '/ fvars-table)))
			(string-append
			"JUMP(Lcreate_prim_div);" nl
			"Lprim_div:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R2,FPARG(1)); // number of params" nl
			"	CMP(R2,IMM(1));" nl
			"	JUMP_EQ(Lprim_div_zero_params);" nl
			"	CMP(R2,IMM(2));" nl
			"	JUMP_EQ(Lprim_div_one_param);" nl
			"	MOV(R0,FPARG(2)); // int1" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R3,IMM(3));" nl
			"	ADD(R2,IMM(1));" nl
			"Lprim_div_loop:" nl
			"	CMP(R3,R2);" nl
			"	JUMP_EQ(Lend_prim_div);" nl
			"	MOV(R1,FPARG(R3)); // next-int" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	DIV(R0,R1);" nl
			"	ADD(R3,IMM(1));" nl
			"	JUMP(Lprim_div_loop);" nl
			"Lprim_div_one_param:" nl
			"	MOV(R0,IMM(1));" nl
			"	MOV(R1,FPARG(2));" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	DIV(R0,R1);" nl
			"	JUMP(Lend_prim_div);" nl
			"Lprim_div_zero_params:" nl
			"	MOV(R0,IMM(0));" nl
			"Lend_prim_div:" nl
			"	PUSH(R0);" nl
			"	CALL(MAKE_SOB_INTEGER);" nl
			"	DROP(1);" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_div:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_div));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-smaller
	(lambda ()
		(let ((addr (lookup-fvar '< fvars-table)))
			(string-append
			"JUMP(Lcreate_prim_smaller);" nl
			"Lprim_smaller:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R2,FPARG(1)); // number of params" nl
			"	CMP(R2,IMM(1));" nl
			"	JUMP_EQ(Lprim_smaller_false);" nl
			"	CMP(R2,IMM(2));" nl
			"	JUMP_EQ(Lprim_smaller_true);" nl
			"	MOV(R0,FPARG(2)); // int1" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R3,IMM(3));" nl
			"	ADD(R2,IMM(1));" nl
			"Lprim_smaller_loop:" nl
			"	CMP(R3,R2);" nl
			"	JUMP_EQ(Lprim_smaller_true);" nl
			"	MOV(R1,FPARG(R3)); // next-int" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	CMP(R0,R1);" nl
			"	JUMP_GE(Lprim_smaller_false);" nl
			"	MOV(R0,R1);" nl
			"	ADD(R3,IMM(1));" nl
			"	JUMP(Lprim_smaller_loop);" nl
			"Lprim_smaller_true:" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_smaller);" nl
			"Lprim_smaller_false:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_smaller:" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_smaller:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_smaller));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-greater
	(lambda ()
		(let ((addr (lookup-fvar '> fvars-table)))
			(string-append
			"JUMP(Lcreate_prim_greater);" nl
			"Lprim_greater:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R2,FPARG(1)); // number of params" nl
			"	CMP(R2,IMM(1));" nl
			"	JUMP_EQ(Lprim_greater_false);" nl
			"	CMP(R2,IMM(2));" nl
			"	JUMP_EQ(Lprim_greater_true);" nl
			"	MOV(R0,FPARG(2)); // int1" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R3,IMM(3));" nl
			"	ADD(R2,IMM(1));" nl
			"Lprim_greater_loop:" nl
			"	CMP(R3,R2);" nl
			"	JUMP_EQ(Lprim_greater_true);" nl
			"	MOV(R1,FPARG(R3)); // next-int" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	CMP(R0,R1);" nl
			"	JUMP_LE(Lprim_greater_false);" nl
			"	MOV(R0,R1);" nl
			"	ADD(R3,IMM(1));" nl
			"	JUMP(Lprim_greater_loop);" nl
			"Lprim_greater_true:" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_greater);" nl
			"Lprim_greater_false:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_greater:" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_greater:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_greater));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-equal
	(lambda ()
		(let ((addr (lookup-fvar '= fvars-table)))
			(string-append
			"JUMP(Lcreate_prim_equal);" nl
			"Lprim_equal:" nl
			"	PUSH(FP);" nl
			"	MOV(FP, SP);" nl
			"	MOV(R2,FPARG(1)); // number of params" nl
			"	CMP(R2,IMM(1));" nl
			"	JUMP_EQ(Lprim_equal_false);" nl
			"	CMP(R2,IMM(2));" nl
			"	JUMP_EQ(Lprim_equal_true);" nl
			"	MOV(R0,FPARG(2)); // int1" nl
			"	MOV(R0,INDD(R0,1));" nl
			"	MOV(R3,IMM(3));" nl
			"	ADD(R2,IMM(1));" nl
			"Lprim_equal_loop:" nl
			"	CMP(R3,R2);" nl
			"	JUMP_EQ(Lprim_equal_true);" nl
			"	MOV(R1,FPARG(R3)); // next-int" nl
			"	MOV(R1,INDD(R1,1));" nl
			"	CMP(R0,R1);" nl
			"	JUMP_NE(Lprim_equal_false);" nl
			"	MOV(R0,R1);" nl
			"	ADD(R3,IMM(1));" nl
			"	JUMP(Lprim_equal_loop);" nl
			"Lprim_equal_true:" nl
			"	MOV(R0,SOB_BOOLEAN_TRUE);" nl
			"	JUMP(Lend_prim_equal);" nl
			"Lprim_equal_false:" nl
			"	MOV(R0,SOB_BOOLEAN_FALSE);" nl
			"Lend_prim_equal:" nl
			"	POP(FP);" nl
			"	RETURN;" nl
			"Lcreate_prim_equal:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_equal));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))

(define prim-apply
	(lambda ()
		(let ((addr (lookup-fvar 'apply fvars-table)))
			(string-append
			"JUMP(Lcreate_prim_apply);" nl
			"Lprim_apply:" nl
			"	PUSH(FP);" nl
			"	MOV(FP,SP);" nl
			"	MOV(R3,FPARG(2));" nl
			"	MOV(R0,FPARG(3)); // R0 holds the list" nl
			"	MOV(R4,SP); // R4 holds the bottom of params on stack" nl
			"	MOV(R7,IMM(0));" nl
			"Lprim_apply_list_loop:" nl
			"	CMP(INDD(R0,2),SOB_NIL);" nl
			"	JUMP_EQ(Lend_apply_list_loop);" nl
			"	MOV(R1,INDD(R0,1));" nl
			"	PUSH(R1);" nl
			"	MOV(R0,INDD(R0,2));" nl
			"	ADD(R7,IMM(1));" nl
			"	JUMP(Lprim_apply_list_loop);" nl
			"Lend_apply_list_loop:" nl
			"	MOV(R1,INDD(R0,1));" nl
			"	MOV(R2,INDD(R0,2));" nl
			"	PUSH(R1);" nl
			"	PUSH(R2);" nl
			"	ADD(R7,IMM(2)); // R7 holds num of params" nl
			"	PUSH(R7);" nl
			"	MOV(R5,SP);" nl 
			"	SUB(R5,IMM(2)); // R5 holds the top of params on stack" nl
			"Lreverse_params:" nl
			"	CMP(R4,R5);" nl
			"	JUMP_GE(Lapply_in_tp);" nl
			"	MOV(R6,STACK(R4));" nl
			"	MOV(STACK(R4),STACK(R5));" nl
			"	MOV(STACK(R5),R6);" nl
			"	SUB(R5,IMM(1));" nl
			"	ADD(R4,IMM(1));" nl
			"	JUMP(Lreverse_params);" nl
			"Lapply_in_tp:" nl
			"	MOV(R0,R3); // R0 holds the proc to apply" nl
			"	PUSH(INDD(R0,1)); //push env" nl
			"	PUSH(FPARG(-1)); // push ret" nl
			"	MOV(R7,FPARG(-2));" nl
			"	MOV(R1,FPARG(1));" nl
			"	MOV(R4,R1);" nl
			"	ADD(R4,IMM(4));" nl
			"	ADD(R1,IMM(1)); //FPARG(R1) - BOTTOM OF OLD FRAME" nl
			"	ADD(R2,IMM(4)); //R2 HOLDS NUM OF ITEMS TO COPY" nl
			"	MOV(R3,FP);" nl
			"	// loop to override stack" nl
			"Lapply_in_tp_loop:" nl
				"	CMP(R2,IMM(0));" nl
				"	JUMP_EQ(Lend_prim_apply);" nl
				"	MOV(FPARG(R1),STACK(R3));" nl
				"	SUB(R1,IMM(1));" nl
				"	ADD(R3,IMM(1));" nl
				"	SUB(R2,IMM(1));" nl
				"	JUMP(Lapply_in_tp_loop);" nl

			"Lend_prim_apply:" nl
			"	DROP(R4);" nl
			"	MOV(FP,R7);" nl
			"	JUMPA(INDD(R0,2));" nl
			"Lcreate_prim_apply:" nl
			"	PUSH(3);" nl
			"	CALL(MALLOC);" nl
			"	DROP(1);" nl
			"	MOV(INDD(R0,0),IMM(T_CLOSURE));" nl
			"	MOV(INDD(R0,1),IMM(0));" nl
			"	MOV(INDD(R0,2),LABEL(Lprim_apply));" nl
			"	MOV(IND(" (number->string addr) "),R0);" nl))))