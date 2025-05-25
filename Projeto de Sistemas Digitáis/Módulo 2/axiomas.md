# ✅ 4.2 Álgebra Booleana

## O que é?
- Conjunto de **regras** (axiomas e teoremas) para **simplificar** expressões booleanas.
- **Objetivo**: deixar a expressão **mais simples, rápida e eficiente** para implementar.

## Por quê?
- Menos portas lógicas → **menos custo**, **menos energia** e **mais desempenho**.

---

# ✅ Axiomas da Álgebra Booleana

### São as **regras básicas** do funcionamento das operações:

| Axioma                         | Resultado   |
|---------------------------------|-------------|
| Identidade: A + 0               | A           |
| Identidade: A · 1               | A           |
| Dominação: A + 1                | 1           |
| Dominação: A · 0                | 0           |
| Idempotência: A + A             | A           |
| Idempotência: A · A             | A           |
| Inversão: A + A'                | 1           |
| Inversão: A · A'                | 0           |
| Comutatividade: A + B = B + A   | ✅ Válido   |
| Comutatividade: A · B = B · A   | ✅ Válido   |
| Associatividade: (A + B) + C = A + (B + C) | ✅ Válido |
| Associatividade: (A · B) · C = A · (B · C) | ✅ Válido |
| Distributividade: A(B + C) = AB + AC | ✅ Válido |
| Distributividade: A + BC = (A + B)(A + C) | ✅ Válido |

---

# ✅ Como usar?

Vai aplicando essas regras para ir **reduzindo** a expressão até não conseguir mais.

### Exemplo:

Y = AB + AB
= B(A + A) → Distributiva
= B(1) → Inversão
= B → Identidade

---

# ✅ Limitação:

- Nem sempre o resultado é o **mais otimizado** só usando álgebra.
- Por isso, usamos **Mapas de Karnaugh** para ajudar.

---