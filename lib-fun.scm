(define /
	(lambda (first . rest )
		(if (null? rest)
			(oron/binary-div 1 first)
			(letrec ((run (lambda (s)
								(if (null? s)
									1
									(oron/binary-div (run (cdr s)) (car s))))))
			 (run (cons first rest))))))



(define map
	(lambda (foo lst)
		(if (null? lst)
			lst
			(cons (foo (car lst)) (map foo (cdr lst))))))


(define append
  (letrec ((app2
	    (lambda (s1 s2)
	      (if (null? s1) s2
		  (cons (car s1)
		   (app2 (cdr s1) s2)))))
	   (appl
	    (lambda (s1 s)
	      (if (null? s) s1
		  (app2 s1 (appl (car s) (cdr s)))))))
    (lambda s
      (if (null? s) '()
	  (appl (car s) (cdr s))))))



(define +
	(lambda s
		(letrec ((run (lambda (args)
						(if (null? args)
							0
							(oron/binary-add (car args) (run (cdr args)))))))
			(run s))))

