.data
rand: .word 23, 45, 17, 82, 51, 99, 64, 15, 37, 76, 29, 62, 86, 5, 93, 13, 49, 79, 34, 67, 9, 90, 21, 54, 84, 30, 63, 89, 19, 52, 81, 36, 69, 25, 58, 87, 12, 44, 73, 39, 72, 16, 48, 77, 32, 65, 92, 24, 57, 85, 38, 71, 27, 60, 88, 11, 43, 74, 35, 68, 95, 28, 61, 83, 18, 50, 78, 33, 66, 94, 26, 59, 80, 14, 46, 75, 31, 70, 97, 20, 53, 82, 10, 42, 71, 40, 98, 96
 
# WARNING: for this to work you have to declare on main.asm .data section the following
# "rand_ptr: .word 0" and pass it to RANDOM as its second argument, otherwise it will not work
# rand_ptr stores the current index of rand, so you can use the macro multiple times without starting at 0
 
# Gets a random number based on user input
.macro RANDOM (%key, %rand_ptr)
  la s3, %rand_ptr #R loads rand_ptr into s0
  lw t0, 0(s3) #R loads current index into t0
  add t0, t0, %key #R adds key into current index
 
  li t1, 100 #R loads t1 as rand size
  rem  t0, t0, t1 #R stay inbounds by doing curr_index % 100
  sw t0, 0(s3) #R saves the new curr index value
  
  li t1, 4 #R replaces t1 with int size
  mul t0, t0, t1 #R applies int offset to t0

  la s0, rand #R loads rand into s0
  add s0, s0, t0 #R shifts curr index amount in rand
  lw s0, 0(s0) #R gets and returns rand value in s0
.end_macro
