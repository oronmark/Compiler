(define <
	(lambda s
		(letrec ((run (lambda (args curr)
						(if (null? args)
							#t
							(and (oron/binary< curr (car args)) (run (cdr args) (car args)))))))
			(run (cdr s) (car s)))))

(< 1)
