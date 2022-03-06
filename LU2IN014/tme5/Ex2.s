.text
.globl main
main:
  addiu $29, $29, -8 # Deux variables locales: a, b
  addi $8, $0, 123
  sw $8, 4($29) # a <- 123
  addi $9, $0, 245
  sw $9, 0($29) # b <- 245
  
loop:
  lw $8, 4($29) # lecture a
  lw $9, 0($29) # lecture b
  beq $8, $9, finloop
  
  # corps du boucle
  sub $10, $8, $9 
  bgtz $10, agb 
  bltz $10, apb 
  
  agb : # if (a > b)
    sub $8, $8, $9 # a <- a - b
    sw $8, 4($29)

  apb : # if (a < b)
    sub $9, $9, $8 # b <- b - a
    sw $9, 0($29)
  # Retour au debut de la boucle
  j loop

finloop:
  lw $4, 4($29) # lecture a
  ori $2, $2, 1 # affichage a
  syscall
  addiu $29, $29, 8 # Desallocation dans la pile
  ori $2, $2, 0
  jr $31 # return 0
 
ori $2, $0, 10
syscall