addi $2, $0, 5
syscall
addu $3, $2, $0

addi $2, $0, 5
syscall
addu $4, $2, $0

addu $9, $0, $3
addu $10, $0, $4
div $9, $10

mflo $11
addi $2, $0, 1
addu $4, $0, $11
syscall

mfhi $12
addu $4, $0, $12
syscall

mult $11 $10
mflo $13
addu $14, $13, $12
addu $4, $0, $14
syscall