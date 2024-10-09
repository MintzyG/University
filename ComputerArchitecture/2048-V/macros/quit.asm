#Q prints score and quits the game
.macro QUIT(%score)
  PRINT_SCORE(%score)
  li a7, 10
  ecall
.end_macro
