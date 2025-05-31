# Resumo — Capítulo 6: Circuitos Sequenciais

## 6.1 Conceito
- Circuitos **sequenciais**: saída depende da **entrada atual** + **estado anterior**.
- Necessário: **memória** para armazenar 1 bit.
- Aplicação: **controladores**.

## 6.2 Elemento Biestável
- Base da memória: **dois inversores em ciclo** → 2 estados estáveis.
- Problema: sem entradas de controle, é **impraticável**.

## 6.3 Latch SR
- Entradas: **S** (set) e **R** (reset).
- Funcionamento:
  - `S=1`, `R=0` → `Q = 1` (**set**).
  - `S=0`, `R=1` → `Q = 0` (**reset**).
  - `S=0`, `R=0` → **mantém estado**.
  - `S=1`, `R=1` → **estado inválido**.

## 6.4 Latch D
- Entrada: **D** (dado) e **CLK** (clock).
- Funcionamento:
  - `CLK=1` → `Q = D`.
  - `CLK=0` → **mantém estado**.
- Problema: alteração de D enquanto `CLK=1` pode causar **erro**.

## 6.5 Flip-Flop D (Edge-Triggered)
- Solução: **muda apenas na borda** (transição) do clock.
- Implementação: dois **latches-D em série**:
  - 1º: clock **invertido**.
  - 2º: clock **normal**.
- Evita alterações indesejadas → **mais confiável**.

## 6.6 Flip-Flop JK
- Evolução do latch SR → elimina estado proibido.
- Entradas: **J** e **K**.
- Funcionamento:
  - `J=1`, `K=0` → **set** (`Q = 1`).
  - `J=0`, `K=1` → **reset** (`Q = 0`).
  - `J=K=1` → **inverte saída**.
  - `J=K=0` → **mantém estado**.

## 6.7 O Papel do Relógio
- Clock define **quando** a saída muda.
- Garante **sincronização** de todo o circuito.

## 6.8 Utilização dos Circuitos Sequenciais
- Base para: 
  - **Registradores**
  - **Memórias**
  - **Contadores**
  - **Máquinas de Estados Finitos (FSM)**

### Máquinas de Estados Finitos (FSM)

#### Componentes:
- **Estados**: armazenam histórico.
- **Transições**: condições para mudar de estado.
- **Ações**: atividades executadas.

#### Tipos:
- **Moore**: saída depende **apenas do estado**.
- **Mealy**: saída depende do **estado + entrada**.

#### Representação:
1. **Diagrama de estados**.
2. **Tabela de transição**.
3. **Equações booleanas**.
4. **Circuito**.

### Exemplo de FSM
- Robô detecta sequência `1101` em fita binária.
- **FSM Moore**: saída associada ao **estado**.
- **FSM Mealy**: saída associada à **transição**.

### Passos para criar FSM:
1. Identificar **entradas** e **saídas**.
2. Desenhar **diagrama de transição**.
3. Criar **tabela de transição**.
4. Escolher **codificação** dos estados.
5. 
   - Para **Moore**: tabela de transição + tabela de saída.
   - Para **Mealy**: tabela única de transição e saída.
6. Derivar **equações booleanas**.
7. Desenhar **circuito**.

