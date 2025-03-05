#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Declaração e inicialização de strings
    char str1[50] = "Hello, ";
    char str2[] = "World!";
    char str3[100];
    
    // Concatenar strings
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
    
    // Copiar strings
    strcpy(str3, str1);
    printf("Copied string: %s\n", str3);
    
    // Comprimento da string
    printf("Length of str3: %lu\n", strlen(str3));
    
    // Comparar strings
    if (strcmp(str1, str3) == 0) {
        printf("str1 and str3 are equal\n");
    } else {
        printf("str1 and str3 are not equal\n");
    }
    
    // Encontrar substring
    char *substr = strstr(str3, "World");
    if (substr) {
        printf("Substring found: %s\n", substr);
    } else {
        printf("Substring not found\n");
    }
    
    // Converter para maiúsculas
    for (int i = 0; str3[i]; i++) {
        str3[i] = toupper(str3[i]);
    }
    printf("Uppercase string: %s\n", str3);
    
    // Converter para minúsculas
    for (int i = 0; str3[i]; i++) {
        str3[i] = tolower(str3[i]);
    }
    printf("Lowercase string: %s\n", str3);
    
    // Dividir string
    char str4[] = "Hello, World! Welcome to C programming.";
    char *token = strtok(str4, " ");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }
    
    return 0;
}