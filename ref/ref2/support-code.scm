;;; support-code.scm
;;;
;;; Part of the initial environment that you will need to provide with
;;; your compiler, but written in [very elementary] Scheme. Put
;;; otherwise, your compiler will have to be able to compile this code
;;; in order to provide it.
;;;
;;; Programmer: Mayer Goldberg, 2012

;;; the following should be re-implemented in cisc assembly:
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
	  
(define map
  ((lambda (y) 
     ((lambda (map1) 
	((lambda (maplist) 
	   (lambda (f . s) 
	     (maplist f s))) 
	 (y (lambda (maplist) 
	      (lambda (f s) 
		(if (null? (car s)) '() 
		    (cons (apply f (map1 car s)) 
			  (maplist f (map1 cdr s))))))))) 
      (y (lambda (map1) 
	   (lambda (f s) 
	     (if (null? s) '() 
		 (cons (f (car s)) 
		       (map1 f (cdr s))))))))) 
   (lambda (f) 
     ((lambda (x) 
	(f (lambda (y z)
	     ((x x) y z))))
      (lambda (x) 
	(f (lambda (y z)
	     ((x x) y z))))))))
