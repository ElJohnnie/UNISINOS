// Nome: Jonatha Rodrigo Follmer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MATRIX_SIZE 10

void print_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

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

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = i * MATRIX_SIZE + j + 1;
        }
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Erro ao criar pipe");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Erro ao criar processo filho");
        exit(1);
    } else if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        printf("Processo filho (PID: %d) - Baixando página e procurando palavra\n", getpid());
        char *args[] = {"/bin/sh", "-c", "curl -s https://linguagemc.com.br/criando-e-compilando-programa-em-c-pelo-gcc-ubuntu/ | egrep -o 'imagem' | wc -l", NULL};
        execvp(args[0], args);
        perror("Erro ao executar execvp");
        exit(1);
    } else {
        close(pipefd[1]);

        printf("Processo pai (PID: %d) - Calculando transposta da matriz\n", getpid());
        transpose_matrix(matrix, transposed);
        printf("Matriz original:\n");
        print_matrix(matrix);
        printf("Matriz transposta:\n");
        print_matrix(transposed);

        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Processo filho terminou com status %d\n", WEXITSTATUS(status));
        } else {
            printf("Processo filho terminou de forma anormal\n");
        }

        char buffer[128];
        read(pipefd[0], buffer, sizeof(buffer));
        close(pipefd[0]);
        printf("Número de ocorrências da palavra 'imagem': %s", buffer);
    }

    return 0;
}