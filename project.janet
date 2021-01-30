(declare-project
  :name "isatty"
  :description "tells you if a file is a tty"
  :dependencies [])

(declare-native
  :name "isatty"
  :source ["isatty.c"])
