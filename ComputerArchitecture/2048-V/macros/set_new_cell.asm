.macro SET_NEW_CELL()
  start:
    li s0, 1 #SNC sets s0 as 1 to get next random number
    RANDOM(s0, rand_ptr) #SNC gets the random number

    li t0, 16 #SNC value needed for % operation
    rem s0, s0, t0 #SNC calculates the position 0 indexed
    addi s0, s0, 1 #SNC fixes the position adding 1

    li t0, 0 #SNC creates a counter with 0
    loop:
      addi s0, s0, -4 #SNC subtracts 4 from position
      addi t0, t0, 1 #SNC counter += 1 for every subtraction > 0
      ble s0, zero, get_pos #SNC -> gets that position current value else
      j loop #SNC keeps subtracting and counting

    get_pos: #SNC gets here once t3 <= 0
      addi s1, t0, -1 #SNC subtracts 1 from the counter to find line | (i)
      addi s2, s0, 3 #SNC adds 3 to t3 to find the element | (j)
      MATRIX_FETCH(matrix, s1, s2) #SNC gets  number at position matrix[i][j]
      bnez s0, start #SNC (problem?) if value != 0 find another position
      li s0, 1 #SNC sets s0 to 1 further optimize
      RANDOM(s0, rand_ptr) #SNC gets a new random number
      li t0, 10 #SNC loads 10 for modulo operation
      rem t0, s0, t0 #SNC calculates the remainder of the random number with 10
      addi t0, t0, 1 #SNC adds 1 to result for range 1-10 instead of 0-9
      li t1, 1 #SNC loads 1 to for if
      beq t0, t1, quatro #SNC if t4 == 1 goes to label quatro:
        MATRIX_CHANGE_VALUE (matrix, s1, s2, 2) #SNC set matrix[i][j] to 2
        j end #SNC ends macro
      quatro:
        MATRIX_CHANGE_VALUE (matrix, s1, s2, 4) #SNC set matrix[i][j] to 4
      end:
      li s9, 1 #SNC loads 1 to sum to count
      COUNT(counter, s9) #SNC count += 1
.end_macro
