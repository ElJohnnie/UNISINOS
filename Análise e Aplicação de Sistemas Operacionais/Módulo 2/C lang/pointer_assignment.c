#include <stdio.h>

int main(int argc, char* argv[]) {
    int x;
    int *p1, *p2;

    p1 = &x;
    p2 = p1;

    printf("Endereço de x: %p\n", &x);
    printf("Endereço de p1: %p\n", p1);
    printf("Endereço de p2: %p\n", p2);
}