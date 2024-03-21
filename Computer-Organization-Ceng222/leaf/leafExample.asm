.text
leaf_example:
addi $a0, $zero, 10
addi $a1,$zero, 15
addi $a2,$zero, 20
addi $a3,$zero, 30
addi $s0, $zero, 100

addi $sp, $sp, -4	
sw $s0, 0($sp) 
add $t0, $a0, $a1
add $t1, $a2, $a3
sub $s0, $t0, $t1
move $v0, $s0
lw $s0, 0($sp)
addi $sp, $sp, 4
j exit

exit:
