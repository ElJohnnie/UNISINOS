#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;

    // Solicita ao usuário o tamanho do array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Aloca memória dinamicamente para o array
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Inicializa o array com valores
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Imprime os valores do array
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(arr);

    return 0;
}