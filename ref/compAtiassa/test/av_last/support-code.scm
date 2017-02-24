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

(define +
 (letrec ((loop
	    (lambda (s)
	      (if (null? s)
		  0
		  (bin+ (car s)
			(loop (cdr s)))))))
   (lambda s (loop s))))
   


(define -
  (lambda (a . s)
    (if (null? s)
	(bin- 0 a)
	(bin- a (apply + s)))))



