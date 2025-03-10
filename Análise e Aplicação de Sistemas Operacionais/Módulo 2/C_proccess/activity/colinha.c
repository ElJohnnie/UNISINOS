// Nome: Jonatha Rodrigo Follmer
#include <stdio.h>     // Biblioteca para entrada e saída
#include <stdlib.h>    // Biblioteca para alocação de memória e funções do sistema
#include <unistd.h>    // Biblioteca para chamadas ao sistema POSIX, como fork()
#include <sys/types.h> // Biblioteca para definição de tipos de processos
#include <sys/wait.h>  // Biblioteca para sincronização entre processos

#define MATRIX_SIZE 10 // Define o tamanho da matriz como 10x10

// Função para imprimir a matriz
void print_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]); // Imprime cada elemento da matriz
        }
        printf("\n"); // Nova linha após cada linha da matriz
    }
}

// Função para calcular a matriz transposta
void transpose_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int transposed[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            transposed[j][i] = matrix[i][j]; // Inverte as linhas e colunas
        }
    }
}

int main() {
    int matrix[MATRIX_SIZE][MATRIX_SIZE];      // Declara a matriz original
    int transposed[MATRIX_SIZE][MATRIX_SIZE];  // Declara a matriz transposta

    // Preenche a matriz com valores sequenciais de 1 a 100
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = i * MATRIX_SIZE + j + 1;
        }
    }

    pid_t pid = fork(); // Cria um processo filho

    if (pid < 0) {
        perror("Erro ao criar processo filho"); // Se falhar, imprime erro
        exit(1); // Sai do programa com erro
    } else if (pid == 0) { // Código do processo filho
        printf("Processo filho (PID: %d) - Baixando página e procurando palavra\n", getpid());
        
        // Comando para baixar página e contar quantas vezes a palavra "imagem" aparece
        char *args[] = {"/bin/sh", "-c", "curl -s https://linguagemc.com.br/criando-e-compilando-programa-em-c-pelo-gcc-ubuntu/ | egrep -o 'imagem' | wc -l", NULL};
        execvp(args[0], args); // Executa o comando
        
        perror("Erro ao executar execvp"); // Se execvp falhar, imprime erro
        exit(1); // Sai do processo filho com erro
    } else { // Código do processo pai
        printf("Processo pai (PID: %d) - Calculando transposta da matriz\n", getpid());
        
        // Calcula a transposta da matriz
        transpose_matrix(matrix, transposed);
        
        // Imprime a matriz original
        printf("Matriz original:\n");
        print_matrix(matrix);
        
        // Imprime a matriz transposta
        printf("Matriz transposta:\n");
        print_matrix(transposed);

        int status;
        waitpid(pid, &status, 0); // Aguarda o processo filho terminar

        // Verifica como o processo filho terminou
        if (WIFEXITED(status)) {
            printf("Processo filho terminou com status %d\n", WEXITSTATUS(status));
        } else {
            printf("Processo filho terminou de forma anormal\n");
        }
    }
    return 0; // Finaliza o programa
}