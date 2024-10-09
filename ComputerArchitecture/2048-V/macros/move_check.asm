.data
lost: .asciz "You lost!\n"
cont: .asciz "You continue!\n"

.macro POSSIBLE_CHECK(%matrix)
  vars:
    li a1, 0 #PC i counter
    li a2, 0 #PC j counter
    li a3, 4 #PC line/column limit
    li a4, 3 #PC element limit
   
  horizontal: # horizontal checks
    for_loop_1_step_1:
      bge a1, a3, vertical #PC verifies if i counter is stop condition
      li a2, 0 #PC starts j counter at 0
      j for_loop_2 #PC 

      for_loop_2:
      bge a2, a3, for_loop_1_step_2 #PC verifies if for loop 2 finished
	
	beqz a2, end_loop_2 #PC if verifying first value continue
	beq a2, a4, end_loop_2 #PC if verifying last value continue
	
	  MATRIX_FETCH(matrix, a1, a2) #PC gets position [i][j]
	  mv s1, s0 #PC saves the value at i j for comparing
	  addi t0, a2, 1 #PC prepares t0 to get the next value
	  MATRIX_FETCH(matrix, a1, t0) #PC gets the next value
	  beq s0, s1, possible #PC if equals a move is possible
    beq s0, zero, possible #PC if next is 0 a move is possible
	  addi t0, a2, -1 #PC prepares to get previous value
	  MATRIX_FETCH(matrix, a1, t0) #PC gets previous value
	  beq s0, s1, possible #PC if equals a move is possible
    beq s0, zero, possible #PC if next is 0 a move is possible
	  j end_loop_2
	
	end_loop_2:
	  addi a2, a2, 1 #PC increments j by 1
	  j for_loop_2
				
    for_loop_1_step_2:
      addi a1, a1, 1 #PC increments i by 1
      j for_loop_1_step_1
  
   vertical:
    li a1, 0 #PC i counter
    li a2, 0 #PC j counter
    for_loop_1_step_1v:
      bge a1, a3, finish #PC verifies if i counter is at stop condition
      li a2, 0 #PC starts j counter at 0
      j for_loop_2v

      for_loop_2v:
	bge a2, a3, for_loop_1_step_2v #PC verifies if j counter is at stop condition
	
	beqz a2, end_loop_2v #PC if verifying first value continue
	beq a2, a4, end_loop_2v #PC if verifying last value continue
	
	  MATRIX_FETCH(matrix, a2, a1) #PC gets value at position [j][i]
	  mv s1, s0 #PC saves the value at i j for comparing
	  addi t0, a2, 1 #PC prepares t0 to get the next value
	  MATRIX_FETCH(matrix, t0, a1) #PC gets the next value
	  beq s0, s1, possible #PC if equals a move is possible
    beq s0, zero, possible #PC if next is 0 a move is possible
	  addi t0, a2, -1 #PC prepares to get previous value
	  MATRIX_FETCH(matrix, t0, a1) #PC gets previous value
	  beq s0, s1, possible #PC if equals a move is possible
    beq s0, zero, possible #PC if next is 0 a move is possible
	  j end_loop_2v
	
	end_loop_2v:
	  addi a2, a2, 1 #PC increments j by 1
	  j for_loop_2v
				
    for_loop_1_step_2v:
      addi a1, a1, 1 #PC increments i by 1
      j for_loop_1_step_1v
  
  possible:
    #li s 7, 1 PC future implementation for not spawning unecessary cells
    MATRIX_PRINT(matrix)
    j end #PC you still have moves left, jumps to end keeps playing
  finish:
    PRINT(lost) #PC you have no moves left
    MATRIX_PRINT(matrix) #PC prints the matrix before quitting
    QUIT(score) #PC closes the game
  end:
.end_macro
