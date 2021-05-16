.data
N:
.word 5
M:
.word 4
matrix:
.word  3,  2,  4, 11
.word  5,  1,  6, 10
.word  7,  9,  8, 12
.word 20, 19, 18, 17
.word 13, 15, 17, 16
result:
.word 0x7FFF

.text

main:
la a2, N
la a3, M
la a4, matrix
la a5, result

lw t1, 0(a2)   # N
lw t2, 0(a3)   # M
mul t3, t1, t2 # N * M

call pushArray
call process
call print
call exit

pushArray:
addi t4, x0, 0 # element pointer (i)

pushArrayCycle:
lw t5, 0(a4)   # load value from array
addi a4, a4, 4 # increment array pointer
addi t4, t4, 1 # increment element pointer

# push value to stack
addi sp, sp, -4
sw t5, 0(sp)

blt t4, t3, pushArrayCycle # i < N * M
ret

process:
addi t4, x0, 0 # element pointer (i)

popCycle:
lw t6, 0(a5)   # load value from result
addi t4, t4, 1 # increment element pointer

# pop value from stack
lw t5, 0(sp)
addi sp, sp, 4

bge t5, t6     # result < poped value
sw t5, 0(a5)   # store new result

blt t4, t3, popCycle # i < N * M
ret


print:
addi a0, x0, 1 # print_int ecall
lw a1, 0(a5)   # result value
ecall

addi a0, x0, 11 # print_char ecall
addi a1, x0, 32
ecall

exit:
addi a0, x0, 10
ecall