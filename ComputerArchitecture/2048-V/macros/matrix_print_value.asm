.macro MATRIX_PRINT_VALUE (%matrix, %line, %column)
	MATRIX_FETCH(%matrix, %line, %column) #O valor é buscado e guardado em s0 a partir dessa macro
	mv a0, s0	#O valor contido em s0 é transferido para a0
	li a7, 1
	ecall
.end_macro
