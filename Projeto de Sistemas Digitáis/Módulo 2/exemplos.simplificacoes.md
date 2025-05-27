# Exemplos Resolvidos de Simplificação de Funções Booleanas

---

## ✅ Exemplo 1: Soma de Produtos (SdP)

### Tabela-Verdade:

| A | B | F |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

### Passo a passo:
- Linhas com **F = 1**: (0,1) e (1,0)
- Para (0,1) → A'B
- Para (1,0) → AB'

### Expressão SdP:
F = A'B + AB'


---

## ✅ Exemplo 2: Produto de Somas (PdS)

### Mesma tabela-verdade:

| A | B | F |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

### Passo a passo:
- Linhas com **F = 0**: (0,0) e (1,1)
- Para (0,0) → (A + B)
- Para (1,1) → (A' + B')

### Expressão PdS:

- F = (A + B)(A' + B')


### Passo a passo:
1. F = A(B + B')
2. F = A(1)
3. F = A

### Expressão simplificada:

- F = A


---

## ✅ Exemplo 4: Mapa de Karnaugh (MK)

### Tabela-Verdade:

| A | B | F |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

### Mapa de Karnaugh:

| A\B | 0 | 1 |
|------|---|---|
| 0    | 0 | 1 |
| 1    | 1 | 1 |

### Passo a passo:
- Agrupar os três **1s** contíguos: (0,1), (1,0), (1,1).
- Melhor agrupamento:  
  - Grupo 1: cobre (1,0) e (1,1) → A  
  - Grupo 2: cobre (0,1) e (1,1) → B

### Expressão simplificada:

- F = A + B

O que significa cada parte:
A' → A negado. Ou seja, quando A = 0.

B → B direto. Ou seja, quando B = 1.

A'B → A é 0 E B é 1 → A AND NOT B.

A → A direto. Ou seja, quando A = 1.

B' → B negado. Ou seja, quando B = 0.

AB' → A é 1 E B é 0 → A AND NOT B.

+ → OR → resultado é verdadeiro se pelo menos um dos dois termos for verdadeiro.

✅ Em outras palavras:
F é verdadeiro quando:

A é 0 e B é 1

OU

A é 1 e B é 0.

✅ Resultado:
Isso é a clássica função XOR (ou exclusivo).
Só dá 1 quando A e B são diferentes.

# Resumo:


---

## ✅ Exemplo 5: MK com 3 variáveis

### Tabela-Verdade:

| A | B | C | F |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 1 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |
