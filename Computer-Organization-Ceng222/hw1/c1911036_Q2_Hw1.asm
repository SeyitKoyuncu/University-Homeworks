# sum of array
.data
input:	.word 10,25,50,100,300,500
output:	.word 0

.text
li $s1,0	# sum

la $t1,input
la $t2,output

lw $t3, 0($t1)
lw $t4, 4($t1)
lw $t5, 8($t1)
lw $t6, 12($t1)
lw $t7, 16($t1)
lw $t8, 20($t1)

sub $t9,$t7,$t5
add $s1, $t6, $t8
sub $s1, $s1, $t9
sub $s1, $s1, $t4
add $s1, $s1, $t3 

sw $s1,0($t2)