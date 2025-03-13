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
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Função para calcular a transposta da matriz
void transpose_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int transposed[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int transposed[MATRIX_SIZE][MATRIX_SIZE];

    // Inicializa a matriz com valores de 1 a 100
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = i * MATRIX_SIZE + j + 1;
        }
    }

    // Cria um pipe para comunicação entre processos pai e filho
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Erro ao criar pipe");
        exit(1);
    }

    // Cria um novo processo
    pid_t pid = fork();

    if (pid < 0) {
        perror("Erro ao criar processo filho");
        exit(1);
    } else if (pid == 0) {
        // Código do processo filho
        close(pipefd[0]); // Fecha o lado de leitura do pipe
        dup2(pipefd[1], STDOUT_FILENO); // Redireciona a saída padrão para o pipe
        close(pipefd[1]); // Fecha o lado de escrita do pipe

        printf("Processo filho (PID: %d) - Baixando página e procurando palavra\n", getpid());
        // Executa o comando para baixar a página e contar a ocorrência da palavra 'imagem'
        char *args[] = {"/bin/sh", "-c", "curl -s https://linguagemc.com.br/criando-e-compilando-programa-em-c-pelo-gcc-ubuntu/ | egrep -o 'imagem' | wc -l", NULL};
        execvp(args[0], args);
        perror("Erro ao executar execvp");
        exit(1);
    } else {
        // Código do processo pai
        close(pipefd[1]); // Fecha o lado de escrita do pipe

        printf("Processo pai (PID: %d) - Calculando transposta da matriz\n", getpid());
        // Calcula a transposta da matriz
        transpose_matrix(matrix, transposed);
        printf("Matriz original:\n");
        print_matrix(matrix);
        printf("Matriz transposta:\n");
        print_matrix(transposed);

        // Espera o processo filho terminar
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Processo filho terminou com status %d\n", WEXITSTATUS(status));
        } else {
            printf("Processo filho terminou de forma anormal\n");
        }

        // Lê o resultado do pipe
        char buffer[128];
        read(pipefd[0], buffer, sizeof(buffer));
        close(pipefd[0]); // Fecha o lado de leitura do pipe
        printf("Número de ocorrências da palavra 'imagem': %s", buffer);
    }

    return 0;
}