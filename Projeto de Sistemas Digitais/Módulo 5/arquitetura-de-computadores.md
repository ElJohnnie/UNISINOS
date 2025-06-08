

## Visão Geral
Este capítulo marca a transição do estudo da **organização** (hardware) para a **arquitetura** (interface com o software). A arquitetura **MIPS** é usada como base por sua simplicidade e aplicação real em sistemas embarcados, roteadores e consoles.

---

## 7.1 Ligação entre Hardware e Software

- **Organização**: define *como* o hardware executa operações.
- **Arquitetura**: define *o que* o hardware pode fazer (visão do programador).

> Exemplo:  
> - Organização: multiplicação via somas sucessivas ou circuito dedicado?  
> - Arquitetura: existe instrução de multiplicação?

- Um processador é composto por:
  - **Parte operativa** (execução): ALU, multiplexadores, etc.
  - **Unidade de controle**: orquestra os blocos.

- Modelo **Von Neumann**: instruções e dados ficam juntos na **memória** e são lidos sequencialmente pela CPU.

---

## 7.2 Linguagem de Máquina

- A **ISA (Instruction Set Architecture)** define o que a CPU pode fazer:
  - Operação (ex: ADD, MUL)
  - Entradas/saídas (registradores ou memória)
  - Próxima instrução a ser executada

- ISA é estável entre gerações (ex: Intel 286, 486, Pentium IV → mesma ISA).
- Cada instrução carrega toda a informação necessária para sua execução.
- Instruções de salto alteram o fluxo, quebrando a execução sequencial.

---

## 7.3 CISC × RISC

### CISC (Complex Instruction Set Computer)
- Muitas instruções, algumas complexas.
- Vantagem: código menor, menos esforço para programador.
- Ex: **x86** (Intel, AMD, etc.)
- Usado em desktops.
- Problema: instruções compostas são “engessadas”, dificultando otimizações.

### RISC (Reduced Instruction Set Computer)
- Poucas instruções, simples e rápidas.
- Vantagem: execução rápida, hardware menor, menos energia/calor.
- Ex: **MIPS, ARM, SPARC, PowerPC**
- Usado em sistemas embarcados.
- Desvantagem: exige mais código para tarefas complexas.

### Comparação
- RISC → código maior, mais rápido por instrução.
- CISC → código menor, instruções mais lentas.
- **Tendência atual**: arquiteturas híbridas que traduzem CISC para microinstruções RISC internamente.

---

## Conflito Central
- **Tamanho do código** (CISC) vs **desempenho e controle** (RISC).
