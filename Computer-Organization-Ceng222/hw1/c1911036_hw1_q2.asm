# This code works fine in QtSpim simulator

.data

.text

main:


    li $v0, 5 
    syscall      # take in input
    move $t0, $v0
    
    li $v0, 5 
    syscall      # take in input
    move $t1, $v0
    
    li $v0, 5 
    syscall      # take in input
    move $t2, $v0
    
    li $v0, 5 
    syscall      # take in input
    move $t3, $v0
    
    li $v0, 5 
    syscall      # take in input
    move $t4, $v0
    
    li $v0, 5 
    syscall      # take in input
    move $t5, $v0
    
    add $t6, $zero, $t0
    add $t6, $t6, $t1
    add $t6,$t6, $t2
    add $t6,$t6, $t3
    add $t6,$t6,$t4
    add $t6,$t6, $t5    
    
    

