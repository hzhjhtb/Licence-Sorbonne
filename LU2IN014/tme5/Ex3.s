.data
ch: .asciiz "Bonjour, Je suis Zhe HUANG!"  # @ = 0x10010000

.text
.globl main
main:
  addiu $29, $29, -4 # Une variable locale : i
  sw $0, 0($29) # i = 0
  lui $8, 0x1001 # $8 = 0x10010000 = @str
loop:
  lw $9, 0($29) # lecture i
  addu $9, $8, $9 # $9 = &str[i] = @str + i
  lb $9, 0($9) # $9 = str[i]
  beq $9, $0, finloop
  
  # corps du boucle
  lw $9, 0($29) # lecture i
  addi $10, $10, 1 # i <- i + 1
  sw $10, 0($29) # écriture i
  # Retour au debut de la boucle
  j loop

finloop:
  lw $4, 0($29) # lecture i
  ori $2, $2, 1
  syscall
  addiu $29, $29, 4 # Desallocation dans la pile
  ori $2, $2, 0
  jr $31 # return 0
  
ori $2, $0, 10
syscall