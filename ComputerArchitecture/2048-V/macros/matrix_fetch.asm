# Macro que pega um valor específico da matriz e guarda ela em s0
# A macro recebe a label da matriz, e a posição do elemento na forma de linha e coluna.

# 0, 0 para o primeiro elemento. 0, 1, para o segundo... 3, 3 para o último

.macro MATRIX_FETCH (%matrix, %line, %column)
	
	mv t1, %line	#MF posição de linha é guardado em t1
	mv t2, %column	#MF posição de coluna é guardado em t2
	li t3, 4	#MF t3 recebe o valor 4 para multiplicar os valores contidos em t1 e t2
	
	#Os elementos dos vetores são espaçados em palavras de 4 bytes cada, então as
	#as posições são multiplicadas por 4 para que seja acessado os endereços de
	#memória corretos
	mul t1, t1, t3 #MF applies int offset to t1
	mul t2, t2, t3 #MF applies int offset to t2
	
	
	la s0, %matrix	#MF carrega o endereço da matriz em s0
	add s0, s0, t1	#MF soma o valor do endereço com o valor contido em t1
	lw t0, 0(s0)	#MF carrega em t0 a linha que o endereço em s0 aponta
	add t0, t0, t2	#MF soma o valor do endereço com o valor contido em t2
	lw s0, 0(t0)	#MF carrega em s0 o número que o endereço em t0 aponta
.end_macro
