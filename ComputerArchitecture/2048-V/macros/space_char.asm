.data
space_char: .asciz " "

.macro SPACE_CHAR()
  la a0, space_char #SC loads space_char on a0
  li a7, 4 #SC loads 4 on a7 to print a string
  ecall #SC prints space_char
.end_macro
