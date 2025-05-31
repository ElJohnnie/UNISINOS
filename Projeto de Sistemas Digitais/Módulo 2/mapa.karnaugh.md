# ✅ Mapa de Karnaugh (MK)

## O que é?

- Técnica **gráfica** para **simplificar** funções booleanas.
- Baseado na **Soma de Produtos** (SdP).
- Facilita a visualização de **combinações adjacentes** que podem ser simplificadas.

---

## ✅ Como montar?

1. **Número de variáveis** define o tamanho do mapa:
   - 2 variáveis → 4 células (2²).
   - 3 variáveis → 8 células (2³).
   - 4 variáveis → 16 células (2⁴).

2. Preenche cada célula com o resultado da função, conforme a **tabela-verdade**.

3. Organização das variáveis segue o **Código Gray** (para mudar só 1 bit por vez):

- 2 variáveis → sequência: 00, 01, 11, 10.
- 3 variáveis → idem nas colunas/linhas.
- 4 variáveis → Código Gray em ambos eixos.

---

## ✅ Como simplificar?

**Regras fundamentais**:

- Forme grupos de **"1" adjacentes**.
- Grupos devem ser quadrados ou retângulos.
- Tamanho do grupo → potência de 2:  
  `1, 2, 4, 8, 16...`
- Cada "1" deve ser **coberto ao menos uma vez**.
- **Quanto maior** o grupo, **melhor** (mais simplificação).
- Grupos podem **"dar a volta"** no mapa, conectando bordas.
- "Don't care" (`X`) → usa **se** ajudar na simplificação.
- Em cada grupo: 
  - Mantém variáveis que **não mudam**.
  - Elimina variáveis que **mudam**.

---

## ✅ Como escrever a expressão final?

- Cada grupo gera um **termo produto** (AND).
- Todos os grupos são combinados com **soma** (OR).

---

## ✅ Exemplos rápidos:

### 1. MK de 2 variáveis

| A | B | F |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

Mapa:


Grupo: duas células `1` → A = 1, B muda → **F = A**

---

### 2. MK de 3 variáveis

8 células, exemplo:

| A | B | C | F |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 1 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 |

Faz agrupamentos, simplifica eliminando variáveis que **mudam**.

---

### 3. MK de 4 variáveis

16 células. Mesmo processo, mas com atenção para agrupamentos que podem **ultrapassar bordas**.

---

## ✅ Vantagens do MK:

✅ Visual  
✅ Evita tentativa e erro  
✅ Garante **simplificação máxima**

---

## ✅ Quando usar?

- Sempre que tiver até **4-5 variáveis**.
- Para mais variáveis → melhor usar métodos **algorítmicos** (Quine-McCluskey, etc.).

