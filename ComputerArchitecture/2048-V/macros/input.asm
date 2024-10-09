.data
input_s: .string "Your move (w/a/s/d): "
init: .string "Escreva uma letra: "

.macro GET_INPUT_INIT()
  la a0, init #GIC loads input text
  li a7, 4 #GIC loads 4 to print string
  ecall #GIC prints input text
  li a7, 12 #GIC loads 12 to get user input
  ecall #GIC gets user input
  mv s0, a0 #GIC saves user input on s0 so its no cannibalized
  NEW_LINE()
.end_macro

.macro GET_INPUT_CHAR()
  la a0, input_s #GIC loads input text
  li a7, 4 #GIC loads 4 to print string
  ecall #GIC prints input text
  li a7, 12 #GIC loads 12 to get user input
  ecall #GIC gets user input
  mv s0, a0 #GIC saves user input on s0 so its no cannibalized
  NEW_LINE()
.end_macro
