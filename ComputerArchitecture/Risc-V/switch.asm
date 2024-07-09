.data
qual: .asciz "Qual string você quer (1; 2; 3): "
um: .asciz "Primeira string\n"
dois: .asciz "Segunda string\n"
tres: .asciz "Terceira string\n"

.text
.global main
main:
	li t0, 1
	li, t1, 2
	li, t2, 3
	li, t3, 4
	li, t4, 0

user:	
	la a0, qual
  	addi a7, zero, 4
  	ecall

	li a7, 5
	ecall
	add t4, zero, a0  
	
	beq t0, t4 Pum
	beq t1, t4 Pdois
	beq t2, t4 Ptres
	beq t3, t4 sair
	j user
	
Pum:
	la a0, um
  	addi a7, zero, 4
  	ecall
  	j user
Pdois:
	la a0, dois
  	addi a7, zero, 4
  	ecall
  	j user
Ptres:
	la a0, tres
  	addi a7, zero, 4
  	ecall
  	j user
sair:
	li a7, 10             # finaliza
	ecall