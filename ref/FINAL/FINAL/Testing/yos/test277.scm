
(define always-zero
  (letrec ((the-result-is-zero
	      (lambda (n) (if (< n 0) 0 (does-nothing (- n 1)))))
	   (does-nothing (lambda (x) (the-result-is-zero x))))
	the-result-is-zero))

(always-zero 6) 
