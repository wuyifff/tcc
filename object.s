.data
_Prompt: .asciiz "Enter an integer:  "
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0,4
  la $a0,_Prompt
  syscall
  li $v0,5
  syscall
  jr $ra
write:
  li $v0,1
  syscall
  li $v0,4
  la $a0,_ret
  syscall
  move $v0,$0
  jr $ra

fact:
  li $t3, 1
  sw $t3, 20($sp)
  lw $t1, 12($sp)
  lw $t2, 20($sp)
  beq $t1,$t2,label2
  j label3
label2:
  lw $v0,12($sp)
  jr $ra
  j label1
label3:
  li $t3, 1
  sw $t3, 24($sp)
  lw $t1, 12($sp)
  lw $t2, 24($sp)
  sub $t3,$t1,$t2
  sw $t3, 28($sp)
  move $t0,$sp
  addi $sp, $sp, -40
  sw $ra,0($sp)
  lw $t1, 28($t0)
  move $t3,$t1
  sw $t3,12($sp)
  jal fact
  lw $ra,0($sp)
  addi $sp,$sp,40
  sw $v0,32($sp)
  lw $t1, 12($sp)
  lw $t2, 32($sp)
  mul $t3,$t1,$t2
  sw $t3, 36($sp)
  lw $t1, 36($sp)
  move $t3, $t1
  sw $t3, 20($sp)
  lw $v0,20($sp)
  jr $ra
label1:

main:
  addi $sp, $sp, -28
  li $t3, 10
  sw $t3, 16($sp)
  lw $t1, 10468624($sp)
  move $t3, $t1
  sw $t3, 12($sp)
  move $t0,$sp
  addi $sp, $sp, -40
  sw $ra,0($sp)
  lw $t1, 12($t0)
  move $t3,$t1
  sw $t3,12($sp)
  jal fact
  lw $ra,0($sp)
  addi $sp,$sp,40
  sw $v0,24($sp)
  lw $t1, 24($sp)
  move $t3, $t1
  sw $t3, 20($sp)
  li $t3, 0
  sw $t3, 24($sp)
  lw $v0,24($sp)
  jr $ra
label5:
