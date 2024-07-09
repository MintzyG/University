.data
start: .asciz "Qual valor de parada: "
new: .asciz "\n"

.text
.global main
main: 
	li t0, 0          # Valor limite
	li t2, 0          # fib(0)
	li t3, 1          # fib(1)
	li t4, 0	  # fib(next)
	
	# Print texto
	la a0, start
  	addi a7, zero, 4
  	ecall
  			
  	# Read input
	li a7, 5
	ecall
	add t0, zero, a0
	j while
		
while:
	bge t4, t0, end	 # if (t1 >= t2)
	
	add t4, t3, t2
	
	mv t2, t3
	mv t3, t4
	
	la a0, new
  	addi a7, zero, 4
  	ecall
	
	mv a0, t4
	li a7, 1
	ecall
	
	j while

end:
	li a7, 10             # finaliza
	ecall
