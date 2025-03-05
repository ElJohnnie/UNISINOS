#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Define um tipo de função de comparação que aceita dois ponteiros para char e retorna um int
typedef int (*cmp_function)(const char *, const char *);

// Declaração da função 'check' que recebe duas strings e uma função de comparação
void check(char *a, char *b, cmp_function cmp);
// Declaração da função 'numcmp' que compara duas strings como números
int numcmp(const char *a, const char *b);

int main(void) {
    char s1[80], s2[80];

    // Lê duas strings do usuário
    printf("Enter first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0'; // Remove o caractere de nova linha

    // Verifica se o primeiro caractere da primeira string é uma letra
    if(isalpha(*s1)) 
        // Se for uma letra, usa 'strcmp' para comparar as strings
        check(s1, s2, strcmp);
    else 
        // Se não for uma letra, usa 'numcmp' para comparar as strings como números
        check(s1, s2, numcmp);

    return 0;
}

// Função que verifica a igualdade de duas strings usando uma função de comparação
void check(char *a, char *b, cmp_function cmp) {
    printf("Testing for equality.\n");
    // Chama a função de comparação passada como argumento
    if(!(*cmp)(a, b)) 
        printf("Equal\n");
    else 
        printf("Not equal\n");
}

// Função que compara duas strings como números
int numcmp(const char *a, const char *b) {
    // Converte as strings para inteiros e compara
    if(atoi(a) == atoi(b)) 
        return 0;
    return 1;
}