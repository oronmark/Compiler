(define dyn1 (string->symbol (make-string 3 #\a)))
(define dyn2 (string->symbol (make-string 3 #\a)))
(define fw (string->symbol (symbol->string 'aaa)))
(and (eq? dyn1 dyn2) (eq? dyn1 fw) (eq? fw dyn2))