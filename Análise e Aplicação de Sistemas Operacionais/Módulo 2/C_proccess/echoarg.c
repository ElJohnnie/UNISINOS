#include <stdio.h>  // Biblioteca padrão de entrada/saída
#include <stdlib.h> // Biblioteca padrão de funções utilitárias

int main(int argc, char *argv[]) {
    int i;  // Declaração da variável de índice

    // Loop para percorrer todos os argumentos passados na linha de comando
    for (i = 0; i < argc; i++) {
        // Imprime o índice e o valor do argumento correspondente
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    // Termina o programa com código de saída 0 (sucesso)
    exit(0);
}