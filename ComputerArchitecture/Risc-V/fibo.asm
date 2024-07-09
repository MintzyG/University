.data
start: .asciz "Até qual valor de fibonacci você deseja: "
new: .asciz "\n"

.text
.global main
main: 
	la a0, start
  	addi a7, zero, 4
  	ecall
	li t0, 0          # iterador inicial
	li t1, 5          # valor do final
	li t2, 0          # fib(0)
	li t3, 1          # fib(1)
		
	li a7, 5         # read input
	ecall		 # syscall
	add t1, zero, a0        # armazena no vetor
		
max_loop:
	bge t0, t1, end # if (iterador >= final) print_max;
	
	add t4, t3, t2
	mv t2, t3
	mv t3, t4
	la a0, new
  	addi a7, zero, 4
  	ecall
	mv a0, t4
	li a7, 1
	ecall
	addi t0, t0, 1        # iterador++
	j max_loop

end:
	li a7, 10             # finaliza
	ecall
