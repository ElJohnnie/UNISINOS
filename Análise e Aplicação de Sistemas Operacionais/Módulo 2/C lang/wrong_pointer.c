#include <stdio.h>

int main(int argc, char* argv[]) {
    float x = 3.5, y;
    int *p;

    p = &x;
    y = *p;

    printf("O valor de x, apontado por p é: %f\n", y);
}

// Output:
// wrong_pointer.c: In function ‘main’:
// wrong_pointer.c:7:7: warning: assignment to ‘int *’ from incompatible pointer type ‘float *’ [-Wincompatible-pointer-types]
// 7 |     p = &x;
//  |      ^