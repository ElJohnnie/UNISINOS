#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    c = a + b;
    printf("Sum: %d\n", c);
    return 0;
}