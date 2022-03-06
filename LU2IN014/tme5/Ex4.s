.data
V: .word 8  # @ = 0x10010000
tab: .word 1, 3, 5, 7, 9, -1

.text
.globl main
main:
  addiu $29, $29, -4 # Une variable locale : cpt
  sw $0, 0($29) # cpt = 0
  lui $8, 0x1001 # $8 = 0x10010000 = @V
  lw $10, 0($8) # lecture V 
  addi $8, $8, 4 # $8 = @tab = 0x10010004
loop:
  lw $9, 0($8) # $9 = tab[i]
  addi $9, $9, 1
  beq $9, $0, finloop # if tab[i] == -1
  
  # corps du boucle
  lw $9, 0($8) # $9 = tab[i]
  addi $8, $8, 4 # i <- i+1
  sub $9, $9, $10 
  bltz $9, pv 
  bgtz $9, gv

  pv: # if (tab[i] < V)
    lw $11, 0($29) # lecture cpt
    addi $11, $11, 1 # cpt <- cpt + 1
    sw $11, 0($29) # écriture cpt
  
  gv : # if (tab[i] > V)
    lw $11, 0($29) # lecture cpt
    addi $11, $11, 0 # cpt <- cpt + 0
    sw $11, 0($29) # écriture cpt
  # Retour au debut de la boucle
  j loop

finloop:
  lw $4, 0($29) # lecture cpt
  ori $2, $2, 1
  syscall
  addiu $29, $29, 4 # Desallocation dans la pile
  ori $2, $2, 0
  jr $31 # return 0
  
ori $2, $0, 10
syscall
