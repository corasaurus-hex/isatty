(declare-project
  :name "isatty"
  :description "tells you if a file is a tty"
  :dependencies ["https://github.com/pyrmont/testament"])

(declare-native
  :name "isatty"
  :source ["isatty.c"])
