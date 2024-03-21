# sum of array
.data
input:	.word 100,500,50,-300,-25,10
output:	.word 0

.text
li $t1,6
li $t2,0	
li $s1,0	

la $t3,input
la $t4,output

loop:
slt $t5,$t2,$t1
beq $t5,$zero,out	

sll $t5,$t2,2		
add $t5,$t5,$t3		

lw $t6,0($t5)		
add $s1,$s1,$t6		

addi $t2,$t2,1		
j loop			

out:
sw $s1,0($t4)
