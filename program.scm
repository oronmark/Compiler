(define +
	(lambda s
		(letrec ((run (lambda (args)
						(if (null? args)
							0
							(oron/binary-add (car args) (run (cdr args)))))))
			(run s))))


(+ 1 2/15 -3/11 114 -5/29 34)