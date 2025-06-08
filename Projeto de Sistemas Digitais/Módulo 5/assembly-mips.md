# Guia Completo de Assembly MIPS

## 📌 Introdução

A arquitetura MIPS é **RISC** (Reduced Instruction Set Computer), o que significa que possui um conjunto pequeno e eficiente de instruções. Cada instrução executa uma tarefa muito específica, geralmente em um único ciclo de clock.

---

## 🧠 Conceitos Fundamentais

### Registradores

MIPS tem **32 registradores de propósito geral** (`$0` a `$31`). Alguns deles têm nomes convencionais:

| Nome | Registrador | Uso                     |
|------|-------------|--------------------------|
| `$zero` | `$0`     | Contém sempre o valor 0   |
| `$t0-$t7` | `$8-$15` | Temporários              |
| `$s0-$s7` | `$16-$23` | Salvos entre chamadas    |
| `$a0-$a3` | `$4-$7` | Argumentos de função     |
| `$v0-$v1` | `$2-$3` | Valores de retorno       |
| `$sp`     | `$29`   | Stack pointer            |
| `$ra`     | `$31`   | Return address           |

---

## 🧮 Tipos de Instruções

### 1. **Tipo R (Register)**

Usadas para operações aritméticas/lógicas entre registradores.

```asm
add $t0, $t1, $t2   # $t0 = $t1 + $t2
sub $s0, $s1, $s2   # $s0 = $s1 - $s2
and $t0, $t1, $t2   # AND bit-a-bit
or  $t0, $t1, $t2   # OR bit-a-bit
slt $t0, $t1, $t2   # $t0 = 1 se $t1 < $t2, senão 0
```


### 2. Tipo I (Immediate)

```asm
addi $t0, $t1, 10   # $t0 = $t1 + 10
andi $t0, $t1, 0xFF # AND com valor imediato
lw   $t0, 4($s0)    # carrega palavra da memória
sw   $t0, 8($s0)    # salva palavra na memória
beq  $t0, $t1, LABEL # branch se igual
bne  $t0, $t1, LABEL # branch se diferente
```

### 3. Tipo J (Jump)

j LABEL           # Salta para LABEL
jal LABEL         # Salta e salva retorno em $ra
jr $ra            # Retorna da função (jump register)

### 🧰 Acesso à Memória

- MIPS é load/store architecture: só acessa memória via lw e sw.

- Endereços devem ser múltiplos de 4 para alinhamento.

```asm
lw  $t0, 0($sp)   # Carrega valor da pilha
sw  $t1, 4($sp)   # Salva valor na pilha
```

### 🔁 Controle de Fluxo
Condicional

```asm
beq $t0, $t1, IGUAL
bne $t0, $t1, DIFERENTE
slt $t2, $t0, $t1   # $t2 = 1 se $t0 < $t1
bne $t2, $zero, MENOR
```

Incondicional
j LOOP


### 📦 Funções

```asm
jal funcao     # chama função
```

### Retornos

```asm
jr $ra         # retorna para o endereço salvo
```

### Exemplo de Função

```asm
funcao:
    addi $sp, $sp, -8   # reserva espaço na pilha
    sw $ra, 4($sp)      # salva return address
    sw $s0, 0($sp)      # salva registrador s0

    # corpo da função

    lw $s0, 0($sp)      # restaura s0
    lw $ra, 4($sp)      # restaura return address
    addi $sp, $sp, 8    # libera espaço da pilha
    jr $ra              # retorna

```

### 🛠️ Exemplo Completo: Soma de Dois Números

```asm
.data
    a: .word 5
    b: .word 7
    result: .word 0

.text
main:
    lw $t0, a
    lw $t1, b
    add $t2, $t0, $t1
    sw $t2, result

    li $v0, 10    # syscall para sair
    syscall
```


### 📎 Referência Rápida de Instruções

| Categoria | Instruções 
|------|-------------|
| Aritmética | add, sub, mul, div | 
| Lógica | and, or, nor, slt |          
| Memória | lw, sw, lb, sb |
| Imediatos | addi, andi, ori, li | 
| Controle | beq, bne, j, jr, jal | 
| Syscalls | syscall | 


### 📚 Recursos para Praticar
- MARS Simulator – Ferramenta oficial.

- SPIM – Alternativa online ao MARS.

- Green Card MIPS – Folha de referência rápida.