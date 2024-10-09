.macro PRINT_ADDR(%addr)
  mv a0, %addr #PA receives an address as input and loads it
  li a7, 1 #PA loads 1 on a7 to print a number
  ecall #PA prints the address received
.end_macro
