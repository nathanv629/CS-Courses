#|
Van, Nathan
Kim, Juyeon
Bui, Catherine

April 19,2020

CS 250
Lab 16
|#

#lang racket
(define func1
 (lambda(x y)
   (cond[(empty? x) (cons x y )]
        [else (first x)])))

(func1 '() '(1 2 3))
(func1 '(1 2 3) '(4 5 6 7))
 

(define new-list
  (lambda (w)
    (cons (third w)
          (cons (second w)
                (cons (first w)
                      (rest(rest(rest w))))))))

(new-list '(1 2 3))
(new-list  '(1 2 3 4))
(new-list '((1 2) (3) (4)))