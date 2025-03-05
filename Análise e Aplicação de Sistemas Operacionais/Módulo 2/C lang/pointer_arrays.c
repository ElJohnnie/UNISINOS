#include <stdio.h>
#include <string.h>

int main() {
    char *str[10];
    char buffer[100];
    char copy[100];
    char *substring;

    // Inicializa o array de ponteiros com algumas strings
    str[0] = "Hello";
    str[1] = "World";
    str[2] = "This";
    str[3] = "Is";
    str[4] = "A";
    str[5] = "Pointer";
    str[6] = "Array";
    str[7] = "Example";
    str[8] = "In";
    str[9] = "C";

    // Imprime as strings
    for (int i = 0; i < 10; i++) {
        printf("%s\n", str[i]);
    }

    // Concatena todas as strings em um único buffer
    buffer[0] = '\0'; // Inicializa o buffer com uma string vazia
    for (int i = 0; i < 10; i++) {
        strcat(buffer, str[i]);
        strcat(buffer, " ");
    }

    // Imprime a string concatenada
    printf("Concatenated string: %s\n", buffer);

    // Copia a primeira string para o buffer de cópia
    strcpy(copy, str[0]);
    printf("Copied string: %s\n", copy);

    // Compara duas strings
    if (strcmp(str[0], str[1]) == 0) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }

    // Busca uma substring
    substring = strstr(buffer, "Pointer");
    if (substring != NULL) {
        printf("Substring found: %s\n", substring);
    } else {
        printf("Substring not found\n");
    }

    return 0;
}