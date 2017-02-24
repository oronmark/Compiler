(include "pc.scm")
(include "pattern-matcher.scm")
(include "qq.scm")

;;----------------------------------------------------------------------------------    part 5

(define set?
  (lambda (expr v)  ;first iteration with original lambda body only
    ;       (display "set?\n")
    (cond ((equal? (car expr) 'set) (if (equal? (get-set-var expr) `(var ,v))
                                      #t
                                      #f))
          ((equal? (car expr) 'if3) (or (set? (get-if-test expr) v) 
                                        (set? (get-if-dit expr) v) 
                                        (set? (get-if-dif expr) v)))
          ((equal? (car expr) 'def) (or (set? (get-def-var expr) v) 
                                        (set? (get-def-val expr) v)))
          ((equal? (car expr) 'applic) (or (set? (get-applic-operator expr) v)
                                           (ormap (lambda (ex) (set? ex v)) (get-applic-operands expr))))
          ((equal? (car expr) 'seq) (ormap (lambda (ex) (set? ex v)) (get-seq-list expr)))
          ((equal? (car expr) 'or) (ormap (lambda (ex) (set? ex v)) (get-or-body expr)))
          ((and (is-lambda-expr? expr) (not (member-param? expr v))) (set? (get-lambda-body expr) v))                              
          (else #f))
    ))

(define read?
  (lambda (expr v) 

   ;check for expr=(var v) in nested scope
    ;       (display "read?\n")
    (cond ;((equal? (car expr) 'set) (or (read? (get-set-var expr) v) (read? (get-set-val expr) v)))
      ((equal? (car expr) 'set) (or (read? (get-set-val expr) v) (equal? (get-set-var expr) `(var ,v))))
      ((equal? (car expr) 'var) (equal? expr `(var ,v)))
      ((equal? (car expr) 'if3) (or (read? (get-if-test expr) v) 
                                    (read? (get-if-dit expr) v) 
                                    (read? (get-if-dif expr) v)))
      ((equal? (car expr) 'def) (or (read? (get-def-var expr) v) 
                                    (read? (get-def-val expr) v)))
      ((equal? (car expr) 'applic) (or (read? (get-applic-operator expr) v)
                                       (ormap (lambda (ex) (read? ex v)) (get-applic-operands expr))))
      ((equal? (car expr) 'seq) (ormap (lambda (ex) (read? ex v)) (get-seq-list expr)))
      ((equal? (car expr) 'or) (ormap (lambda (ex) (read? ex v)) (get-or-body expr)))
      ((and (is-lambda-expr? expr) (not (member-param? expr v))) (read? (get-lambda-body expr) v))                             
      (else #f))
    ))


(define bound?
  (lambda (expr v)
    ;       (display "bound?\n")
    (cond ((equal? (car expr) 'set) (or (bound? (get-set-var expr) v) (bound? (get-set-val expr) v)))
          ((equal? (car expr) 'if3) (or (bound? (get-if-test expr) v) 
                                        (bound? (get-if-dit expr) v) 
                                        (bound? (get-if-dif expr) v)))
          ((equal? (car expr) 'def) (or (bound? (get-def-var expr) v) 
                                        (bound? (get-def-val expr) v)))
          ((equal? (car expr) 'applic) (or (bound? (get-applic-operator expr) v)
                                           (ormap (lambda (ex) (bound? ex v)) (get-applic-operands expr))))
          ((equal? (car expr) 'seq) (ormap (lambda (ex) (bound? ex v)) (get-seq-list expr)))
          ((equal? (car expr) 'or) (ormap (lambda (ex) (bound? ex v)) (get-or-body expr)))
          ((and (is-lambda-expr? expr) (not (member-param? expr v))) (read? expr v))                       
          (else #f))           
    ))

(define to-box?
  (lambda (l-expr v)      
   ; (disp v)
  ;;  (disp (read? (get-lambda-body l-expr) v))
  ;  (disp (set? (get-lambda-body l-expr) v))
   ; (disp (bound? (get-lambda-body l-expr) v))
    (and (read? (get-lambda-body l-expr) v) (set? (get-lambda-body l-expr) v) (bound? (get-lambda-body l-expr) v))
    ))

(define box-var  
  (lambda (expr v)
    ;       (display "box-var\n")
    (cond ((null? expr) expr)
          ((atom? expr) expr)
          ((equal? expr `(var ,v)) `(box-get (var ,v)))
          ((and (equal? (car expr) 'set) (equal? (cadr expr) `(var ,v))) `(box-set ,(cadr expr) ,(box-var (caddr expr) v)))
          ((and (is-lambda-expr? expr) (member-param? expr v)) expr)               
          (else (map (lambda (ex) (box-var ex v)) expr)))
    ))

(define box-simple 
  (lambda (l-expr v minor)  
    ;       (display "box-simple\n")
    (let* ((l-type (car l-expr))
           (args (cadr l-expr))
           (rest (caddr l-expr)))
      (if (equal? (car rest) 'seq)
        `(,l-type ,args (seq ((set (pvar ,v ,minor) (box (pvar ,v ,minor))) ,@(box-var (cadr rest) v))))
        `(,l-type ,args (seq ((set (pvar ,v ,minor) (box (pvar ,v ,minor))) ,(box-var rest v)))))
      )
    ))

(define box-opt 
  (lambda (l-expr v minor)  
    ;       (display "box-opt\n")
    (let* ((l-type (car l-expr))
           (args (get-lambda-opt-param l-expr))
           (lst (get-lambda-opt-param-list l-expr))
           (rest (get-lambda-body l-expr)))
      (if (equal? (car rest) 'seq)
        `(,l-type ,args ,lst (seq ((set (pvar ,v ,minor) (box (pvar ,v ,minor))) ,@(box-var (cadr rest) v))))
        `(,l-type ,args ,lst (seq ((set (pvar ,v ,minor) (box (pvar ,v ,minor))) ,(box-var rest v)))))
      )
    ))

(define box-variadic
  (lambda (l-expr v minor)  
    ;       (display "box-var\n")
    (let* ((l-type (car l-expr))
           (args (get-lambda-var-param l-expr))
           (rest (get-lambda-body l-expr)))
      (if (equal? (car rest) 'seq)
        `(,l-type ,args (seq ((set (pvar ,v ,minor) (box (pvar ,v ,minor))) ,@(box-var (cadr rest) v))))
        `(,l-type ,args (seq ((set (pvar ,v ,minor) (box (pvar ,v ,minor))) ,(box-var rest v)))))
      )
    ))

(define box
  (lambda (l-expr v minor)
    ;       (display "box \n")
    (cond  ((equal? (car l-expr) 'lambda-simple) (box-simple l-expr v minor))
           ((equal? (car l-expr) 'lambda-opt) (box-opt l-expr v minor))
           (else  (equal? (caaddr l-expr) (box-variadic l-expr v minor))))))

(define reverse-list
  (lambda (lst)
    (if (null? lst)
      lst
      (cons (get-last-elem lst) (reverse-list (remove-last-elem lst))))
    ))

(define count
  (lambda (lst)
    (if (null? lst)
      0
      (+ 1 (count (cdr lst))))))


(define box-all-args
  (lambda (l-expr args minor)
    ;       (display "box-all-args\n")
    ;         (disp args)
    ; (disp minor)

    (cond ((null? args) l-expr)
          ((to-box? l-expr (car args)) (box-all-args (box l-expr (car args) (- minor 1)) (cdr args) (- minor 1)))
          (else (box-all-args l-expr (cdr args) (- minor 1))))
    ))

(define box-all
  (lambda (l-expr)
    ;       (display "box-all\n")
    (cond ((equal? (car l-expr) 'lambda-simple) (box-all-args l-expr (reverse-list (get-lambda-simple-param l-expr)) 
                                                              (count (get-lambda-simple-param l-expr)) ))
          ((equal? (car l-expr) 'lambda-opt) (box-all-args l-expr 
                                                           (reverse-list `(,@(get-lambda-opt-param l-expr) ,(get-lambda-opt-param-list l-expr))) 
                                                           (count `(,@(get-lambda-opt-param l-expr) ,(get-lambda-opt-param-list l-expr)))))
          (else (box-all-args l-expr `(,(get-lambda-opt-param-list l-expr)) (count `(,(get-lambda-opt-param-list l-expr))))))
    ))

(define box-set
  (lambda (expr)
    ;       (display "box-set\n")

    (cond ((null? expr) expr)
          ((atom? expr) expr)
          ((is-lambda-expr? expr) (map box-set (box-all expr)))
          (else (map box-set expr)))                               
    ))

;---------------------------------------------------------------------------------------------------- ;
;;helper functions

(define disp
  (lambda (exp)
    (display "\n")
    (display "The expression is: ")
    (display exp)
    (display "\n")))



(define get-or-body
  (lambda (expr)
    (cadr expr)
    ))

(define remove-last-elem
  (lambda (lst)
    (if (null? (cdr lst))
      '()
      (cons (car lst) (remove-last-elem (cdr lst))))
    ))

(define get-last-elem
  (lambda (lst)
    (if (null? (cdr lst))
      (car lst)
      (get-last-elem (cdr lst)))
    ))

(define get-if-test
  (lambda (if-exp)
    (cadr if-exp)))

(define get-if-dit
  (lambda (if-exp)
    (caddr if-exp)))

(define get-if-dif
  (lambda (if-exp)
    (cadddr if-exp)))

(define get-def-var
  (lambda (def-expr)
    (cadr def-expr)))

(define get-def-val
  (lambda (def-expr)
    (caddr def-expr)))

(define get-set-var
  (lambda (set-expr)
    (cadr set-expr)))

(define get-set-val
  (lambda (set-expr)
    (caddr set-expr)))

(define get-lambda-opt-param
  (lambda (l-expr)
    (cadr l-expr)))

(define get-lambda-opt-param-list
  (lambda (l-expr)
    (caddr l-expr)))

(define get-lambda-var-param
  (lambda (l-expr)
    (cadr l-expr)))

(define get-lambda-simple-param
  (lambda (l-expr)
    (cadr l-expr)))

(define get-lambda-simple-body
  (lambda (l-expr)
    (caddr l-expr)))

(define get-lambda-opt-body
  (lambda (l-expr)
    (cadddr l-expr)))

(define get-lambda-var-body
  (lambda (l-expr)
    (caddr l-expr)))

(define get-applic-operator
  (lambda (applic-expr)
    (cadr applic-expr)))

(define get-applic-operands
  (lambda (applic-expr)
    (caddr applic-expr)))

(define get-seq-list
  (lambda (seq-expr)
    (cadr seq-expr)
    ))

(define get-const-val
  (lambda (const-expr)
    (cadr const-expr)
    ))

(define get-lambda-body
  (lambda (l-expr)
    (cond  ((equal? (car l-expr) 'lambda-simple) (get-lambda-simple-body l-expr))
           ((equal? (car l-expr) 'lambda-opt) (get-lambda-opt-body l-expr))
           (else  (get-lambda-var-body l-expr)))))

(define is-lambda-expr?
  (lambda (expr)
    (or (equal? (car expr) 'lambda-simple) (equal? (car expr) 'lambda-opt) (equal? (car expr) 'lambda-var))))


(define is-lambda-seq?
  (lambda (l-expr)
    (cond  ((equal? (car l-expr) 'lambda-simple) (equal? (caaddr l-expr) 'seq))
           ((equal? (car l-expr) 'lambda-opt) (equal? (car (cadddr l-expr)) 'seq))
           (else  (equal? (caaddr l-expr) 'seq)))))


(define member-simple? 
  (lambda (l-expr v)
    (ormap (lambda (x) (equal? v x)) (get-lambda-simple-param l-expr))
    ))

(define member-opt?
  (lambda (l-expr v)
    (or (ormap (lambda (x) (equal? v x)) (get-lambda-opt-param l-expr)) (equal? (get-lambda-opt-param-list l-expr) v))
    ))


(define member-var?
  (lambda (l-expr v)
    (equal? (get-lambda-var-param l-expr) v)
    ))

(define member-param?
  (lambda (l-expr v)
    (cond ((equal? (car l-expr ) 'lambda-simple) (member-simple? l-expr v))
          ((equal? (car l-expr ) 'lambda-opt) (member-opt? l-expr v))
          (else  (member-var? l-expr v)))
    ))

(define get-lambda-param-list
  (lambda (l-expr)
    (cond ((equal? (car l-expr ) 'lambda-simple) (get-lambda-simple-param l-expr))
          ((equal? (car l-expr ) 'lambda-opt) (append (get-lambda-opt-param l-expr) `(,(get-lambda-opt-param-list l-expr))))
          (else  `(,(get-lambda-var-param l-expr))))))
;-----------------------------------expr identifier------------------------------------------
(define const-expr?
  (lambda (expr)
    (equal? (car expr) 'const)
    ))

(define var-expr?
  (lambda (expr)
    (equal? (car expr) 'var)
    ))

(define pvar-expr?
  (lambda (expr)
    (equal? (car expr) 'pvar)
    ))

(define bvar-expr?
  (lambda (expr)
    (equal? (car expr) 'bvar)
    ))

(define fvar-expr?
  (lambda (expr)
    (equal? (car expr) 'fvar)
    ))

(define if-expr?
  (lambda (expr)
    (equal? (car expr) 'if3)
    ))

(define applic-expr?
  (lambda (expr)
    (equal? (car expr) 'applic)
    ))

(define tc-applic-expr?
  (lambda (expr)
    (equal? (car expr) 'tc-applic)
    ))

(define seq-expr?
  (lambda (expr)
    (equal? (car expr) 'seq)
    ))

(define lambda-simple-expr?
  (lambda (expr)
    (equal? (car expr) 'lambda-simple)
    ))

(define lambda-opt-expr?
  (lambda (expr)
    (equal? (car expr) 'lambda-opt)
    ))

(define lambda-var-expr?
  (lambda (expr)
    (equal? (car expr) 'lambda-var)
    ))


(define or-expr?
  (lambda (expr)
    (equal? (car expr) 'or)
    ))

(define define-expr?
  (lambda (expr)
    (equal? (car expr) 'def)
    ))

(define set-expr?
  (lambda (expr)
    (equal? (car expr) 'set)
    ))
  
;--------------------------------------------------------------------------------------;;part 4

(define make-expr-no-redundant
  (lambda (expr)
    (let*  
      ((op (get-applic-operator expr))
       (args (get-applic-operands expr))) 
      (if (and (is-lambda-expr? op) (null? args) (null? (get-lambda-simple-param op)))
        (get-lambda-body op)
        expr)


      )
    ))

(define remove-applic-lambda-nil
  (lambda (expr)
    (cond ((equal? (car expr) 'or) `(or ,(map remove-applic-lambda-nil (get-or-body expr))))

          ((equal? (car expr) 'seq) `(seq ,(map remove-applic-lambda-nil (get-seq-list expr))))
          ((equal? (car expr) 'set) `(set ,(remove-applic-lambda-nil (get-set-var expr))
                                          ,(remove-applic-lambda-nil (get-set-val expr))))
          ((equal? (car expr) 'if3) `(if3 ,(remove-applic-lambda-nil (get-if-test expr))
                                          ,(remove-applic-lambda-nil (get-if-dit expr))
                                          ,(remove-applic-lambda-nil (get-if-dif expr))))
          ((equal? (car expr) 'def) `(def ,(remove-applic-lambda-nil (get-def-var expr))
                                          ,(remove-applic-lambda-nil (get-def-val expr))))
          ((equal? (car expr) 'lambda-simple) `(lambda-simple ,(get-lambda-simple-param expr) 
                                                              ,(remove-applic-lambda-nil (get-lambda-body expr)))) 
          ((equal? (car expr) 'lambda-opt) `(lambda-opt ,(get-lambda-opt-param expr) ,(get-lambda-opt-param-list expr)
                                                        ,(remove-applic-lambda-nil (get-lambda-body expr))))
          ((equal? (car expr) 'lambda-var) `(lambda-var ,(get-lambda-var-param expr) 
                                                        ,(remove-applic-lambda-nil (get-lambda-body expr))))                                  
          ((equal? (car expr) 'applic) (make-expr-no-redundant `(applic ,(remove-applic-lambda-nil (get-applic-operator expr))
                                                                        ,(map remove-applic-lambda-nil  
                                                                              (get-applic-operands expr)))))

          (else expr))
    ))

;;--------------------------------------------------------------------------------------- part 7

(define tc
  (lambda (expr tp?)
    (cond ((equal? (car expr) 'or) `(or ,(append (map (lambda (ex) (tc ex #f)) (remove-last-elem (get-or-body expr))) 
                                                 (list (tc (get-last-elem (get-or-body expr)) tp?)))))
          ((equal? (car expr) 'seq) `(seq ,(append (map (lambda (ex) (tc ex #f)) (remove-last-elem (get-or-body expr))) 
                                                   (list (tc (get-last-elem (get-or-body expr)) tp?)))))
          ((equal? (car expr) 'set) `(set ,(get-set-var expr) ,(tc (get-set-val expr) tp?)))
          ((equal? (car expr) 'if3) `(if3 ,(tc (get-if-test expr) #f) ,(tc (get-if-dit expr) tp?) ,(tc (get-if-dif expr) tp?)))
          ((equal? (car expr) 'def) `(def ,(get-def-var expr) ,(tc (get-def-val expr) #f)))
          ((equal? (car expr) 'lambda-simple) `(lambda-simple ,(get-lambda-simple-param expr) 
                                                              ,(tc (get-lambda-simple-body expr) #t)))
          ((equal? (car expr) 'lambda-opt) `(lambda-opt ,(get-lambda-opt-param expr) ,(get-lambda-opt-param-list expr)  
                                                        ,(tc (get-lambda-opt-body expr) #t)))
          ((equal? (car expr) 'lambda-var) `(lambda-var ,(get-lambda-var-param expr),(tc (get-lambda-var-body expr) #t)))
          ((equal? (car expr) 'applic) (if (eq? tp? #f)
                                         `(applic ,(tc (get-applic-operator expr) #f) ,(map (lambda (ex) (tc ex #f)) (get-applic-operands expr)))
                                         `(tc-applic ,(tc (get-applic-operator expr) #f) ,(map (lambda (ex) (tc ex #f)) (get-applic-operands expr)))))
          (else expr))
    ))

(define annotate-tc
  (lambda (expr)
    (tc expr #f)))

;;--------------------------------------------------------------------------------------- part 6

(define seq?
  (lambda(exp)
    (and (pair? exp) (equal? (car exp) 'seq))))

(define seq-exps
  (lambda(exp)
    (cadr exp)))

(define lambda-simple-pred
  (lambda(exp)
    (and (pair? exp) (equal? (car exp) 'lambda-simple))))

(define lambda-simple-vars
  (lambda(exp)
    (cadr exp)))

(define lambda-simple-body
  (lambda(exp)
    (caddr exp)))

(define lambda-opt-pred
  (lambda(exp)
    (and (pair? exp) (equal? (car exp) 'lambda-opt))))

(define lambda-opt-vars
  (lambda(exp)
    (cadr exp)))

(define lambda-opt-last
  (lambda(exp)
    (caddr exp)))

(define lambda-opt-body
  (lambda(exp)
    (cadddr exp)))

(define lambda-variadic-exp?
  (lambda(exp)
    (and (pair? exp) (equal? (car exp) 'lambda-var))))

(define lambda-var-vars
  (lambda(exp)
    (cadr exp)))

(define lambda-var-body
  (lambda(exp)
    (caddr exp)))

(define my-var?
  (lambda(exp)
    (and (pair? exp) (equal? (car exp) 'var))))

(define get-my-var?
  (lambda(exp)
    (cadr exp)))

(define get-position
  (lambda(item  stack  )
    (letrec ((iter 
               (lambda(stack item i)
                 (if (equal? (car stack) item) i
                   (iter (cdr stack) item (+ i 1))))))
      (iter stack item 0))))

(define member?
  (lambda(item env)
    (cond ((null? env) #f)
          ((member item (car env)) #t)
          (else (member? item (cdr env) )))))

(define item-pos-env
  (lambda(item env)
    (letrec ((iter
               (lambda(env item i)
                 (if (member item (car env)) 
                   (cons (car env) i) 
                   (iter (cdr env) item (+ i 1)  )))))
      (let* ((stack-row (iter env item 0))
             (stack (car stack-row))
             (row (cdr stack-row))
             (col (get-position item stack)))
        (cons row col)))))

(define pe->lex-pe
  (lambda (expr)
    (annotate-helper expr '() '())
    ))

(define annotate-helper 
  (lambda (exp stack env)
    (cond ((lambda-simple-pred exp)
           (let* ((inner-stack (lambda-simple-vars exp))
                  (body (lambda-simple-body exp))
                  (inner-env  (cons stack env)))
             (if (seq? body) 
               `(lambda-simple ,inner-stack (seq ,(map (lambda(exp) (annotate-helper  exp inner-stack inner-env)) (seq-exps body))))  
               `(lambda-simple ,inner-stack ,(annotate-helper body inner-stack inner-env)))))
          ((lambda-variadic-exp? exp)
           (let* ((var  (lambda-var-vars exp))
                  (inner-stack (list var))
                  (body (lambda-var-body exp))
                  (inner-env  (cons stack env)))         
             (if (seq? body) 
               `(lambda-var ,var (seq ,(map (lambda(exp) (annotate-helper  exp inner-stack inner-env)) (seq-exps body))))  
               `(lambda-var ,var ,(annotate-helper body inner-stack inner-env)))))
          ((lambda-opt-pred exp)
           (let* ((vars (lambda-opt-vars exp))
                  (last-var (lambda-opt-last exp))
                  (inner-stack (append vars (list last-var)))
                  (body (lambda-opt-body exp))
                  (inner-env  (cons stack env)))         
             (if (seq? body) 
               `(lambda-opt ,vars ,last-var (seq ,(map (lambda(exp) (annotate-helper  exp inner-stack inner-env)) (seq-exps body))))  
               `(lambda-opt ,vars ,last-var ,(annotate-helper body inner-stack inner-env)))))
          ((my-var? exp)
           (let ((var (get-my-var? exp)))
             (cond ((member var stack) `(pvar ,var ,(get-position var  stack  )  ))
                   ((member? var env)
                    (let ((pos (item-pos-env var env)))
                      `(bvar ,var ,(car pos) ,(cdr pos))))
                   (else `(fvar ,var)))))
          ((list? exp) (map (lambda(exp) (annotate-helper  exp stack env)) exp))
          (else exp)
          )))

;--------------------------------------------------------------------------------------- Eliminate-nested defines

;@param lst - list of expression from a lambda's body with seq
;@example - (lambd-simple (x) (seq (a b c))) --> lst = (a b c)
(define make-def-set-list
  (lambda (lst)
    (cond ((null? lst) lst)
          ((equal? (caar lst) 'def) (cons `(set ,(get-def-var (car lst)) ,(get-def-val (car lst))) (make-def-set-list (cdr lst))))
          (else '()))
    ))

;@param lst - list of expression from a lambda's body with seq
;@example - (lambd-simple (x) (seq (a b c))) --> lst = (a b c)
(define make-def-var-list
  (lambda (lst)
    (cond ((null? lst) lst)
          ((equal? (caar lst) 'def) (cons (cadr (get-def-var (car lst))) (make-def-var-list (cdr lst))))
          (else '()))
    ))

;@param lst - list of expression from a lambda's body with seq
;@example - (lambd-simple (x) (seq (a b c))) --> lst = (a b c)
(define make-rest-body
  (lambda (lst)
    (cond ((null? lst) lst)
          ((equal? (caar lst) 'def) (make-rest-body (cdr lst)))
          (else lst))
    ))

(define make-false-list
  (lambda (var-list)
    (if (null? var-list)
      var-list
      (cons `(const #f) (make-false-list (cdr var-list))))
    ))

(define more-then-one?
  (lambda (lst)
    (cond ((null? lst) #f)
          ((null? (cdr lst)) #f)
          (else #t))
    ))

(define eliminate
  (lambda (l-body)
    ;(disp l-body)
    (if (equal? (car l-body) 'seq)
      (let* ((var-list (make-def-var-list (get-seq-list l-body)))
             (set-list (make-def-set-list (get-seq-list l-body)))
             (rest-body (make-rest-body (get-seq-list l-body)))
             (false-list (make-false-list var-list))
             (new-body `(,@set-list ,@rest-body)))
        (cond ((null? set-list) l-body) 
              ((more-then-one? new-body) `(applic (lambda-simple ,var-list (seq ,new-body)) ,false-list))
              (else  `(applic (lambda-simple ,var-list ,new-body) ,false-list))))
      (let* ((var-list (make-def-var-list `(,l-body)))
             (set-list (make-def-set-list `(,l-body)))
             (rest-body (make-rest-body `(,l-body)))
             (false-list `(,l-body))
             (new-body `(,l-body)))
        (cond ((null? set-list) l-body) 
              ((more-then-one? new-body) `(applic (lambda-simple ,var-list (seq ,new-body)) ,false-list))
              (else  `(applic (lambda-simple ,var-list ,new-body) ,false-list)))))
    ))   



(define eliminate-nested-defines
  (lambda (expr)
    ;(disp expr)
    (cond ((equal? (car expr) 'set) `(set ,(eliminate-nested-defines (get-set-var expr))
                                          ,(eliminate-nested-defines (get-set-val expr))))
          ((equal? (car expr) 'if3) `(if3 ,(eliminate-nested-defines (get-if-test expr))
                                          ,(eliminate-nested-defines (get-if-dit expr))
                                          ,(eliminate-nested-defines (get-if-dif expr))))
          ((equal? (car expr) 'def) `(def ,(eliminate-nested-defines (get-def-var expr))
                                          ,(eliminate-nested-defines (get-def-val expr))))
          ((equal? (car expr) 'applic) `(applic ,(eliminate-nested-defines (get-applic-operator expr))
                                                ,(map eliminate-nested-defines (get-applic-operands expr))))
          ((equal? (car expr) 'or) `(or ,(map eliminate-nested-defines (get-or-body expr))))
          ((equal? (car expr) 'seq) `(seq ,(map eliminate-nested-defines (get-seq-list expr))))
          ((equal? (car expr) 'lambda-simple)  `(lambda-simple ,(get-lambda-simple-param expr) 
                                                               ,(eliminate-nested-defines (eliminate (get-lambda-simple-body expr)))))
          ((equal? (car expr) 'lambda-opt) `(lambda-opt ,(get-lambda-opt-param expr) ,(get-lambda-opt-param-list expr)
                                                        ,(eliminate-nested-defines (eliminate (get-lambda-opt-body expr)))))
          ((equal? (car expr) 'lambda-var)  `(lambda-var ,(get-lambda-var-param expr) 
                                                         ,(eliminate-nested-defines (eliminate (get-lambda-var-body expr)))))
          (else expr))
    ))

; ----------------------------------------------------------------------; 

(define *reserved-words*
  '(and begin cond define do else if lambda
        let let* letrec or quasiquote unquote
        unquote-splicing quote set!))

;; returns true if lst is a proper list, false otherwise
(define guard-proper-list
  (lambda (lst)
    (cond
      ((list? lst) #t))))

;; returns true if var is not a reserved word and a symbol, false otherwise
(define guard-reserved-words
  (lambda (var)
    (if (not (symbol? var))
      #f
      (andmap (lambda (x)
                (not (symbol=? var x))) *reserved-words*)))
  )
;; return true if var is (not a reserved word and a symbol) or (list)
(define guard-reserved-words-list
  (lambda (var)
    (if (not (symbol? var))
      #t
      (andmap (lambda (x)
                (not (symbol=? var x))) *reserved-words*)))
  )

;;returns true is expr is not a list, false otherwise
(define guard-not-list
  (lambda (expr)
    (not (list? expr))))

;;If list's tails is nill it is a proper list!
(define guard-improper-list
  (lambda (lst)
    (if (equal? (list-tail lst 1) '())
      #f
      (and (andmap (lambda (elem) (and (symbol? elem) (guard-reserved-words elem))) (get-all-but-last lst '() ))
           (find-dups (get-all-but-last lst '()))
           (and (symbol? (cdr (last-pair lst))) (guard-reserved-words (cdr (last-pair lst))))
           ))))

(define simple-const?
  (lambda (c)
    (or (null? c) (vector? c) (boolean? c) (char? c) (number? c) (string? c))))

(define proper-list?
  (lambda (lst)
    (if (null? lst)
      #t
      (and (pair? lst)
           (proper-list? (cdr lst))))
    ))

(define *void-object*
  `(const ,(void)))

(define get-all-but-last
  (lambda (improper  all-but-last)
    (if (pair? (cdr improper))
      (get-all-but-last (cdr improper) (cons (car improper) all-but-last))
      (cons (car improper) all-but-last)
      )))

(define guard-vars-list
  (lambda (vars)
    (andmap (lambda (var) (and (symbol? var) (guard-reserved-words var))) vars)
    ))

(define find-dups-helper
  (lambda (lst elem help)
    (if (null? lst)
      help
      (if (eq? (car lst) elem)
        (find-dups-helper (cdr lst) elem (append help '(elem)))
        (find-dups-helper (cdr lst) elem help)
        ))))

; returns true if there are no dups and false if there are dups
(define find-dups
  (lambda (lst)
    (andmap (lambda (elem)
              (eq? (length (find-dups-helper lst elem '())) 1)) lst)
    ))

(define guard-mit-def
  (lambda (lst)
    (guard-reserved-words (car lst))
    ))

(define flatten-begin
  (lambda (expr)
    (cond ((null? expr) '())
          ((not (pair? (car expr))) (cons (car expr) (flatten-begin (cdr expr))))
          ((eq? (caar expr) 'begin) (append (flatten-begin (cdar expr)) (flatten-begin (cdr expr))))
          (else  (cons (car expr) (flatten-begin (cdr expr)))))
    ))

(define and->if
  (lambda (exprs)
    (if (null? (cddr exprs))
      `(if ,(car exprs) ,(cadr exprs) #f) ;you have reached the last of the list
      `(if ,(car exprs)
         ,(and->if (cdr exprs))
         #f))
    ))


(define cond->if-one-expr
  (lambda (listOfPairs)
    `(if ,(caar listOfPairs) (begin ,@(cdar listOfPairs)))
    ))


(define cond->if
  (lambda (listOfPairs)
    (if (null? (cdr listOfPairs))
      (cond->if-one-expr listOfPairs)
      (if (null? (cddr listOfPairs))
        (if (eq? (caadr listOfPairs) 'else)
          `(if ,(caar listOfPairs) (begin ,@(cdar listOfPairs)) (begin ,@(cdadr listOfPairs))) ;;with else
          `(if ,(caar listOfPairs) (begin ,@(cdar listOfPairs)) (if ,(caadr listOfPairs)       ;;no else
                                                                  (begin ,@(cdadr listOfPairs) ))))
        `(if ,(caar listOfPairs) (begin ,@(cdar listOfPairs)) ,(cond->if (cdr listOfPairs))))   ;;more then 2 pairs
      )))

(define let->applic
  (lambda (listOfPairs body bodies)
    (let ((vars (fold-right (lambda (pair acc) (cons (car pair) acc)) '() listOfPairs))
          (vals (fold-right (lambda (pair acc) (cons (cadr pair) acc)) '() listOfPairs)))
      (if (find-dups vars)
        `((lambda ,vars ,body ,@bodies) ,@vals)
        (error #f "vars have duplicates in them")
        ))
    ))

(define let*->applic
  (lambda (listOfPairs body bodies)
    (let ((vars (fold-right (lambda (pair acc) (cons (car pair) acc)) '() listOfPairs))
          (vals (fold-right (lambda (pair acc) (cons (cadr pair) acc)) '() listOfPairs)))
      (let*-helper vars vals body bodies)
      )
    ))

(define let*-helper
  (lambda (vars vals body bodies)
    (if (null? (cdr vars))
      `((lambda ,vars ,body ,@bodies) ,@vals)
      `((lambda (,(car vars)) ,(let*-helper (cdr vars) (cdr vals) body bodies)) ,(car vals))
      )
    ))

(define letrec->applic
  (lambda (listOfPairs body bodies)
    (let ((vars (fold-right (lambda (pair acc) (cons (car pair) acc)) '() listOfPairs))
          (vals (fold-right (lambda (pair acc) (cons (cadr pair) acc)) '() listOfPairs)))
      `((lambda ,vars ,@(letrec-seq-helper listOfPairs) (,(letrec-body-helper body bodies))) ,@(map (lambda(pair) #f) listOfPairs))
      )))

(define letrec-seq-helper
  (lambda (listOfPairs)
    (map (lambda (pair) `(set! ,(car pair) ,(cadr pair))) listOfPairs)
    ))

(define letrec-body-helper
  (lambda (body bodies)
    `(lambda () ,body ,@bodies)
    ))

(define guard-cond-rib
  (lambda (rib)
    ; (display "\n")
    ; (display rib)
    ; (display "\n")
    (and (pair? rib) (not (null? (cdr rib))))
    ))

(define guard-cond-rest-ribs
  (lambda (ribs)
    (andmap guard-cond-rib ribs)
    ))

(define parse
  (let ((run
          (compose-patterns
            ;;;;;;;;;;;;const;;;;;;;;;;
            (pattern-rule
              (? 'c simple-const?)
              (lambda (c) `(const ,c)))
            (pattern-rule
              `(quote ,(? 'c))
              (lambda (c) `(const ,c)))
            ;;;;;;;;;;;;variable;;;;;;;;;;
            (pattern-rule                     ;;check ascci output intead of regular output
              (? 'var guard-reserved-words)
              (lambda (var) `(var ,var)))
            ;;;;;;;;;;;;if;;;;;;;;;;
            (pattern-rule
              `(if ,(? 'test) ,(? 'then) ,(? 'else))
              (lambda (test then else)
                `(if3 ,(parse test) ,(parse then) ,(parse else))))
            (pattern-rule
              `(if ,(? 'test) ,(? 'then))
              (lambda (test then)
                `(if3 ,(parse test) ,(parse then) ,*void-object*)))
            ;;;;;;;;;;;;application;;;;;;;;;;
            (pattern-rule
              `(,(? 'application guard-reserved-words-list) . ,(? 'argList))
              (lambda (application argList)
                `(applic ,(parse application) ,(map parse argList))))
            ;;;;;;;;;;;;or;;;;;;;;;;
            (pattern-rule
              `(or . ,(? 'exprList))
              (lambda (exprList)
                (cond ((null? exprList) (parse #f))
                      ((null? (cdr exprList)) (parse (car exprList)))
                      (else `(or ,(map parse exprList)))
                      )
                ))
            ;;;;;;;;;;;;begin;;;;;;;;;;
            (pattern-rule
              `(begin . ,(? 'expers))
              (lambda (expers)
                (if (null? expers)
                  *void-object*
                  (if (null? (cdr expers))
                    (parse (car expers))
                    `(seq ,(map parse (flatten-begin expers))))
                  )
                ))
            ;;;;;;;;;;;lambda-simple;;;;;;;;;;
            (pattern-rule
              `(lambda ,(? 'vars proper-list? guard-vars-list find-dups) ,(? 'body ) . ,(? 'bodies ))
              (lambda (vars body bodies)
                (if (null? bodies)
                  `(lambda-simple ,vars ,(parse body))
                  `(lambda-simple ,vars ,(parse `(begin ,body ,@bodies))))
                ))
            ;;;;;;;;;;;;lambda-opt;;;;;;;;;;
            (pattern-rule
              `(lambda  ,(? 'vars pair? guard-improper-list)  ,(? 'body) . ,(? 'bodies))
              (lambda (vars body bodies)
                (if (null? bodies)
                  `(lambda-opt ,(reverse (get-all-but-last vars '())) ,(cdr (last-pair vars)) ,(parse body))
                  `(lambda-opt ,(reverse (get-all-but-last vars '())) ,(cdr (last-pair vars)) ,(parse `(begin ,body ,@bodies))))
                ))
            ;;;;;;;;;;;;lambda-variadic;;;;;;
            (pattern-rule
              `(lambda ,(? 'vars symbol? guard-reserved-words ) ,(? 'body) . ,(? 'bodies) )
              (lambda (vars body bodies)
                (if (null? bodies)
                  `(lambda-var ,vars ,(parse body))
                  `(lambda-var ,vars ,(parse `(begin ,body ,@bodies))))
                ))
            ;;;;;;;;;;;;define;;;;;;;;;;;;
            (pattern-rule
              `(define ,(? 'var symbol? guard-reserved-words),(? 'val))
              (lambda (var val)
                `(def ,(parse var) ,(parse val))
                ))
            ;;;;;;;;;;;;define-mit;;;;;;;;;;;;
            (pattern-rule
              `(define ,(? 'var guard-mit-def) . ,(? 'exprs))
              (lambda (var exprs)
                `(def ,(parse (car var)) ,(parse `(lambda ,(cdr  var) ,@exprs)))
                ))
            ;;;;;;;;;;;;set!;;;;;;;;;;;;
            (pattern-rule
              `(set! ,(? 'var symbol? guard-reserved-words) ,(? 'expr))
              (lambda (var expr)
                `(set ,(parse var) ,(parse expr))
                ))
            ;;;;;;;;;;;;and-macro-expansion;;;;;;;;;;;;
            (pattern-rule
              `(and . ,(? 'exprs))
              (lambda (exprs)
                (cond ((null? exprs) (parse #t))
                      ((null? (cdr exprs)) (parse (car exprs)))
                      (else (parse (and->if (cons (car exprs) (cdr exprs)))))
                      )
                ))
            ;;;;;;;;;;;;cond-macro-expansion;;;;;;;;;;;;
            (pattern-rule
              `(cond ,(? 'expr guard-cond-rib) . ,(? 'exprs guard-cond-rest-ribs))
              (lambda (expr exprs)
                (parse (cond->if (cons expr exprs)))
                ))
            ;;;;;;;;;;;;let-macro-expansion;;;;;;;;;;;;
            (pattern-rule
              `(let ,(? 'listOfPairs) ,(? 'body) . ,(? 'bodies))
              (lambda (listOfPairs body bodies)
                (parse (let->applic listOfPairs body bodies))
                ))
            ;;;;;;;;;;;;let*-macro-expansion;;;;;;;;;;;;
            (pattern-rule
              `(let* ,(? 'listOfPairs) ,(? 'body) . ,(? 'bodies))
              (lambda (listOfPairs body bodies)
                (if (null? listOfPairs)
                  (parse `((lambda () ,body ,@bodies)))
                  (parse (let*->applic listOfPairs body bodies))
                  )))
            ;;;;;;;;;;;;letrec-macro-expansion;;;;;;;;;;;;
            (pattern-rule
              `(letrec ,(? 'listOfPairs) ,(? 'body) . ,(? 'bodies))
              (lambda (listOfPairs body bodies)
                (if (null? listOfPairs)
                  (parse `((lambda () ((lambda () ,body ,@bodies)))))
                  (parse (letrec->applic listOfPairs body bodies))
                  )))
            ;;;;;;;;;;;;quasiqoute;;;;;;;;;;;;
            (pattern-rule
              `(quasiquote ,(? 'e) . ,(? 'expers))
              (lambda (e expers)
                (parse (expand-qq e))
                ))
            )))
    (lambda (sexpr)
      (run sexpr (lambda() "ERROR")))
    ))

; ------------------------------------------------------------------------------- Hw1
(define <boolean>
  (new (*parser (word-ci "#t"))
       (*pack
	(lambda (_) #t))

       (*parser (word-ci "#f"))
       (*pack
	(lambda (_) #f))

       (*disj 2)
       done))

(define <whitespace>
  (const
   (lambda (ch)
     (char<=? ch #\space))))

(define <line-comment>
  (let ((<end-of-line-comment>
	 (new (*parser (char #\newline))
	      (*parser <end-of-input>)
	      (*disj 2)
	      done)))
    (new (*parser (char #\;))

	 (*parser <any-char>)
	 (*parser <end-of-line-comment>)
	 *diff *star

	 (*parser <end-of-line-comment>)
	 (*caten 3)
	 done)))

(define <sexpr-comment>
  (new (*parser (word "#;"))
       (*delayed (lambda () <sexpr>))
       (*caten 2)
       done))

(define <comment>
  (disj <line-comment>
	<sexpr-comment>))

(define <skip>
  (disj <comment>
	<whitespace>))

(define ^^<wrapped>
  (lambda (<wrapper>)
    (lambda (<p>)
      (new (*parser <wrapper>)
	   (*parser <p>)
	   (*parser <wrapper>)
	   (*caten 3)
	   (*pack-with
	    (lambda (_left e _right) e))
	   done))))

(define ^<skipped*> (^^<wrapped> (star <skip>)))

(define <sexpr>
  (^<skipped*>
   (disj <boolean>
	 )))

;;;

(define add-list
  (lambda (s)
    (fold-right
     (lambda (a b) (+ a b))
     0
     s)))

(define <digit-0-9>
  (range #\0 #\9)
  )

(define <digit-1-9>
  (range #\1 #\9)
  )

(define <char-a-f>
  (range #\a #\f)
  )

(define <char-A-F>
  (range #\A #\F)
  )

(define <whitespace>
  (const
   (lambda (ch)
     (char<=? ch #\space))))

(define <Natural>
  (new (*parser <digit-0-9>) *plus
       (*pack (lambda (x)
		(string->number (list->string x))))
       done))

(define <Boolean>
  (new (*parser (word "#f"))
       (*parser (word "#F"))
       (*disj 2)
       (*pack (lambda (_) #f))
       (*parser (word "#t"))
       (*parser (word "#T"))
       (*disj 2)
       (*pack (lambda(_)  #t))
       (*disj 2)
       done))

(define <VisibleSimpleChar>
  (new (*parser (range #\! #\~))

       done))

(define ^<named-char>
  (lambda (str ch)
    (new (*parser (word str))
   (*pack (lambda (_) ch))
  done)))

(define <NamedChar>
  (new
       (*parser (^<named-char> "lambda" (integer->char 955)))
       (*parser (^<named-char> "newline" #\newline))
       (*parser (^<named-char> "nul" #\nul))
       (*parser (^<named-char> "page" #\page))
       (*parser (^<named-char> "return" #\return))
       (*parser (^<named-char> "space" #\space))
       (*parser (^<named-char> "tab" #\tab))

       (*parser (^<named-char> "LAMBDA" (integer->char 955)))
       (*parser (^<named-char> "NEWLINE" #\newline))
       (*parser (^<named-char> "NUL" #\nul))
       (*parser (^<named-char> "PAGE" #\page))
       (*parser (^<named-char> "RETURN" #\return))
       (*parser (^<named-char> "SPACE" #\space))
       (*parser (^<named-char> "TAB" #\tab))


       (*disj 14)
  done))

(define <Integer>
  (new (*parser (char #\+))
       (*parser <Natural>)
       (*caten 2)
       (*pack-with
	(lambda (++ n) n))

       (*parser (char #\-))
       (*parser <Natural>)
       (*caten 2)
       (*pack-with
	(lambda (-- n) (- n)))

       (*parser <Natural>)
       (*disj 3)
       done))

(define <Fraction>
  (new (*parser <Integer>)
       (*parser (char #\/))
       (*parser <Natural>)
       (*caten 3)
       (*pack-with
	   		(lambda (num div den)
	  			(/ num den)))
       done))

(define <Number>
	(new
		(*parser <Fraction>)
		(*parser <Integer>)
		(*disj 2)
		done))

(define <HexChar>
	(new
		(*parser <digit-0-9>)
		(*parser <char-a-f>)
                (*parser <char-A-F>)

		(*disj 3)
	done))

(define <StringHexChar>
	(new
		(*parser (char #\\))
		(*parser (char #\x))
                (*parser (char #\X))
                (*disj 2)
		(*parser <HexChar>) *star
		(*parser (char #\;))
		(*caten 4)
				(*pack-with (lambda (bs x h np)
					(integer->char (string->number (list->string `(,@h))16))))
	done))

(define <HexUnicodeChar>
  (new (*parser (char #\x))
       (*parser (char #\X))
       (*disj 2)
       (*parser <HexChar>) *plus
       (*caten 2)
			 (*pack-with (lambda (x h)
          (integer->char (string->number (list->string `(,@h))16)))
        )
  done))

(define ^<meta-char>
  (lambda (str ch)
    (new (*parser (word str))
	 (*pack (lambda (_) ch))
	done)))

(define <StringMetaChar>
	(new
         (*parser (^<meta-char> "\\t" #\tab))
         (*parser (^<meta-char> "\\T" #\tab))
         (*parser (^<meta-char> "\\f" #\page))
         (*parser (^<meta-char> "\\F" #\page))
         (*parser (^<meta-char> "\\n" #\newline))
         (*parser (^<meta-char> "\\N" #\newline))
         (*parser (^<meta-char> "\\r" #\return))
         (*parser (^<meta-char> "\\R" #\return))
         (*parser (^<meta-char> "\\\"" #\"))
         (*parser (^<meta-char> "\\" #\\))

         (*disj 10)
         done))

(define <StringLiteralChar>
  (new
      (*parser <any-char>)
      (*parser (char #\\))
      *diff
      done)
  )

(define <CharPrefix>
  (new
      (*parser (word "#\\"))
       done))

(define <Char>
  (new
      (*parser <CharPrefix>)
      (*parser <NamedChar>)
      (*parser <HexUnicodeChar>)
      (*parser <VisibleSimpleChar>)
      (*disj 3)

      (*caten 2)

      (*pack-with (lambda (pre ch)
          ch))
    done))

(define <StringChar>
  (new
      (*parser <StringHexChar>)
      (*parser <StringMetaChar>)
      (*parser <StringLiteralChar>)

      (*disj 3)

    done))

(define <String>
  (new
      (*parser (char #\"))

      (*parser <StringChar>)
      (*parser (char #\"))
      *diff
      *star
      (*pack (lambda (exp)
               (list->string exp)))


      (*parser (char #\"))
      (*caten 3)

      (*pack-with
         (lambda (open-delim chars close-delim)
               chars))
       done))

(define <SymbolChar>
  (new
      (*parser (range #\0 #\9))

      (*parser(range #\a #\z))
      (*parser(range #\A #\Z))
      (*pack (lambda (letter)
             (integer->char (+ (char->integer letter) 32))))

      (*parser (char #\!))
      (*parser (char #\$))
      (*parser (char #\^))
      (*parser (char #\*))
      (*parser (char #\-))
      (*parser (char #\_))
      (*parser (char #\=))
      (*parser (char #\+))
      (*parser (char #\<))
      (*parser (char #\>))
      (*parser (char #\?))
      (*parser (char #\/))
      (*disj 15)
     ; (*pack (lambda (letter)
          ;     (string->symbol (string letter))))
    done))

(define <Symbol>
  (new
      (*parser <SymbolChar>) *plus
      (*pack (lambda (str)
           (string->symbol (list->string str))))
     done))



(define <OnlyNumbers>
  (new
     (*parser
     (not-followed-by <Number> <Symbol>))
  done)
  )


(define <ProperList>
  (new
      (*parser (char #\())
      (*delayed (lambda () <Sexpr>) ) *star
      (*parser (char #\)))
      (*caten 3)
      (*pack-with (lambda (open lst close)
                    lst))
    done))

(define <ImproperList>
  (new
      (*parser (word "("))
      (*delayed (lambda ()  <Sexpr>)) *plus
      (*parser (word "."))
      (*delayed (lambda ()  <Sexpr>))
      (*parser (word ")"))
      (*caten 5)

      (*pack-with
         (lambda (open-delim chars-plus dot chars  close-delim)
              `(,@chars-plus . ,chars)))
    done))



(define <Quoted>
  (new
    (*parser (char #\'))
    (*delayed (lambda () <Sexpr>) )
    (*caten 2)
    (*pack-with (lambda (qu expr) (list 'quote expr)))

  done))


(define <QuasiQuoted>
  (new
    (*parser (char #\`))
    (*delayed (lambda () <Sexpr>))
    (*caten 2)
    (*pack-with (lambda(qu lst) (list 'quasiquote lst)))

  done))


(define <Unquoted>
  (new
    (*parser (char #\,))
    (*delayed (lambda () <Sexpr>) )
    (*caten 2)
    (*pack-with (lambda (qu lst) (list 'unquote lst)))
    done))

(define <UnquotedAndSpliced>
  (new
    (*parser (char #\,))
    (*parser (char #\@))
    (*delayed (lambda () <Sexpr>) )
    (*caten 3)
    (*pack-with (lambda (unq splice lst) (list 'unquote-splicing lst)))

    done))

(define <Vector>
  (new
  (*parser (char #\#))
  (*parser (char #\())
  (*delayed (lambda () <Sexpr>) ) *star
  (*parser (char #\)))
  (*caten 4)
  (*pack-with
        (lambda (asterics open-delim chars-star  close-delim)
         (list->vector chars-star)))
  done))

  (define <InfixPrefixExtenstionPrefix>
    (new
      (*parser (word "##"))
      (*parser (word "#%"))
      (*disj 2)
      done))

  (define <PowOp>
    (new
      (*parser (char #\^))
      (*parser (word "**"))
      (*disj 2)
      done))

  (define <MulDivOp>
    (new
      (*parser (char #\*))
      (*parser (char #\/))
      (*disj 2)
      done))

  (define <AddSubOp>
    (new
      (*parser (char #\+))
      (*parser (char #\-))
      (*disj 2)
      done))


;;------------------------------------------------------------------------------------------
;;---------------------------  InfixAddSub --------------------------- ---------------------
;;------------------------------------------------------------------------------------------
;;------------------------------------------------------------------------------------------

  (define <InfixAddSub>
    (^<skipped*>
      (new
        (*delayed (lambda () <InfixMulDiv>))

        (*parser <AddSubOp>)
        (*delayed (lambda () <InfixMulDiv>))
        (*caten 2)
       (*pack-with
         (lambda (sign rest)
            (lambda (first)
              `(,(string->symbol (string sign)) ,first ,rest)
            )))

        *star
        (*caten 2)
       (*pack-with (lambda (first lambda_rest)
              (fold-left (lambda (op elem)
                              (elem op)) first lambda_rest)
            ))
      done)))

;;------------------------------------------------------------------------------------------
;;---------------------------  InfixMulDiv --------------------------- ---------------------
;;------------------------------------------------------------------------------------------
;;------------------------------------------------------------------------------------------

  (define <InfixMulDiv>
    (^<skipped*>
      (new
        (*delayed (lambda () <InfixNeg>))
        (*parser <MulDivOp>)
        (*delayed (lambda () <InfixNeg>))
        (*caten 2)

       (*pack-with
         (lambda (sign rest)
            (lambda (first)
              `(,(string->symbol (string sign)) ,first ,rest)
            )))

        *star
        (*caten 2)
        (*pack-with (lambda (first lambda_rest)
              (fold-left (lambda (op elem)
                              (elem op)) first lambda_rest)
            ))
        done)))

;;---------------------------------------------------------------------------------------
;;---------------------------  InfixPow --------------------------- ---------------------
;;---------------------------------------------------------------------------------------



(define <InfixNeg>
	(^<skipped*>
	(new
		(*delayed (lambda () <InfixPow>))
			(*parser (char #\-))
		(*delayed (lambda () <InfixPow>))
		(*caten 2)
		(*pack-with (lambda (op exp) `(-,exp)))

        (*disj 2)

        done)))




  (define <InfixPow>
    (^<skipped*>
      (new
        (*delayed (lambda () <InfixFuncall>))
        (*parser <PowOp>)
        (*caten 2)
         (*pack-with
           (lambda (rest sign)
              (lambda (first)
                `(expt ,rest ,first )
              )))
        *star
        (*delayed (lambda () <InfixFuncall>));
       (*caten 2)
       (*pack-with (lambda (lst last)
                (fold-right  (lambda (op elem)
                                (op elem)) last lst)
              ))
       done)))


;;------------------------------------------------------------------------------------------
;;------------------------------------------------------------------------------------------
;;------------------------------------------------------------------------------------------



   (define <InfixFuncall>
        (new
          (*delayed (lambda () <InfixArrayGet>))

          ;----------- ("(" <InfixArrayGet> ( "," <InfixArrayGet>)* ")")*---------------
          (*parser (char #\())

          ;----------------<InfixArgList>-------------------
          (*delayed (lambda () <InfixExpression>))

          (*parser (char #\,))
          (*delayed (lambda () <InfixExpression>))
          (*caten 2)
          (*pack-with (lambda (comma exp)
                        exp))
          *star
          (*caten 2)
          (*pack-with (lambda (first-arg args-list)
                      (cons first-arg args-list)))
          (*parser <epsilon>)
          (*disj 2)
          ;----------------<InfixArgList>-------------------

          (*parser (char #\)))
          (*caten 3)
          (*pack-with (lambda (open args close)
                         (lambda (func)
                          `(,func ,@args)
                            )))
          *star
          ;-----------("(" <InfixArrayGet> ( "," <InfixArrayGet>)* ")")*---------------

          (*caten 2)
          (*pack-with (lambda (arr lst)
                        (fold-left (lambda (a func)
                                           (func a)) arr lst)
                        ))

          done))




      (define <InfixArrayGet>
        (new
          (*delayed (lambda () <InfixFuncall2>))

          ;-----------( "[" <End> "]" )*------------
          (*parser (char #\[))
          (*delayed (lambda () <InfixExpression>))
          (*parser (char #\]))
          (*caten 3)
          (*pack-with (lambda (open pos close)
                        (lambda (arr)
                          `(vector-ref ,arr ,pos))
                          ))
          *star
          ;-----------( "[" <End> "]" )*------------

         (*caten 2)
         (*pack-with (lambda (arr lst)
                        (fold-left (lambda (a func)
                                            (func a)) arr lst)
                        ))

       done))



    (define <InfixFuncall2>
        (new
          (*delayed (lambda () <End>))

          ;----------- ("(" <InfixArrayGet> ( "," <InfixArrayGet>)* ")")*---------------
          (*parser (char #\())

          ;----------------<InfixArgList>-------------------
          (*delayed (lambda () <InfixExpression>))

          (*parser (char #\,))
          (*delayed (lambda () <InfixExpression>))
          (*caten 2)
          (*pack-with (lambda (comma exp)
                        exp))
          *star
          (*caten 2)
          (*pack-with (lambda (first-arg args-list)
                      (cons first-arg args-list)))
          (*parser <epsilon>)
          (*disj 2)
          ;----------------<InfixArgList>-------------------

          (*parser (char #\)))
          (*caten 3)
          (*pack-with (lambda (open args close)
                         (lambda (func)
                          `(,func ,@args)
                            )))
          *star
          ;-----------("(" <InfixArrayGet> ( "," <InfixArrayGet>)* ")")*---------------

          (*caten 2)
          (*pack-with (lambda (arr lst)
                        (fold-left (lambda (a func)
                                           (func a)) arr lst)
                        ))

          done))


;;------------------------------------------------------------------------------------------
;;---------------------------  InfixParen --------------------------- ---------------------
;;------------------------------------------------------------------------------------------
;;------------------------------------------------------------------------------------------

  (define <InfixParen>
    (new
      (*parser (char #\())
      (*delayed (lambda () <InfixExpression>))
      (*parser (char #\)))
      (*caten 3)
      (*pack-with (lambda (open exp close)
        exp
          ))
      done))

;;------------------------------------------------------------------------------------------
;;---------------------------  InfixNeg --------------------------- ---------------------
;;------------------------------------------------------------------------------------------
;;------------------------------------------------------------------------------------------


  (define <NotInfixSymbol>
    (new
      (*parser (char #\+))
      (*parser (char #\-))
      (*parser (char #\*))
      (*parser (char #\^))
      (*parser (char #\/))
      (*parser (word "**"))

      (*disj 6)
      done))

  (define <InfixSymbol>
    (new
      (*parser <SymbolChar>)
      (*parser <NotInfixSymbol>)
      *diff
      *plus
      (*pack (lambda (lst)
              (string->symbol  (list->string  lst))))

    done))

  (define <InfixSexprEscape>
        (new
          (*parser <InfixPrefixExtenstionPrefix>)
          (*delayed (lambda () <Sexpr>))
          (*caten 2)
          (*pack-with (lambda (ext exp)
            exp
            ))
          done))

  (define <InfixNum>
      (new (*parser <Fraction>)
           (*parser <Integer> )
           (*parser <SymbolChar>)
           (*parser <digit-0-9>)
           *diff
           *not-followed-by
           (*disj 2)
           done))

  (define <End>
    (^<skipped*>
      (new
        (*parser <InfixParen>)
        (*parser <InfixSexprEscape>)
        (*parser <Number>)
        (*parser <InfixSymbol>)

        (*disj 4)

    done)))


  (define <InfixExpression>
   (^<skipped*>
    (new
      (*parser <InfixAddSub>)
    done)
    ))

  (define <InfixExtention>
    (new
      (*parser <InfixPrefixExtenstionPrefix>)
      (*parser <InfixExpression>)
      (*caten 2)
      (*pack-with (lambda (x y) y ))
      done))

(define <Sexpr>
(^<skipped*>
  (new
      (*parser <InfixExtention>)

      (*parser <Boolean>)
      (*parser <Char>)
      (*parser <String>)
      (*parser <OnlyNumbers>)
      (*parser <Symbol>)
      (*parser <ProperList>)
      (*parser <ImproperList>)
      (*parser <Vector>)
      (*parser <Quoted>)
      (*parser <QuasiQuoted>)
      (*parser <Unquoted>)
      (*parser <UnquotedAndSpliced>)
      (*disj 13)

     ; (*parser <InfixExtention>)
     ; (*caten 2)


   done)


  ))
