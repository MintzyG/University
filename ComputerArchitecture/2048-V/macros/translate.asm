.macro TRANSLATE(%original, %temp)
	loop_variables:
		li a1, 0 #T j counter
		li a2, 0 #T i counter
		li a3, 4 #T loop limit
	
	for_loop_1_step_1:
		bge a2, a3, continue #T if at stop condition exit
		li a1, 0 #T loads j counter with 0
		j for_loop_2
		
	for_loop_2:
		bge a1, a3, for_loop_1_step_2 #T if at stop condition leave inner for loop
		MATRIX_FETCH(%original, a1, a2) #T fetches number at position [i][j]
		MATRIX_CHANGE_VALUE_ADDR(%temp, a2, a1, s0) #T sets the number back in temp matrix at position [j][i]
		addi a1, a1, 1 #T increment j counter
		j for_loop_2
	
	for_loop_1_step_2:
		addi a2, a2, 1 #T increment i counter
		j for_loop_1_step_1
		
	continue:
.end_macro
