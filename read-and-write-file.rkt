#lang racket/base

;; Write and Read
(let ([file "/tmp/data.txt"])
  (with-output-to-file file
    #:exists 'replace
    (lambda () (printf "text in a file")))
  (call-with-input-file file
    (lambda (in) (displayln (read-string 18 in)))))

;; Read line by line
(call-with-input-file "/etc/shells"
  (lambda (in)
    (let keep-reading ()
      (let ([line (read-line in)])
        (unless (eof-object? line)
          (displayln line)
          (keep-reading))))))

;; Read line by line (2)
(call-with-input-file "/etc/shells"
  (lambda (in)
    (for ([l (in-lines in)])
      (displayln l))))
