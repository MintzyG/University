.include "./macros/macros.asm"

.data

.global matrix temp rand_ptr counter score
vector_1: .word 0, 0, 0, 0
vector_2: .word 0, 0, 0, 0
vector_3: .word 0, 0, 0, 0
vector_4: .word 0, 0, 0, 0
matrix: vector_1, vector_2, vector_3, vector_4

vector_5: .word 0, 0, 0, 0
vector_6: .word 0, 0, 0, 0
vector_7: .word 0, 0, 0, 0
vector_8: .word 0, 0, 0, 0
temp: vector_5, vector_6, vector_7, vector_8

rand_ptr: .word 0
counter: .word 0
score: .word 0
.text

main:
	INIT()
	while:
	MATRIX_PRINT(matrix)
	GET_INPUT_CHAR()
	mv s6, s0
	CONVERT_INPUT(s6)
	RANDOM(s1, rand_ptr)
	MOVE_SWITCH(s6)
	la t1, counter
	lw t2, 0(t1)
	li t3, 16
	blt t2, t3, while
	POSSIBLE_CHECK(matrix)
	j while
