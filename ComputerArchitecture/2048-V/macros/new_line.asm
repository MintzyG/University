.data
new_line: .asciz "\n"

.macro NEW_LINE()
  la a0, new_line #NL loads the new line string
  li a7, 4 #NL loads 4 on a7 to print a string
  ecall #NL prints the new line
.end_macro
