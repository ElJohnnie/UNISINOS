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

    // Inicializa a matriz com valores de 1 a 100
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = i * MATRIX_SIZE + j + 1;
        }
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Erro ao criar processo filho");
        exit(1);
    } else if (pid == 0) {
        // Código do processo filho
        printf("Processo filho (PID: %d) - Baixando página e procurando palavra\n", getpid());
        char *args[] = {"/bin/sh", "-c", "curl -s https://www.example.com | egrep -o 'palavra' | wc -l", NULL};
        execvp(args[0], args);
        perror("Erro ao executar execvp");
        exit(1);
    } else {
        // Código do processo pai
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
    }

    return 0;
}