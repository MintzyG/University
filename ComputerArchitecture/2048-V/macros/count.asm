.macro COUNT(%count, %value)
  la s11, %count #C loads counter in s11
  lw s10, 0(s11) #C loads counter value in s10
  add s10, s10, %value #C adds value to counter
  sw s10, 0(s11) #C saves back counter
.end_macro
