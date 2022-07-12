.data
input: .word 1,5,7,2,3,10,4,9,8,6

.text
li $t1,10	# number of elements = 10
li $t2,0  	#index

la $t3, input
lw $s1, 0($t3) #s1 hold the max number

loop:
slt $t4,$t2,$t1 
beq $t4, $zero, end

sll $t6,$t2,2		
add $t6,$t6,$t3
lw $s2, 0($t6)

slt $t5, $s1, $s2
beq $t5, 1, changeMaxNumber

add $t2, $t2, 1
j loop
changeMaxNumber:
add $s1, $s2, $zero
j loop

end:
