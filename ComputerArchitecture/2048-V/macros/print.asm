.macro PRINT(%text)
  la a0, %text #P receives text as input and loads it
  li a7, 4 #P loads 4 on a7 to print a string
  ecall #P prints the input text
.end_macro
