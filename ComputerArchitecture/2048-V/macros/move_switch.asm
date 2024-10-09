.macro MOVE_SWITCH(%input)
  li, s7, 0 #MS initiates move keeper with 0, if 1 then we moved something
  li t0, 'w' #MS checks input for W
  beq t0, %input, W #MS jumps apropriatelly
  li t0, 'a' #MS checks input for A
  beq t0, %input, A #MS jumps apropriatelly
  li t0, 's' #MS checks input for S
  beq t0, %input, S #MS jumps apropriatelly
  li t0, 'd' #MS checks input for D
  beq t0, %input, D #MS jumps apropriatelly

  W:
    TRANSLATE(matrix, temp)
    MOVE_LEFT(temp)
    TRANSLATE(temp, matrix)
    j end #MS finished moving
  A:
    MOVE_LEFT(matrix)
    j end #MS finished moving
  S:
    TRANSLATE(matrix, temp)
    MOVE_RIGHT(temp)
    TRANSLATE(temp, matrix)
    j end #MS finished moving
  D:
    MOVE_RIGHT(matrix)
  end:
  la t0, counter #MS loads the counter
  lw t0, 0(t0) #MS loads counter value
  li t1, 16 #MS loads limit
  bge t0, t1, no_cell #MS if counter == limit do not spawn a cell
  beq s7, zero, no_cell #MS if we haven't moved anything don't spawn a cell
  SET_NEW_CELL()
  no_cell:
  li s7, 0 #MS reset move keeper
  PRINT_SCORE(score)
.end_macro
