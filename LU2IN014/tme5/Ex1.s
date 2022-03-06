.text
.globl main
main:
  addiu $29, $29, -8 # Deux variables locales: i, somme
  sw $0, 4($29) # somme <- 0
  addi $8, $0, 1 # §8 <- 1
  sw $8, 0($29) # i <- 1
loop:
  lw $8, 0($29) # lecture i
  addi $8, $8, -11
  beq $8, $0, finloop
  
  # corps du boucle
  lw $9, 4($29) # lecture somme
  lw $10, 0($29) # lecture i
  add $9, $9, $10 # somme <- somme + i
  sw $9, 4($29) # écriture somme
  addi $10, $10, 1 # i <- i + 1
  sw $10, 0($29) # écriture i
  # Retour au debut de la boucle
  j loop

finloop:
  lw $4, 4($29) # lecture somme
  ori $2, $2, 1
  syscall
  addiu $29, $29, 8 # Desallocation dans la pile
  ori $2, $2, 0
  jr $31 # return 0
  
ori $2, $0, 10
syscall