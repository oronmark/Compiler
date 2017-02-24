(define dyn1 (string->symbol (make-string 3 #\a)))
(define dyn2 (string->symbol (make-string 3 #\a)))
(define dyn3 (string->symbol (make-string 3 #\a)))
(and (eq? dyn1 dyn2) (eq? dyn2 dyn3) (eq? dyn1 dyn3))