#CI converts user input into predetermined numbers to be used for random number genneration
#CI this is similar to the DOOM method of generation random numbers and is faster than a pseudo random formula
.macro CONVERT_INPUT(%input)
  li t0, 'w' #CI checks if input is w
  beq t0, %input, W #CI jumps accordingly
  li t0, 'a' #CI checks if input is A
  beq t0, %input, A #CI jumps accordingly
  li t0, 's' #CI checks if input is S
  beq t0, %input, S #CI jumps accordingly
  li t0, 'd' #CI checks if input is D
  beq t0, %input, D #CI jumps accordingly
  W:
    li s1, 13 #CI applies W offset to s1
    j end #CI done here
  A:
    li s1, 52 #CI applies A offset to s1
    j end #CI done here
  S:
    li s1, 47 #CI applies S offset to s1
    j end #CI done here
  D:
    li s1, 86 #CI applies D offset to s1
  end:
.end_macro
