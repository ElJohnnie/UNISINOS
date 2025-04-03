# Módulo 3

Este módulo aborda comunicação entre processos e sinais no Linux.

## Conteúdo

### Comunicação
- **pipe1.c**: Demonstra comunicação entre processos usando pipes.
- **pipe2.c**: Exemplo de leitura e escrita em pipes com `fork`.
- **pipe3.c**: Integração de pipes com `exec`.
- **pipe4.c**: Programa auxiliar para leitura de dados de um pipe.
- **pipe5.c**: Demonstração de uso de `dup` e `exec` com pipes.

### Sinais
- **ctrl1.c**: Exemplo de tratamento de sinais com `signal`.
- **ctrl2.c**: Uso de `sigaction` para manipulação de sinais.
- **alarm.c**: Demonstração de uso do sinal `SIGALRM` para temporizadores.