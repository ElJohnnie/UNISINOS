# ✅ CAPÍTULO 5 - CIRCUITOS COMBINACIONAIS

## 5.1 Circuitos Lógicos

- A partir de uma **expressão booleana** → desenha-se o **circuito lógico**.
- **Passos:**
  1. Identifique as **entradas** → ficam à esquerda (ou em cima).
  2. Identifique as **saídas** → ficam à direita (ou embaixo).
  3. Identifique as **operações** → desenhe as **portas lógicas** da esquerda para a direita.
  4. Para cada entrada → trace uma linha representando o fio.

**Exemplo:**  
Equação: `X + Y·Z'`  
→ Porta AND (`Y·Z'`), depois OR com `X`.

---

## 5.2 Circuitos Combinacionais

- Bloco formado por circuitos mais simples.
- **Saída depende apenas das entradas**.
- Qualquer mudança na entrada → **altera a saída**.

**Dica:**  
Quebre o problema em blocos simples de **1 bit**.

---

## 5.2.1 Multiplexadores / Demultiplexadores

### ✅ Multiplexador (MUX)
- Direciona **uma entre N entradas** para a saída.
- Possui:  
  - `2^n` **entradas**  
  - `n` **linhas de controle**  
  - `1` **saída**

**Exemplo:**  
MUX 2:1 → 2 entradas, 1 seletor.  
MUX 4:1 → 4 entradas, 2 seletores.

**Construção:**  
- Use MUX menores para construir MUX maiores.

### ✅ Demultiplexador (DEMUX)
- Faz o **oposto**:  
  - **1 entrada** → **N saídas**  
- Direciona a entrada para uma saída, conforme o **seletor**.

---

## 5.2.2 Codificador / Decodificador

- **Codificador:** converte de uma representação **natural → codificada**.
- **Decodificador:** faz o **inverso**.

**Exemplo:**  
- Decodificador de **7 segmentos** → converte número binário em sinais para exibir dígitos.

---

## 5.2.3 Comparadores

- **Comparam duas entradas**:  
  - `A = B → A - B = 0`  
  - `A > B → A - B > 0`  
  - `A < B → A - B < 0`

**Construção:**  
- Pode usar circuitos específicos.  
- Normalmente se baseia em um **subtrator**.

---

## 5.2.4 Somadores

- Circuito fundamental.  
- Soma dois bits → gera:  
  - **Sum** (soma)  
  - **Carry Out** (vai-um)

### ✅ Meio Somador
- Entradas: `A`, `B`  
- Saídas: `Sum`, `Carry`

**Limitação:**  
- Não considera o **Vem-Um** (Carry-In).

### ✅ Somador Completo
- Entradas: `A`, `B`, `Carry-In`  
- Saídas: `Sum`, `Carry-Out`

**Construção:**  
- 2 meio somadores + 1 porta OR.

### ✅ Somador em Cadeia
- Encadeie **somadores completos** para operar vários bits.  
- **Vai-Um** de um → **Vem-Um** do próximo.  
- Último **Carry-Out** → indica **overflow**.

**Exemplo:**  
- **Somador de 4 bits** → 4 somadores completos em sequência.

---

## 5.2.5 Subtratores

- Subtração: `A - B = A + (-B)`
- Solução:  
  - Inverter `B` → **Complemento de 2**.  
  - Usar o mesmo **circuito de soma**.

---

## 5.2.6 Unidade Lógica e Aritmética (ULA)

- Conjunto de circuitos combinacionais que realizam:  
  - **Operações aritméticas**: soma, subtração, comparação.  
  - **Operações lógicas**: AND, OR, XOR, inversão.

**Função:**  
- Coração da **CPU** → executa todas as instruções lógicas e aritméticas.

**Observação:**  
- Operações lógicas são feitas **bit a bit**.

---

