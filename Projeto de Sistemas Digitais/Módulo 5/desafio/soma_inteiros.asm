.data
	newline: .asciiz "\n"

.text
	.globl main

main:
	# Soma $t0 + $t1 => $t2 = 12
	li $t0, 5
	li $t1, 7
    	add $t2, $t0, $t1  

    	# Imprime $t0
    	move $a0, $t0
    	li $v0, 1
    	syscall
    	li $v0, 4
    	la $a0, newline
    	syscall

    	# Imprime $t1
    	move $a0, $t1
    	li $v0, 1
    	syscall
    	li $v0, 4
    	la $a0, newline
    	syscall

    	# Imprime $t2 (resultado)
    	move $a0, $t2
    	li $v0, 1
    	syscall
    	li $v0, 4
    	la $a0, newline
    	syscall

    	li $v0, 10
    	syscall
