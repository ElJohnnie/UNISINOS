#include <stdio.h>

void main(void) {
    int x, *p, **q;

    x = 10;
    p = &x;  // 'p' é um ponteiro para 'x', armazenando o endereço de 'x'
    q = &p;  // 'q' é um ponteiro para 'p', armazenando o endereço de 'p'

    // Imprime o valor de 'x'
    printf("Valor de x: %d\n", x);
    // Imprime o endereço de 'x'
    printf("Endereço de x: %p\n", &x);
    // Imprime o valor de 'p' (endereço de 'x')
    printf("Valor de p: %p\n", p);
    // Imprime o endereço de 'p'
    printf("Endereço de p: %p\n", &p);
    // Imprime o valor apontado por 'p' (valor de 'x')
    printf("Valor de *p: %d\n", *p);
    // Imprime o valor de 'q' (endereço de 'p')
    printf("Valor de q: %p\n", q);
    // Imprime o endereço de 'q'
    printf("Endereço de q: %p\n", &q);
}