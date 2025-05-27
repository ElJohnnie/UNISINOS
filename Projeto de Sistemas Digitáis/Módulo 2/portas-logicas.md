# ✅ CAPÍTULO 3 - SISTEMAS DIGITAIS E PORTAS LÓGICAS

## 3.1 Sistemas Digitais

- Sistemas digitais → manipulam **valores discretos** (0 ou 1).
- Representação física → geralmente por **tensão**:  
  - `0V` → **Falso** (0)  
  - `5V` → **Verdadeiro** (1)
- Principal aplicação → **computadores**.

---

## 3.2 Operações Lógicas

**Base: Álgebra Booleana** → criada por **George Boole** (1854).

### ✅ Operações Fundamentais:

- **NOT (Negação):**  
  - **Unária** → inverte a entrada:  
    - `NOT(0) = 1`  
    - `NOT(1) = 0`  
  - **Símbolo:** `¬A` ou `A'`

- **AND (E):**  
  - **Binária** → resultado `1` **apenas se ambas entradas forem 1**:  
    - `1 AND 1 = 1`  
    - demais casos → `0`  
  - **Símbolo:** `A · B`

- **OR (Ou):**  
  - **Binária** → resultado `1` **se ao menos uma entrada for 1**:  
    - `0 OR 1 = 1`  
    - `1 OR 0 = 1`  
    - `0 OR 0 = 0`  
  - **Símbolo:** `A + B`

### ✅ Portas Derivadas:

- **NAND:** `AND` negada  
- **NOR:** `OR` negada  
- **XOR:** `Ou-Exclusivo` → saída `1` **se número ímpar de 1's**  
- **XNOR:** `XOR` negada

---

## 3.3 Expressões Lógicas

- Portas lógicas → podem ser **combinadas** → formando **expressões booleanas**.
- **Equivalência com operações matemáticas:**  
  - `AND` → **multiplicação**  
  - `OR` → **adição**

### ✅ Ordem de Precedência:

1. **Parênteses** `()`
2. **Negação** `NOT`
3. **E** `AND`
4. **Ou** `OR` / `XOR`

**Exemplo:**  
Expressão: `R = X + Y · Z'`  

**Resolução:**  
1. `Z'` → inverte `Z`.  
2. `Y · Z'` → operação `AND`.  
3. `X + (Y · Z')` → operação `OR`.

**Tabela-Verdade:**  
- Elabora-se listando todas as combinações de `X, Y, Z`.

---
