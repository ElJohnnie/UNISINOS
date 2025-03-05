#include <stdio.h>    // Biblioteca padrão de entrada/saída
#include <unistd.h>   // Biblioteca para chamadas ao sistema POSIX
#include <sys/types.h> // Definições de tipos de dados usados em chamadas ao sistema
#include <pwd.h>      // Biblioteca para manipulação de senhas e informações de usuários
#include <grp.h>      // Biblioteca para manipulação de grupos

int main() {
    // Obtém o ID do usuário atual
    uid_t uid = getuid();
    // Obtém o ID do grupo atual
    gid_t gid = getgid();

    // Obtém a estrutura passwd para o usuário atual
    struct passwd *pw = getpwuid(uid);
    // Obtém a estrutura group para o grupo atual
    struct group *gr = getgrgid(gid);

    // Verifica se as estruturas foram obtidas com sucesso
    if (pw != NULL && gr != NULL) {
        // Imprime o ID do usuário e o nome do usuário
        printf("ID do usuário (UID): %d\n", uid);
        printf("Nome do usuário: %s\n", pw->pw_name);

        // Imprime o ID do grupo e o nome do grupo
        printf("ID do grupo (GID): %d\n", gid);
        printf("Nome do grupo: %s\n", gr->gr_name);
    } else {
        // Caso ocorra um erro ao obter as informações
        fprintf(stderr, "Erro ao obter informações do usuário ou grupo.\n");
        return 1; // Termina o programa com código de saída 1 (erro)
    }

    return 0; // Termina o programa com código de saída 0 (sucesso)
}