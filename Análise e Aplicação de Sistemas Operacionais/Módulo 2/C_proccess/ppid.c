#include <stdio.h>  // Biblioteca padrão de entrada/saída
#include <unistd.h> // Biblioteca para chamadas ao sistema POSIX

int main() {
    // Obtém o ID do processo atual
    pid_t pid = getpid();
    // Obtém o ID do processo pai
    pid_t ppid = getppid();

    // Imprime o ID do processo atual
    printf("ID do processo atual (PID): %d\n", pid);
    // Imprime o ID do processo pai
    printf("ID do processo pai (PPID): %d\n", ppid);

    return 0; // Termina o programa com código de saída 0 (sucesso)
}