(define dyn1 (string->symbol (make-string 3 #\a)))
(define dyn2 (string->symbol (make-string 3 #\a)))
(define stat2 'aaa)
(and (eq? dyn1 dyn2) (eq? dyn1 stat2) (eq? stat2 dyn2))