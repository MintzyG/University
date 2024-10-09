.macro MATRIX_PRINT(%matrix)
	loop_variables:
		li a1, 0
		li a2, 0
		li a3, 4
	
	for_loop_1_step_1:        # count lines
		bge a2, a3, continue
		li a1, 0
		j for_loop_2
		
	for_loop_1_step_2:        # call print line 4 times to 4 lines
		addi a2, a2, 1
		NEW_LINE
		NEW_LINE
		NEW_LINE
		j for_loop_1_step_1
		
	for_loop_2:               # print line
		bge a1, a3, for_loop_1_step_2
		MATRIX_FETCH(%matrix, a2, a1)
		mv s9, s0
		li s10, 10
		li s11, 0
		li s8 -1
		loop_decimal_places:    # counts the number of decimal places that the number has
		div s9, s9, s10
		addi s11, s11, 1
		bne s9, zero, loop_decimal_places
		
		mul s11, s11, s8
		addi s11, s11, 6
		
		loop_print_spaces:      # prints the spaces, according to the number of decimal places
		SPACE_CHAR
		addi s11, s11, -1
		bgt s11, zero, loop_print_spaces
		MATRIX_PRINT_VALUE(%matrix, a2, a1)
		addi a1, a1, 1
		SPACE_CHAR
		j for_loop_2
	
	continue:
	NEW_LINE
.end_macro
