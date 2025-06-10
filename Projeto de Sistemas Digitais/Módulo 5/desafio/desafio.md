Implementação de um programa em linguagem de montagem MIPS 32 bits para realizar a soma de dois valores numéricos inteiros.data
    prompt1:    .asciiz "Digite o primeiro numero: "
    prompt2:    .asciiz "Digite o segundo numero: "
    resultMsg:  .asciiz "Resultado da soma: "

.text
.globl main

main:
    # Print prompt1
    li $v0, 4
    la $a0, prompt1
    syscall

    # Read first integer
    li $v0, 5
    syscall
    move $t0, $v0    # $t0 = primeiro número

    # Print prompt2
    li $v0, 4
    la $a0, prompt2
    syscall

    # Read second integer
    li $v0, 5
    syscall
    move $t1, $v0    # $t1 = segundo número

    # Soma
    add $t2, $t0, $t1    # $t2 = soma

    # Print result message
    li $v0, 4
    la $a0, resultMsg
    syscall

    # Print result value
    li $v0, 1
    move $a0, $t2
    syscall

    # Exit
    li $v0, 10
    syscall
