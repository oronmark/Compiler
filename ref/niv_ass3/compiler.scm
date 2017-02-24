 

(include "pc.scm")

(define run-all
  (lambda (expr)
    (annotate-tc 
      (pe->lex-pe 
        (box-set 
          (remove-applic-lambda-nil 
            (eliminate-nested-defines(parse expr))))))))


(define <whitespace>
  (const
   (lambda(ch)
     (char<=? ch #\space))))
(define UseMiddle (*pack-with(lambda (x y z) y)))
(define UseSecond (*pack-with(lambda (x y) y)))

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
       (*delayed (lambda()<Sexpr>))
       (*caten 2)
       done))

(define <comment>
  (disj <line-comment>
        <sexpr-comment>))

(define <skip>
  (disj <comment>
        <whitespace>))

(define ^^<wrapped>
  (lambda(<wrapper>)
    (lambda(<p>)
      (new (*parser <wrapper>)
           (*parser <p>)
           (*parser <wrapper>)
           (*caten 3)
           (*pack-with
            (lambda(_left e _right)e))
           done))))

(define ^<skipped*> (^^<wrapped> (star <skip>)))

(define ^<named-char>
  (lambda(name chr)
    (new (*parser (word name))
         (*pack (lambda(_)chr))
         done)))

(define <NamedChar>
  (new (*parser (^<named-char> "lambda" (integer->char 955)))
       (*parser (^<named-char> "LAMBDA" (integer->char 955)))
       (*parser (^<named-char> "newline" #\newline))
       (*parser (^<named-char> "NEWLINE" #\newline))
       (*parser (^<named-char> "nul" #\nul))
       (*parser (^<named-char> "NUL" #\nul))
       (*parser (^<named-char> "page" #\page))
       (*parser (^<named-char> "PAGE" #\page))
       (*parser (^<named-char> "return" #\return))
       (*parser (^<named-char> "RETURN" #\return))
       (*parser (^<named-char> "space" #\space))
       (*parser (^<named-char> "SPACE" #\space))
       (*parser (^<named-char> "tab" #\tab))
       (*parser (^<named-char> "TAB" #\tab))
       
       (*disj 14)
       done))

(define <digit-0-9>
  (range #\0 #\9))

(define <digit-1-9>
  (range #\1 #\9))

(define <a-f>
  (range #\a #\f))

(define <Natural>
  (new (*parser (char #\0))*star
       (*parser <digit-1-9>)
       (*parser <digit-0-9>)*star
       (*caten 3)
       (*pack-with
        (lambda(zeros a s)
          (string->number
           (list->string
            `(,a,@s)))))
       
       (*parser (char #\0))*plus
       (*pack (lambda(zeros)0))
       
       (*disj 2)
       done))

(define <Boolean>
  (new (*parser (word "#T"))
       (*parser (word "#t"))
       (*disj 2)
       (*pack (lambda(true)#t))
       
       (*parser (word "#F"))
       (*parser (word "#f"))
       (*disj 2)
       (*pack (lambda(false) #f))
       
       (*disj 2)
       done))

(define <Integer>
  (new (*parser (char #\+))
       (*parser <Natural>)
       (*caten 2)
       UseSecond
       
       (*parser (char #\-))
       (*parser <Natural>)
       (*caten 2)
       (*pack-with (lambda(-- n)(- n)))
       (*parser <Natural>)
       
       (*disj 3)
       done))

(define <Fraction>
  (new (*parser <Integer>)
       (*parser (char #\/))
       (*parser <Natural>)
       (*guard (lambda(n)(not (zero? n))))
       (*caten 3)
       (*pack-with (lambda(num div den) (/ num den)))
       done))

(define <HexChar>
  (new (*parser <digit-0-9>)
       (*parser <a-f>)
       (*disj 2)
       done))

(define HexGuard (*guard (lambda(hex)(> 110000 (string->number (list->string `(,@hex))16)))))

(define <StringHexChar>
  (new (*parser (char #\\))
       
       (*parser (char #\x))
       (*parser (char #\X))
       (*disj 2)
       
       (*parser <HexChar>)*star
       HexGuard
       
       (*parser (char #\;))
       (*caten 4)
       (*pack-with (lambda(slash x hex np)
                     (integer->char (string->number (list->string `(,@hex))16))))
       done))

(define <HexUnicodeChar>
  (new (*parser (char #\x))
       (*parser (char #\X))
       (*disj 2)
       (*parser <HexChar>)*plus
       HexGuard
       (*caten 2)
       (*pack-with (lambda(x hex)
                     (integer->char (string->number (list->string `(,@hex))16))))
       done))

(define ^<meta-char>
  (lambda(str ch)
    (new (*parser (word str))
         (*pack (lambda(_)ch))
         done)))

(define <StringMetaChar>
  (new (*parser (^<meta-char> "\\\\" #\\))
       (*parser (^<meta-char> "\\\"" #\"))
       (*parser (^<meta-char> "\\n" #\newline))
       (*parser (^<meta-char> "\\N" #\newline))
       (*parser (^<meta-char> "\\r" #\return))
       (*parser (^<meta-char> "\\R" #\return))
       (*parser (^<meta-char> "\\t" #\tab))
       (*parser (^<meta-char> "\\T" #\tab))
       (*parser (^<meta-char> "\\f" #\page))
       (*parser (^<meta-char> "\\F" #\page))
       (*disj 10)
       done))

(define <StringLiteralChar>
  (new (*parser <any-char>)
       (*parser (char #\\))
       *diff
       done))

(define <CharPrefix>
  (new (*parser (char #\#))
       (*parser (char #\\))
       (*caten 2)
       done))

(define <VisibleSimpleChar>
  (new (*parser (range #\! #\~))
       done))

(define <Char>
  (new (*parser <CharPrefix>)
       
       (*parser <NamedChar>)
       (*parser <HexUnicodeChar>)
       (*parser <VisibleSimpleChar>)
       (*disj 3)
       
       (*caten 2)
       UseSecond
       done))

(define <StringChar>
  (new (*parser <StringLiteralChar>)
       (*parser <StringMetaChar>)
       (*parser <StringHexChar>)
       (*disj 3)
       done))

(define <String>
  (new (*parser (char #\"))
       
       (*parser <StringChar>)
       (*parser (char #\"))
       *diff
       *star
       (*pack (lambda(StringChars)
                (list->string StringChars)))
       (*parser (char #\"))
       (*caten 3)
       UseMiddle
       done))

(define <x-helper>
  (range #\x #\x))

(define <SymbolChar>
  (new (*parser(range #\0 #\9))
       (*parser(range #\a #\z))
       (*parser(range #\A #\Z))
       (*pack (lambda(AZ)
                (integer->char(+ 32 (char->integer AZ)))))
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
       done))

(define <Number>
  (new (*parser <Fraction>)
       (*parser <Integer>)
       
       (*disj 2)
       done))

(define <Symbol>
  (new (*parser <SymbolChar>)*plus
       (*pack (lambda(SymbolChars)
                (string->symbol (list->string SymbolChars))))
       done))

(define <JustNumbers>
  (new (*parser
        (not-followed-by <Number> <Symbol>))
       done))

(define <ProperList>
  (new (*parser (char #\())
       (*delayed (lambda()<Sexpr>))*star
       (*parser (char #\)))
       (*caten 3)
       UseMiddle
       done))

(define <ImproperList>
  (new (*parser (char #\())
       (*delayed (lambda() <Sexpr>))*plus
       (*parser (char #\.))
       (*delayed (lambda() <Sexpr>))
       (*parser (char #\)))
       
       (*caten 5)
       
       (*pack-with
        (lambda(open Sexprplus dot Sexpr close)
          `(,@Sexprplus .,Sexpr)))
       done))

(define <Quoted>
  (new (*parser (char #\'))
       (*parser <whitespace>)*star
       (*delayed (lambda()<Sexpr>))
       (*parser <whitespace>)*star
       (*caten 4)
       (*pack-with (lambda(open spaces1 exp spaces2)(list 'quote exp)))
       done))

(define <QuasiQuoted>
  (new (*parser (char #\`))
       (*parser <whitespace>)*star
       (*delayed (lambda()<Sexpr>))
       (*parser <whitespace>)*star
       (*caten 4)
       (*pack-with (lambda(open spaces1 exp spaces2)(list 'quasiquote exp)))
       done))

(define <Unquoted>
  (new (*parser (char #\,))
       (*parser <whitespace>)*star
       (*delayed (lambda()<Sexpr>))
       (*parser <whitespace>)*star
       (*caten 4)
       (*pack-with (lambda(open spaces1 exp spaces2)(list 'unquote exp)))
       done))

(define <UnquotedAndSpliced>
  (new (*parser (word ",@"))
       (*parser <whitespace>)*star
       (*delayed (lambda()<Sexpr>))
       (*parser <whitespace>)*star
       (*caten 4)
       (*pack-with (lambda(openshtrudel spaces1 exp spaces2)(list 'unquote-splicing exp)))
       
       done))

(define <Vector>
  (new (*parser (char #\#))
       (*parser (char #\())
       (*delayed (lambda()<Sexpr>))*star
       (*parser (char #\)))
       (*caten 4)
       (*pack-with
        (lambda(sul open Sexpr close)
          (list->vector Sexpr)))
       done))

(define <InfixPrefixExtenstionPrefix>
  (new (*parser (char #\#))
       
       (*parser (char #\#))
       (*parser (char #\%))
       (*disj 2)
       (*caten 2)
       done))

(define <PowerSymbol> 
  (new (*parser (char #\^))
       (*parser (word "**"))
       (*disj 2)
       done))

(define <AddSubOp>
  (new (*parser (char #\+))
       (*parser (char #\-))
       (*disj 2)
       done))

(define <MulDivOp>
  (new (*parser (char #\/))
       (*parser (char #\*))
       (*disj 2)
       done))

(define <operators>
  (new (*parser <AddSubOp>)
       (*parser <MulDivOp>)
       (*parser <PowerSymbol>)
       (*parser (word "#"))
       (*disj 4)
       done))

(define InfixArrange (*pack-with(lambda(op expr2)
                                  (lambda(expr1)
                                    `(,(string->symbol (string op)),expr1,expr2)))))

(define InfixLeftFoldOpPack
  (*pack-with (lambda(first rest)
                (fold-left (lambda(operator element)
                             (element operator))first rest))))

(define <InfixAddSub>
  
  (new (*delayed (lambda()<InfixMulDiv>))
       (*parser <AddSubOp>)
       (*delayed (lambda()<InfixMulDiv>))
       (*caten 2)
       InfixArrange
       *star
       (*caten 2)
       InfixLeftFoldOpPack
       done))

(define <InfixMulDiv>
  (new (*delayed (lambda()<InfixNeg>))
       (*parser <MulDivOp>)
       (*delayed (lambda()<InfixNeg>))
       (*caten 2)
       InfixArrange
       *star
       (*caten 2)
       InfixLeftFoldOpPack
       done))

(define <InfixNeg>
  (new (*delayed (lambda()<InfixPow>))
       
       (*parser (char #\-))
       (*delayed (lambda()<InfixPow>))
       (*caten 2)
       (*pack-with (lambda(-- exp)`(-,exp)))
       (*disj 2)
       done))

(define <InfixPow>
  (new (*delayed (lambda()<InfixFuncall>))
       (*parser <PowerSymbol>)
       (*caten 2)
       (*pack-with (lambda(base PowerSymbol)
                     (lambda(exp)
                       `(expt,base,exp))))
       *star
       
       (*delayed (lambda()<InfixFuncall>))
       (*caten 2)
       
       (*pack-with (lambda(first rest)
                     (fold-right  (lambda(operator element)
                                    (operator element))rest first)))
       done))
;
(define <InfixArgs>
  (new (*parser (char #\())
       
       (*parser <whitespace>)*star
       
       (*delayed (lambda()<InfixExpression>))
       
       (*parser (char #\,))
       (*delayed (lambda()<InfixExpression>))
       (*caten 2)
       UseSecond
       *star
       
       (*caten 2)
       (*pack-with cons)
       (*parser <epsilon>)
       (*disj 2)
       
       (*parser <whitespace>)*star
       
       (*parser (char #\)))
       (*caten 5)
       (*pack-with (lambda(open space1 args space2 close)
                     (lambda(func)
                       `(,func,@args))))
       *star
       done))
;
(define <InfixFuncall>
  (new  (*delayed (lambda()<InfixArrayGet>))
        (*parser <InfixArgs>)
        (*caten 2)
        InfixLeftFoldOpPack
        done))
;
(define <InfixFuncall2>
  (^<skipped*>
   (new  (*delayed (lambda()<Atomic>))
         (*parser <InfixArgs>)
         (*caten 2)
         InfixLeftFoldOpPack
         done)))
;
(define <InfixArrayGet>
  (^<skipped*>
   (new (*delayed (lambda()<InfixFuncall2>))
        
        (*parser (char #\[))
        (*delayed (lambda()<InfixExpression>))
        (*parser (char #\]))
        (*caten 3)
        (*pack-with (lambda(open index close)
                      (lambda(array)
                        `(vector-ref,array,index))))
        *star
        
        (*caten 2)
        InfixLeftFoldOpPack
        done)))
;
(define <InfixParen>
  (new (*parser (char #\())
       (*delayed (lambda()<InfixExpression>))
       (*parser (char #\)))
       (*caten 3)
       UseMiddle
       done))
;
(define <InfixSymbol>
  (new (*parser <SymbolChar>)
       (*parser <operators>)
       *diff
       *plus
       (*pack (lambda(Symbols)
                (string->symbol (list->string Symbols))))
       done))
;
(define <InfixSexprEscape>
  (new (*parser <InfixPrefixExtenstionPrefix>)
       (*delayed (lambda()<Sexpr>))
       (*caten 2)
       UseSecond
       done))
;
(define <InfixExpression>
  (^<skipped*>
   (new (*parser <InfixAddSub>)
        done)))
;
(define <InfixExtention>
  (new (*parser <InfixPrefixExtenstionPrefix>)
       (*parser <InfixExpression>)
       (*caten 2)
       UseSecond
       done))
;
(define <Atomic>
  (new (*parser <InfixSexprEscape>)
       (*parser <InfixParen>)
       
       (*parser <Number>)
       (*parser <InfixSymbol>)
       
       (*disj 4)
       
       done))
;
(define <Sexpr>
  (^<skipped*>
   (new (*parser <InfixExtention>)
        (*parser <JustNumbers>)
        (*parser <Boolean>)
        (*parser <Vector>)
        (*parser <Char>)
        (*parser <String>)
        (*parser <Symbol>)
        (*parser <ProperList>)
        (*parser <ImproperList>)
        (*parser <Quoted>)
        (*parser <QuasiQuoted>)
        (*parser <Unquoted>)
        (*parser <UnquotedAndSpliced>)
        
        (*disj 13)
        done)))
;=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@;
;=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@;
;=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@;
;=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@;
;=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@=@;
(load "pattern-matcher.scm")
; make quote, Mayer Goldberg code given to us
(define ^quote?
  (lambda (tag)
    (lambda (e)
      (and (pair? e)
           (eq? (car e) tag)
           (pair? (cdr e))
           (null? (cddr e))))))
;Mayer Goldberg code given to us
(define quote? (^quote? 'quote))
;Mayer Goldberg code given to us
(define unquote? (^quote? 'unquote))
;Mayer Goldberg code given to us
(define unquote-splicing? (^quote? 'unquote-splicing))
;Mayer Goldberg code given to us
(define const?
  (let ((simple-sexprs-predicates
         (list boolean? char? number? string?)))
    (lambda (e)
      (or (ormap (lambda (p?) (p? e))
                 simple-sexprs-predicates)
          (quote? e)))))
;Mayer Goldberg code given to us
(define quotify
  (lambda (e)
    (if (or (null? e)
            (pair? e)
            (symbol? e)
            (vector? e))
        `',e
        e)))
;Mayer Goldberg code given to us
(define unquotify
  (lambda (e)
    (if (quote? e)
        (cadr e)
        e)))
;Mayer Goldberg code given to us
(define const-pair?
  (lambda (e)
    (and (quote? e)
         (pair? (cadr e)))))
;Mayer Goldberg code given to us
(define expand-qq
  (letrec ((expand-qq
            (lambda (e)
              (cond ((unquote? e) (cadr e))
                    ((unquote-splicing? e)
                     (error 'expand-qq
                            "unquote-splicing here makes no sense!"))
                    ((pair? e)
                     (let ((a (car e))
                           (b (cdr e)))
                       (cond ((unquote-splicing? a)
                              `(append ,(cadr a) ,(expand-qq b)))
                             ((unquote-splicing? b)
                              `(cons ,(expand-qq a) ,(cadr b)))
                             (else `(cons ,(expand-qq a) ,(expand-qq b))))))
                    ((vector? e) `(list->vector ,(expand-qq (vector->list e))))
                    ((or (null? e) (symbol? e)) `',e)
                    (else e))))
           (optimize-qq-expansion (lambda (e) (optimizer e (lambda () e))))
           (optimizer
            (compose-patterns
             (pattern-rule
              `(append ,(? 'e) '())
              (lambda (e) (optimize-qq-expansion e)))
             (pattern-rule
              `(append ,(? 'c1 const-pair?) (cons ,(? 'c2 const?) ,(? 'e)))
              (lambda (c1 c2 e)
                (let ((c (quotify `(,@(unquotify c1) ,(unquotify c2))))
                      (e (optimize-qq-expansion e)))
                  (optimize-qq-expansion `(append ,c ,e)))))
             (pattern-rule
              `(append ,(? 'c1 const-pair?) ,(? 'c2 const-pair?))
              (lambda (c1 c2)
                (let ((c (quotify (append (unquotify c1) (unquotify c2)))))
                  c)))
             (pattern-rule
              `(append ,(? 'e1) ,(? 'e2))
              (lambda (e1 e2)
                (let ((e1 (optimize-qq-expansion e1))
                      (e2 (optimize-qq-expansion e2)))
                  `(append ,e1 ,e2))))
             (pattern-rule
              `(cons ,(? 'c1 const?) (cons ,(? 'c2 const?) ,(? 'e)))
              (lambda (c1 c2 e)
                (let ((c (quotify (list (unquotify c1) (unquotify c2))))
                      (e (optimize-qq-expansion e)))
                  (optimize-qq-expansion `(append ,c ,e)))))
             (pattern-rule
              `(cons ,(? 'e1) ,(? 'e2))
              (lambda (e1 e2)
                (let ((e1 (optimize-qq-expansion e1))
                      (e2 (optimize-qq-expansion e2)))
                  (if (and (const? e1) (const? e2))
                      (quotify (cons (unquotify e1) (unquotify e2)))
                      `(cons ,e1 ,e2))))))))
    (lambda (e)
      (optimize-qq-expansion
       (expand-qq e)))))
;
(define let-list?
  (lambda (lst)
    (and (list? lst)
         (not (null? lst))
         (andmap (lambda (assignment)
                   (and (list-length>=2? assignment)
                        (is-var? (car assignment))
                        (null? (cddr assignment))))
                 lst))))
; check that the list have atlist 2 nodes
(define list-length>=2?
  (lambda (value)
    (and (list? value)
         (not (null? value))
         (not (null? (cdr value))))))
;
(define split-car-cadr
  (lambda (lst)
    (if (let-list? lst)
        (list (map car lst) (map cadr lst))
        #f)))

;code given to us in hw2 3.1.2
(define *reserved-words*
  '(and begin cond define do else if lambda
        let let* letrec or quasiquote unquote 
        unquote-splicing quote set!))
;check if input is reserved or not by using ormap on all list
(define is-reserved?
  (lambda (input)
    (ormap (lambda (word) (eq? word input))
           *reserved-words*)))
;not on is-reserved function
(define not-reserved?
  (lambda (sym)
    (not (is-reserved? sym))))
;check if input is a varible should not be a symbol not reserved and not cost 3.1.2
(define is-var?
  (lambda (input)
    (and (not (const? input))
         (not (is-reserved? input))
         (symbol? input)
         )))
;return (#void)
(define elseDoNothing (void)) 
;check if list of variables are all viarbale or null list 
(define is-vars?
  (lambda (lst)
    (and (list? lst)
         (or (null? lst)
             (andmap is-var? lst)))))
;parse begin statement
(define parse-begin
  (lambda (lst)
    (if (null? (cdr lst))
        (car lst)
        `(begin ,@lst))))   
;cps function to extract variables from optional arguments lambda        
(define extract-opt-vars
  (lambda (val)
    (letrec ((f (lambda (lst cont fail)
                  (if (and (is-var? (car lst)) (pair? lst))
                      (if (pair? (cdr lst))
                          (f (cdr lst)
                             (lambda (args rest)
                               (cont (cons (car lst) args) rest))
                             fail)
                          (if (is-var? (cdr lst))
                              (cont (list (car lst)) (cdr lst))
                              (fail)))
                      (fail)))))
      (if (is-var? val) (list (list) val)
          (f val
             (lambda (args rest) (list args rest))
             (lambda () #f))))))
;save lines in code helper function . 
(define parseOneThing 
  (lambda (input)
    (parse input)))
;help for parse begin statement .
(define one-begin
  (lambda (expr)
    (cond ((null? expr) (list))
          ((not (pair? (car expr))) (cons (car expr) (one-begin (cdr expr))))
          ((eq? (caar expr) 'begin) (append (one-begin (cdr (car expr))) (one-begin (cdr expr))))
          (else (cons (car expr) (one-begin (cdr expr)))))))
;our main parser function .
(define parse
  ( let ((run
          ( compose-patterns
            ;3.1.1 quote?.
            (pattern-rule
             `(quote ,(? 'c))
             (lambda (c) `(const ,c)))
            ;3.1.1 const?.
            (pattern-rule
             (? 'c const?)
             (lambda (c) `(const ,c)))
            ;3.1.2 var?.
            (pattern-rule
             (? 'v is-var?)
             (lambda (v) `(var ,v)))
            ;3.1.3 if without alternative path.
            (pattern-rule
             `(if ,(? 'test) ,(? 'dit))
             (lambda (test dit)
               `(if3 ,(parse test) ,(parse dit) (const ,elseDoNothing))))
            ;3.1.3 if with alternative path.
            (pattern-rule
             `(if ,(? 'test) ,(? 'dit) ,(? 'dif))
             (lambda (test dit dif)
               `(if3 ,(parse test) ,(parse dit) ,(parse dif))))
            
            ;3.1.4 Disjunctions or: empty
            (pattern-rule
             `(or)
             (lambda ()
               `,(parse #f)))
            ; 3.1.4 Disjunctions
            (pattern-rule
             `(or ,(? 'expr))
             parseOneThing)
            ;3.1.4 Disjunctions
            (pattern-rule 
             `(or ,(? 'first) . ,(? 'others))
             (lambda (first others) 
               (if (null? others) 
                   (parse first) 
                   `(or ,(map parse (cons first others)))))) 
            ; 3.1.4 Disjunctions
            (pattern-rule
             `(and)
             (lambda ()
               `,(parse #t)))
            ; 3.1.4 Disjunctions
            (pattern-rule
             `(and ,(? 'expr))
             parseOneThing)
            ; 3.1.4 Disjunctions
            (pattern-rule
             `(and ,(? 'first) ,(? 'second) . ,(? 'rest list?))
             (lambda (first second rest)
               (parse `(if ,first (and ,second . ,rest) #f)))) 
            ;
            (pattern-rule
             `(begin)
             (lambda () `(const ,(void))))
            ; 3.1.5 Lambda forms sequence
            (pattern-rule
             `(begin ,(? 'expr ) . ,(? 'exprs null?))
             (lambda (expr exprs);
               (parse expr)))
            (pattern-rule
             `(begin . ,(? 'expers))
             (lambda (expers)
               `(seq ,(map parse (one-begin expers)))))
            ; 3.1.5 Lambda forms simple lambda
            (pattern-rule
             `(lambda ,(? 'vars is-vars?) ,(? 'expr) . ,(? 'exprs list?))
             (lambda (vars expr exprs)
               `(lambda-simple ,vars ,(parse (parse-begin `(,expr . ,exprs))))))
            ; 3.1.5 Lambda forms optional arguments lambda
            (pattern-rule
             `(lambda (,(? 'var is-var?) . ,extract-opt-vars) ,(? 'expr) . ,(? 'exprs list?))
             (lambda (var vars opts expr exprs)
               `(lambda-opt ,(cons var vars) ,opts ,(parse (parse-begin `(,expr . ,exprs))))))
            ;3.1.5 Lambda forms variadic lambda
            (pattern-rule
             `(lambda ,(? 'vars is-var?) ,(? 'expr) . ,(? 'exprs list?))
             (lambda (vars expr exprs)
               `(lambda-var ,vars ,(parse (parse-begin `(,expr . ,exprs))))))
            ;3.1.6 Define
            (pattern-rule
             `(define ,(? 'var is-var?) ,(? 'expr))
             (lambda (var expr)
               `(def ,(parse var) ,(parse expr))))
            ; 3.1.6 MIT-style define (for procedures)
            (pattern-rule
             `(define (,(? 'var is-var?) . ,(? 'vars)) ,(? 'expr) . ,(? 'exprs list?))
             (lambda (var vars expr exprs)
               (parse `(define ,var (lambda ,vars ,expr . ,exprs)))))
            ; 3.1.7 Assignment
            (pattern-rule
             `(set! ,(? 'var is-var?) ,(? 'value))
             (lambda (var value)
               `(set ,(parse var) ,(parse value))))
            ; 3.1.8 Applications
            (pattern-rule
             `(,(? 'proc not-reserved?) . ,(? 'exprs))
             (lambda (proc exprs)
               `(applic ,(parse proc) ,(map parse exprs))))
            ; let: empty - to application
            (pattern-rule
             `(let () ,(? 'expr) . ,(? 'exprs list?))
             (lambda (expr exprs)
               (parse `((lambda () ,expr . ,exprs)))))
            ; let: Not empty - to application
            (pattern-rule
             `(let ,split-car-cadr ,(? 'expr) . ,(? 'exprs list?))
             (lambda (vars values expr exprs)
               (parse `((lambda ,vars ,expr . ,exprs) . ,values))))
            ;empty let* pattern
            (pattern-rule
             `(let* () ,(? 'expr) . ,(? 'exprs))
             (lambda (expr exprs)
               (parse `(begin ,expr ,@exprs))))
            ;let* pattern rule
            (pattern-rule
             `(let* ((,(? 'var is-var?) ,(? 'val)) . ,(? 'rest)) . ,(? 'exprs)) 
             (lambda (var val rest exprs)
               (parse `(let ((,var ,val))
                         (let* ,rest . ,exprs)))))
            ; cond: Empty - to void
            (pattern-rule
             `(cond)
             (lambda ()
               `(const ,elseDoNothing)))
            ;cond
            (pattern-rule
             `(cond (,(? 'expr (lambda (x) (equal? 'else x ))) . ,(? 'exprs)))
             (lambda (expr exprs)
               (parse (cons 'begin exprs))))
            ;cond, MIT
            (pattern-rule
             `(cond ,(? 'clause list-length>=2?) . ,(? 'clauses list?))
             (lambda (clause clauses)
               (parse `(if ,(car clause)
                           ,(parse-begin (cdr clause))
                           (cond . ,clauses)))))
            ;3.2 Macro-Expanding Special Forms in Scheme letrec
            ;empty letrec
            (pattern-rule
             `(letrec () ,(?`expr).,(? 'exprs list?))
             (lambda (expr exprs)
               (parse `((lambda() ,expr . , exprs)))))
            
            (pattern-rule
             `(letrec ,(? 'expr list?) ,@(? 'body))
             (lambda (expr body)
               (let ((variables (map car expr)))
                 (parse `((lambda ,variables
                            (begin ,@(append (map (lambda (x) (list 'set! (car x) (cadr x))) expr) 
                                             `(((lambda () ,@body))))))
                          ,@(map (lambda (x) #f) expr))))))
            ; 3.3 Handling quasi quoted expressions
            (pattern-rule
             `(,'quasiquote ,(? 'expr))
             (lambda (expr) 
               (parse (expand-qq expr))))
            )))
     (lambda (e)
       (run e
            (lambda ()
              (error 'parse
                     (format "ERROR: ~s" e))))))) 

;  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3
;  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3
;  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3
;  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3
;  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3
;  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3
;  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3
;  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3
;  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3  HW3

;3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
;3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
;3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
;3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
;3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
;3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
;3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
;3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333           
; mayer code from class
(define find-nested-defines
  (lambda (pes ret-ds+es)
    (if (null? pes)
        (ret-ds+es '() '())
        (find-nested-defines (cdr pes)
                             (lambda (ds es)
                               (cond ((eq? (caar pes) 'def)
                                      (ret-ds+es (cons (car pes) ds) es))
                                     ((eq? (caar pes) 'seq)
                                      (find-nested-defines (cadar pes)
                                                           (lambda (ds1 es1) (ret-ds+es
                                                                              (append ds1 ds)
                                                                              (append es1 es)))))
                                     (else (ret-ds+es ds (cons (car pes) es)))))))))
;return varaibles of define
(define defineVars
  (lambda (ds)
    (map (lambda (def)
           (cadadr def))
         ds)))
;make set function
(define createSet
  (lambda (ds)
    (map (lambda (def)
           (cons 'set (cdr def)))
         ds)))

(define createDefualtVars
  (lambda (ds)
    (map (lambda (def)
           '(const #f))
         ds)))
;
(define mapElminate
  (lambda (x y)
    (map eliminate-nested-defines (find-nested-defines x y))))
;
(define HelperFunc
  (lambda (lambda-what e)
    (lambda(ds es)
      (if (null? ds)
          e
          `(lambda-what ,(cadr e)
                        (applic (lambda-simple ,(defineVars ds)
                                               (seq (,@(createSet ds) ,@es))) ,(createDefualtVars ds)))))))
;  
(define caaddr=e?  (lambda  (what-cont e)         
                     (if (eq? (caaddr e) 'seq)
                         (mapElminate (car (cdaddr e)) (HelperFunc what-cont e))
                         (mapElminate '((caddr e)) (HelperFunc what-cont e)))))
;
(define eliminate-nested-defines
  (lambda (e)
    (cond ((or (const? e) (symbol? e) (null? e))     e)
          ((eq? (car e) 'lambda-simple)
           (let ((cont 
                  (lambda(ds es)
                    (if (null? ds)
                        e
                        `(lambda-simple ,(cadr e)
                                        (applic (lambda-simple ,(defineVars ds)
                                                               (seq (,@(createSet ds) ,@es))) ,(createDefualtVars ds)))))
                  ))
             (if (eq? (caaddr e) 'seq)
                 (mapElminate (car (cdaddr e)) cont)
                 (mapElminate '((caddr e)) cont))))
          ((eq? (car e) 'lambda-var)
           
           (caaddr=e? 'lambda-var e))
          ((equal? (car e) 'lambda-opt)
           (let ((cont (lambda (ds es)
                         (if (null? ds)
                             e
                             (map eliminate-nested-defines `(lambda-opt ,(cadr e) ,(caddr e)
                                                                        (applic (lambda-simple ,(defineVars ds)
                                                                                               (seq (,@(createSet ds) ,@es))) ,(createDefualtVars ds))))))))
             (if (eq? (car (cadddr e)) 'seq)
                 (mapElminate (cadr (cadddr e)) cont)
                 (mapElminate '((cadddr e)) cont))))
          (else
           (map eliminate-nested-defines
                e)))))

;444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
;444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
;444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
;444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
;444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444

;;;;;;;;;4 Removing redundant applications
(define lambda-nil? 
  (lambda (inputlst) 
    (if (and 
         (list? inputlst) 
         (not(null? inputlst)) 
         (equal? 'applic (car inputlst)) 
         (equal? (caadr inputlst) 'lambda-simple) 
         (null? (cadadr inputlst)))
        (list (car (cddadr inputlst)))
        #f)))  
;
(define remove-applic-lambda-nil
  (lambda (Input)
    (cond ((lambda-nil? Input) 
           (remove-applic-lambda-nil (lambda-nil? Input)))
          ((atom? Input) Input)
          (else 
           (map (lambda (Input2) 
                  (if (lambda-nil? Input2) 
                      (remove-applic-lambda-nil (car (lambda-nil? Input2))) 
                      (remove-applic-lambda-nil Input2)
                      )) Input)))))

;55555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
;55555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
;55555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
;55555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
;55555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
;55555555555555555555555555555555555555555555555555555555555555555555555555555555555555555

;;;;;;5  Boxing of variables ;;;;

(define GetParemeters (lambda (Input)
                        (let ((carinp (car Input)))                    
                          (cond ((equal? 'lambda-simple carinp) (cadr Input))
                                ((equal? 'lambda-var carinp) (list (cadr Input)))
                                ((equal? 'lambda-opt carinp) (append (cadr Input) (list (caddr Input))))
                                (else (list))))))
(define some-kind-of-lambda?
  (lambda (Input)
    (or (equal? 'lambda-simple (car Input))
        (equal? 'lambda-var (car Input)) 
        (equal? 'lambda-opt (car Input)))))

(define some-kind-of-lambda-expander
  (lambda (Input)
    (and (list? Input) (< 2 (length Input)) (some-kind-of-lambda? Input))))

(define bound-var? 
  (letrec ((varInInput (lambda (var Input)
                         (cond ((null? Input) #f)
                               ((list? Input) (or (varInInput var (car Input)) (varInInput var (cdr Input))))
                               ((equal? var Input) #t)
                               (else #f))))
           (varIsNotparam (lambda (var Input) (not (member var (GetParemeters Input)))))	      
           (lambda? (lambda (var Input)
                      (and (some-kind-of-lambda-expander Input) (varIsNotparam var Input))))
           (recurs (lambda (var Input)
                  (cond ((null? Input) #f)
                        ((lambda? var Input) (varInInput var Input))
                        ((list? Input) (or (recurs var (car Input)) (recurs var (cdr Input))))
                        (else #f)))))
    (lambda (var env)
      (recurs var env))))


(define set-equal? (lambda (var Input) 
                     (and (list? Input) (= 3 (length Input)) (equal? 'set (car Input)) 
                          (equal? var (cadadr Input)))))

(define hass?
  (lambda (v Input onesetzeroget)
    (cond ((null? Input) #f)
          ((set-equal? v Input) (if (zero? onesetzeroget) (hass? v (caddr Input) onesetzeroget) #t))
          ((and (some-kind-of-lambda-expander Input) (member v (GetParemeters Input))) #f)
          ((and (equal? onesetzeroget 0) (list? Input) (= 2 (length Input)) (equal? 'var (car Input)) (equal? v (cadr Input))) #t)
          ((list? Input) (or (hass? v (car Input) onesetzeroget) (hass? v (cdr Input) onesetzeroget)))
          (else #f))))

(define list-of-box-params
  (letrec ((unbox-lmb (lambda (Input lst)
                        (cond ((null? lst) (list))
                              ((and (bound-var? (car lst) Input) (hass? (car lst) Input 1) (hass? (car lst) Input 0)) (cons (car lst) (unbox-lmb Input (cdr lst))))
                              (else (unbox-lmb Input (cdr lst)))))))
    (lambda (scope list-of-vars)
      (reverse (unbox-lmb scope list-of-vars)))))

(define readd-box-param
  (letrec ((lambda-with-param?
            (lambda (var Input)
              (and (some-kind-of-lambda-expander Input) (member var (GetParemeters Input)))))
           (unbox-lmb (lambda (var Input)
                        (cond ((null? Input) (list))
                              ((lambda-with-param? var Input) Input)
                              ((set-equal? var Input) `(box-set ,(cadr Input) ,(unbox-lmb var (caddr Input))))
                              ((and (list? Input) (= 2 (length Input)) (equal? 'var (car Input)) 
                                    (equal? var (cadr Input)))
                               `(box-get ,Input))
                              ((list? Input) (cons (unbox-lmb var (car Input)) (unbox-lmb var (cdr Input))))
                              (else Input)))))
    (lambda (var2 scope)
      (if (equal? 'seq (car scope)) 
          `(seq ((set (var ,var2) (box (var ,var2))) ,@(unbox-lmb var2 (cadr scope))))
          `(seq ((set (var ,var2) (box (var ,var2))) , (unbox-lmb var2  scope)))))))

(define box-lambda-expr 
  (letrec ((env (lambda (Input) (if (equal? 'lambda-opt
                                            (car Input)) (cadddr Input) (caddr Input))))
           (recurs (lambda (env box-params)
                  (cond ((null? box-params) env)
                        (else (readd-box-param (car box-params) (recurs env (cdr box-params))))))))
    (lambda (Input)
      `( ,@(if (equal? 'lambda-opt(car Input))
               (list (car Input) (cadr Input) (caddr Input))
               (list (car Input) (cadr Input)))
         ,@(list (box-set (recurs (env Input) 
                               (list-of-box-params (env Input)
                                                   (reverse (GetParemeters Input))))))))))

(define box-set (lambda (Input)
                  (cond  ((null? Input) (list))
                         ((some-kind-of-lambda-expander Input) (box-lambda-expr Input))
                         ((list? Input) (cons (box-set (car Input)) (box-set (cdr Input))))
                         (else Input))))
;6666666666666666666666666666666666666666666666666666666666666666666666666666666
;6666666666666666666666666666666666666666666666666666666666666666666666666666666
;6666666666666666666666666666666666666666666666666666666666666666666666666666666
;6666666666666666666666666666666666666666666666666666666666666666666666666666666
;6666666666666666666666666666666666666666666666666666666666666666666666666666666
;6666666666666666666666666666666666666666666666666666666666666666666666666666666
; check if exp is a seq
(define seq?
  (lambda(exp)
    (and (pair? exp) (equal? (car exp) 'seq))))
; return seq exps
(define get-seq-exps
  (lambda(exp)
    (cadr exp)))
; check if exp is lambda simple
(define lambda-simple-exp?
  (lambda(exp)
    (and (pair? exp) (equal? (car exp) 'lambda-simple))))
; return variables of lambda simple
(define get-lambda-simple-vars
  (lambda(exp)
    (cadr exp)))
;return lambda simple body
(define get-lambda-simple-body
  (lambda(exp)
    (caddr exp)))
; check if exp is lambda optional 
(define lambda-opt-exp?
  (lambda(exp)
    (and (pair? exp) (equal? (car exp) 'lambda-opt))))
;return lambda optional variables
(define get-lambda-opt-vars
  (lambda(exp)
    (cadr exp)))
;return lambda optional extra variables if there is any
(define get-lambda-opt-extra-var
  (lambda(exp)
    (caddr exp)))
; get lambda optional body
(define get-lambda-opt-body
  (lambda(exp)
    (cadddr exp)))
;check if exp is vardic lambda
(define lambda-variadic-exp?
  (lambda(exp)
    (and (pair? exp) (equal? (car exp) 'lambda-variadic))))
;get lambda vardaic variables
(define get-lambda-variadic-var
  (lambda(exp)
    (cadr exp)))
;return the body of the lambda varadic
(define get-lambda-variadic-body
  (lambda(exp)
    (caddr exp)))
;check if this exp is the var
(define my-var?
  (lambda(exp)
    (and (pair? exp) (equal? (car exp) 'var))))
;return varialbes
(define get-my-var?
  (lambda(exp)
    (cadr exp)))
;get the element position in stack 
(define get-item-position-in-stack
  (lambda(item  stack  )
    (letrec ((iter 
              (lambda(stack item i)
                (if (equal? (car stack) item) i
                    (iter (cdr stack) item (+ i 1))))))
      (iter stack item 0))))
; check if item is memebr in the enviorment
(define member-in-env
  (lambda(item env)
    (cond ((null? env) #f)
          ((member item (car env)) #t)
          (else (member-in-env item (cdr env) )))))
;return the item position in the enviorment . 
(define get-item-position-in-env
  (lambda(item env)
    (letrec ((iter
              (lambda(env item i)
                (if (member item (car env)) 
                    (cons (car env) i) 
                    (iter (cdr env) item (+ i 1)  )))))
      (let* ((stack-row (iter env item 0))
             (stack (car stack-row))
             (row (cdr stack-row))
             (col (get-item-position-in-stack item stack)))
        (cons row col)))))
;6 Annotating Variables with their Lexical address;
(define pe->lex-pe
  (lambda(pe)
    (letrec ((annotate-scope
              (lambda(exp stack env)
                (cond ((lambda-simple-exp? exp)
                       (let* ((new-stack (get-lambda-simple-vars exp))
                              (body-exp (get-lambda-simple-body exp))
                              (new-env  (cons stack env)))         
                         (if (seq? body-exp) 
                             `(lambda-simple ,new-stack (seq ,(map (lambda(exp) (annotate-scope  exp new-stack new-env)) (get-seq-exps body-exp))))  
                             `(lambda-simple ,new-stack ,(annotate-scope body-exp new-stack new-env)))))
                      ((lambda-opt-exp? exp)
                       (let* ((vars (get-lambda-opt-vars exp))
                              (extra-var (get-lambda-opt-extra-var exp))
                              (new-stack (append vars (list extra-var)))
                              (body-exp (get-lambda-opt-body exp))
                              (new-env  (cons stack env)))         
                         (if (seq? body-exp) 
                             `(lambda-opt ,vars ,extra-var (seq ,(map (lambda(exp) (annotate-scope  exp new-stack new-env)) (get-seq-exps body-exp))))  
                             `(lambda-opt ,vars ,extra-var ,(annotate-scope body-exp new-stack new-env)))))
                      ((lambda-variadic-exp? exp)
                       (let* ((var  (get-lambda-variadic-var exp))
                              (new-stack (list var))
                              (body-exp (get-lambda-variadic-body exp))
                              (new-env  (cons stack env)))         
                         (if (seq? body-exp) 
                             `(lambda-variadic ,var (seq ,(map (lambda(exp) (annotate-scope  exp new-stack new-env)) (get-seq-exps body-exp))))  
                             `(lambda-variadic ,var ,(annotate-scope body-exp new-stack new-env)))))
                      ((my-var? exp)
                       (let ((var (get-my-var? exp)))
                         (cond ((member var stack) `(pvar ,var ,(get-item-position-in-stack var  stack  )  ))
                               ((member-in-env var env)
                                (let ((pos (get-item-position-in-env var env)))
                                  `(bvar ,var ,(car pos) ,(cdr pos))))
                               (else `(fvar ,var)))))
                      ((list? exp) (map (lambda(exp) (annotate-scope  exp stack env)) exp))
                      (else exp)))))
      (annotate-scope pe '() '())) ))

;7 Annotating tail calls;
(define map-on-annotate
  (lambda (pe tp?)
    (if (null? pe) '()
        (if (null? (cdr pe)) (list (loop-annotate-tc (car pe) tp?))
            (cons (loop-annotate-tc (car pe) #f) (map-on-annotate (cdr pe) tp?))))))


(define loop-annotate-tc
  (lambda (pe tp?)
    (cond
      ((null? pe) pe)
      ((not (pair? pe)) pe)
      ((eq? (car pe) 'var) pe)
      ((eq? (car pe) 'fvar) pe)
      ((eq? (car pe) 'bvar) pe)
      ((eq? (car pe) 'pvar) pe)
      ((eq? (car pe) 'or)
       `(or ,(map-on-annotate (cadr pe) tp?)))
      ((eq? (car pe) 'if3)
       `(if3 ,(loop-annotate-tc (cadr pe) #f)
             ,(loop-annotate-tc (caddr pe) tp?)
             ,(loop-annotate-tc (cadddr pe) tp?)))
      ((eq? (car pe) 'seq)
       `(seq ,(map-on-annotate (cadr pe) tp?)))
      ((eq? (car pe) 'lambda-simple)
       `(lambda-simple ,(cadr pe) ,(loop-annotate-tc (caddr pe) #t)))
      ((eq? (car pe) 'lambda-opt)
       `(lambda-opt ,(cadr pe) ,(caddr pe) ,(loop-annotate-tc (cadddr pe) #t)))
      ((eq? (car pe) 'lambda-variadic)
       `(lambda-variadic ,(cadr pe) ,(loop-annotate-tc (caddr pe) #t)))
      ((eq? (car pe) 'applic)
       (if tp?
           `(tc-applic ,(loop-annotate-tc (cadr pe) #f) ,(loop-annotate-tc (caddr pe) #f))
           `(applic ,(loop-annotate-tc (cadr pe) #f) ,(map-on-annotate (caddr pe) #f))))
      ((eq? (car pe) 'define)
       `(define ,(loop-annotate-tc (cadr pe) #f) ,(loop-annotate-tc (caddr pe) #f)))
      (else (cons (loop-annotate-tc (car pe) tp?) (loop-annotate-tc (cdr pe) tp?) )))))


(define annotate-tc
  (lambda (pe)
    (loop-annotate-tc pe #f)))