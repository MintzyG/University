.macro MOVE_LEFT(%matrix)
	li a1, 0
	li a2, 12
	la a3, %matrix
	
	current_line:
		bgt a1, a2, end
		lw t0, 0(a3)
		li t1, 0
		li t2, 4
		
		addi t1, t0, 4
		j while
		
	next_line:
		addi a1, a1, 4
		addi a3, a3, 4
		j current_line
	while:
		bgt t2, a2, next_line
		lw t3, 0(t0)
		lw t4, 0(t1)
		
		beq t4, zero, move_sum_pointer
		beq t3, zero, move_to_empty
		beq t3, t4, equal_destination
		
		addi t0, t0, 4
		bne t0, t1, while
		addi t1, t1, 4
		addi t2, t2, 4
		j while
		
	move_sum_pointer:
		addi t1, t1, 4
		addi t2, t2, 4
		j while
		
	move_to_empty:
    li s7, 1
		lw t5, 0(t1)
		sw t5, 0(t0)
		sw zero, 0(t1)
		
		addi t1, t1, 4
		addi t2, t2, 4
		j while
		
	equal_destination:
    li s7, 1
		add t5, t3, t4
    ADD_SCORE(score, t5)
		sw t5, 0(t0)
		sw zero, 0(t1)
		li t6, -1
		COUNT(counter, t6)
		
		addi t0, t0, 4
		addi t1, t1, 4
		addi t2, t2, 4
		j while
	
	end:

.end_macro
