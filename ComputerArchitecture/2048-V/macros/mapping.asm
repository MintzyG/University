.data
wrong: .asciz "You've entered a wrong char, pls enter another: "

#AM similar to convert but applies random offsets for the whole alphabet
#AM it also directly calls random to apply the offset imediately
.macro ALPHABET_MAPPING(%char)
loop:
  li t0, 'a'
  li t1, 'b'
  li t2, 'c'
  li t3, 'd'
  li t4, 'e'
  li t5, 'f'
  li t6, 'g'
	
  beq t0, %char, A
  beq t1, %char, B
  beq t2, %char, C
  beq t3, %char, D
  beq t4, %char, E
  beq t5, %char, F
  beq t6, %char, G
  j S2
  
  A:
    li s0, 36
    RANDOM(s0, rand_ptr)
    j end
  B:
    li s0, 45
    RANDOM(s0, rand_ptr)
    j end
  C:
    li s0, 12
    RANDOM(s0, rand_ptr)
    j end
  D:
    li s0, 28
    RANDOM(s0, rand_ptr)
    j end
  E:
    li s0, 50
    RANDOM(s0, rand_ptr)
    j end
  F:
    li s0, 7
    RANDOM(s0, rand_ptr)
    j end
  G:
    li s0, 18
    RANDOM(s0, rand_ptr)
    j end
    
  S2:
  li t0, 'h'
  li t1, 'i'
  li t2, 'j'
  li t3, 'k'
  li t4, 'l'
  li t5, 'm'
  li t6, 'n'
	
  beq t0, %char, H
  beq t1, %char, I
  beq t2, %char, J
  beq t3, %char, K
  beq t4, %char, L
  beq t5, %char, M
  beq t6, %char, N
  j S3
  
  H:
    li s0, 49
    RANDOM(s0, rand_ptr)
    j end
  I:
    li s0, 41
    RANDOM(s0, rand_ptr)
    j end
  J:
    li s0, 23
    RANDOM(s0, rand_ptr)
    j end
  K:
    li s0, 14
    RANDOM(s0, rand_ptr)
    j end
  L:
    li s0, 3
    RANDOM(s0, rand_ptr)
    j end
  M:
    li s0, 48
    RANDOM(s0, rand_ptr)
    j end
  N:
    li s0, 35
    RANDOM(s0, rand_ptr)
    j end
    
  S3:
  li t0, 'o'
  li t1, 'p'
  li t2, 'q'
  li t3, 'r'
  li t4, 's'
  li t5, 't'
  li t6, 'u'
	
  beq t0, %char, O
  beq t1, %char, P
  beq t2, %char, Q
  beq t3, %char, R
  beq t4, %char, S
  beq t5, %char, T
  beq t6, %char, U
  j S4
  
  O:
    li s0, 29
    RANDOM(s0, rand_ptr)
    j end
  P:
    li s0, 9
    RANDOM(s0, rand_ptr)
    j end
  Q:
    li s0, 19
    RANDOM(s0, rand_ptr)
    j end
  R:
    li s0, 39
    RANDOM(s0, rand_ptr)
    j end
  S:
    li s0, 44
    RANDOM(s0, rand_ptr)
    j end
  T:
    li s0, 27
    RANDOM(s0, rand_ptr)
    j end
  U:
    li s0, 10
    RANDOM(s0, rand_ptr)
    j end
    
  S4:
  li t0, 'v'
  li t1, 'w'
  li t2, 'x'
  li t3, 'y'
  li t4, 'z'
	
  beq t0, %char, V
  beq t1, %char, W
  beq t2, %char, X
  beq t3, %char, Y
  beq t4, %char, Z
  j Default
  
  V:
    li s0, 31
    RANDOM(s0, rand_ptr)
    j end
  W:
    li s0, 6
    RANDOM(s0, rand_ptr)
    j end
  X:
    li s0, 37
    RANDOM(s0, rand_ptr)
    j end
  Y:
    li s0, 22
    RANDOM(s0, rand_ptr)
    j end
  Z:
    li s0, 46
    RANDOM(s0, rand_ptr)
    j end

  Default:
    PRINT(wrong)
    GET_INPUT_CHAR()
    j loop
    
  end:
.end_macro
