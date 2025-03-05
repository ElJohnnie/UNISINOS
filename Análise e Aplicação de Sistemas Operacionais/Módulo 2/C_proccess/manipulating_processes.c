#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Erro ao criar processo filho");
        exit(1);
    } else if (pid == 0) {
        // Código do processo filho
        printf("Processo filho (PID: %d)\n", getpid());
        char *args[] = {"/bin/ls", "-l", NULL};
        execvp(args[0], args);
        perror("Erro ao executar execvp");
        exit(1);
    } else {
        // Código do processo pai
        printf("Processo pai (PID: %d), esperando o filho (PID: %d) terminar\n", getpid(), pid);
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