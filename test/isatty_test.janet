(import ../build/isatty :prefix "")
(import testament :prefix "" :exit true)

(deftest standard-stuff-is-tty
  (is (isatty? stdout))
  (is (isatty? stdin))
  (is (isatty? stderr)))

(deftest other-stuff-is-not-tty
  (is (not (isatty? (file/temp)))))

(run-tests!)
