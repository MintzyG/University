.data
score_s: .string "Score: "

.macro ADD_SCORE(%score, %amount)
  la s11, %score #AS loads score pointer
  lw s10, 0(s11) #AS loads score value
  add s10, s10, %amount #AS adds the amount to score
  sw s10, 0(s11) #AS stores back the new score
.end_macro

.macro PRINT_SCORE(%score)
  la a0, score_s #AS loads score text
  li a7, 4 #AS load 4 to print string
  ecall
  la s11, %score #AS loads score pointer
  lw a0, 0(s11) #AS loads score value
  li a7, 1 #AS load 1 to print integer
  ecall #AS print score
  NEW_LINE()
.end_macro
