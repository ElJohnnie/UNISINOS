# Capítulo 4 - Simplificação de Funções Lógicas

## Objetivo
Minimizar expressões booleanas para reduzir a complexidade de circuitos e programas:
- Menor consumo de energia.
- Maior desempenho.
- Manutenção mais simples.

---

## 4.1 Derivação de Expressões Booleanas

### Métodos principais:

### ✅ Soma de Produtos (SdP)
- Usa todas as combinações de entradas que resultam em **1**.
- Cada linha com resultado 1 gera um **mintermo**.
- **Mintermo:** produto (AND) de todas variáveis:
  - Variável = 0 → aparece **negada**.
  - Variável = 1 → aparece **não negada**.
- Função final: **OR** entre todos os mintermos.
- **Quando usar:** quando houver **mais 0s** que 1s na tabela-verdade → gera expressão mais curta.

---

### ✅ Produto de Somas (PdS)
- Usa todas as combinações de entradas que resultam em **0**.
- Cada linha com resultado 0 gera um **maxtermo**.
- **Maxtermo:** soma (OR) de todas variáveis:
  - Variável = 1 → aparece **negada**.
  - Variável = 0 → aparece **não negada**.
- Função final: **AND** entre todos os maxtermos.
- **Quando usar:** quando houver **mais 1s** que 0s → expressão mais curta.

---

## 4.2 Álgebra Booleana

- Conjunto de **axiomas e teoremas** para **simplificar** expressões booleanas.
- Regras semelhantes à álgebra comum, mas só com **0** e **1**.

### ✅ Exemplo clássico de simplificação:
Y = AB + AB
= B(A + A)
= B(1)
= B

- **Limitação:** não garante a solução **mais simplificada** — muitas vezes exige tentativa e erro.

---

## 4.2.1 Mapa de Karnaugh (MK)

- **Ferramenta gráfica** para simplificação sistemática de funções booleanas.
- Baseada na lógica da **Soma de Produtos**.
- Substitui a tentativa e erro por um método **visual e sistemático**.

---

### ✅ Regras para simplificação com MK:
1. Agrupar os **1s adjacentes** (horizontal/vertical).
2. Grupos devem ter tamanho em **potências de 2** (1, 2, 4, 8...).
3. Cada **1** deve ser coberto **ao menos uma vez**.
4. Grupos podem **atravessar bordas** do mapa.
5. **"Don’t care" (X)** podem ser usados se ajudarem na simplificação.
6. Mantêm-se variáveis **constantes** no grupo; eliminam-se variáveis **que mudam**.
7. Grupos resultam em produtos (AND) → combinação final por soma (OR).

---

## Aplicação conforme o número de variáveis:

### ✅ MK com 2 variáveis
- **4 quadrados**.
- Exemplo:  
  F = (AB)' + AB → simplificada para **F = A**.

---

### ✅ MK com 3 variáveis
- **8 quadrados**.
- Usa **código Gray**: 00, 01, 11, 10.
- Exemplo:  
  Grupo cobre posições onde C varia → função minimizada: **F = AB**.

---

### ✅ MK com 4 variáveis
- **16 quadrados**.
- Código Gray usado nas **colunas e linhas**.
- Grupos podem ultrapassar as bordas.
- Mesmo raciocínio das versões anteriores, mas com mais complexidade.

---

## ✅ Resumo final:
1. Derive a função via **SdP** ou **PdS**, conforme a quantidade de 1s e 0s.
2. Tente simplificar com **álgebra booleana** → tentativa e erro.
3. Prefira o **Mapa de Karnaugh** → minimização **visual e sistemática**.

---


