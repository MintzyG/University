#A macro recebe a matriz, a posição e um valor como argumentos
#Ela vai até a posição da matriz informada e bota o valor novo nela

.macro MATRIX_CHANGE_VALUE (%matrix, %line, %column, %value)
	mv t1, %line #MCV posição de linha é guardado em t1
	mv t2, %column #MCV posição de coluna é guardado em t2
	li t3, 4 #MCV t3 recebe o valor 4 para multiplicar os valores contidos em t1 e t2
	li t4, %value #MCV o valor novo é guardado em t4
	
	#Os valores em t1 e t2 são multiplicados por 4
	mul t1, t1, t3 #MCV multiplies t1 by int offset
	mul t2, t2, t3 #MCV multiplies t2 by int offset
	
	#O valor novo é guardado na posição da matriz informada
	la s0, %matrix #MCV loads matrix at s0
	add s0, s0, t1 #MCV moves to the desired line 
	lw t0, 0(s0) #MCV loads first element of that line
	add t0, t0, t2 #MCV moves to the desired element
	sw t4, 0(t0) #MCV stores %value at that element
.end_macro


#Essa macro é a mesma que a de cima, com a única diferença sendo como recebe o valor novo
#A macro de cima recebe um valor literal. Quando ela é chamada, o valor deve ser passada dessa forma:
#	MATRIX_CHANGE_VALUE(matrix, t0, t1, 23)
#A macro de baixo, em vez de receber um número direto, ela recebe um registrador contendo um número. Sua chamada é feita dessa forma:
#	MATRIX_CHANGE_VALUE_ADDR(matrix, t0, t1, t2)

.macro MATRIX_CHANGE_VALUE_ADDR(%matrix, %line, %column, %value)
	mv t1, %line #MCV posição de linha é guardado em t1
	mv t2, %column #MCV posição de coluna é guardado em t2
	li t3, 4 #MCV t3 recebe o valor 4 para multiplicar os valores contidos em t1 e t2
	mv t4, %value #MCV o valor novo é guardado em t4
	
	mul t1, t1, t3 #MCV multiplies t1 by int offset
	mul t2, t2, t3 #MCV multiplies t2 by int offset
	
	la s0, %matrix #MCV loads matrix at s0
	add s0, s0, t1 #MCV moves to the desired line 
	lw t0, 0(s0) #MCV loads first element of that line
	add t0, t0, t2 #MCV moves to the desired element
	sw t4, 0(t0) #MCV stores %value at that element
.end_macro
