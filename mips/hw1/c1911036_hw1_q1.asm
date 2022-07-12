.data

.text
addi $t1,$zero,500
addi $t2,$zero,100
addi $t3,$zero,50
addi $t4,$zero,10
addi $t5,$zero,300
addi $t6,$zero,25

sub $t7, $t5, $t3
add $t8, $t2, $t1
sub $t8, $t8, $t7
sub $t8, $t8, $t6
add $t8, $t8, $t7

