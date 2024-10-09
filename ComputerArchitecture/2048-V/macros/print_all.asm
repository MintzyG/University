#PA a combination of PRINT and PRINT_ADDR to print text together with an address
.macro PRINT_ALL(%text, %addr)
  PRINT(%text)
  PRINT_ADDR(%addr)
  NEW_LINE()
.end_macro
