#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void push(int i);
int pop(void);
int *tos, *p1, stack[SIZE];

int main(void) {
    int value;
    tos = stack; /* faz tos conter a base da pilha */
    p1 = stack; /* Inicializa p1 */

    do {
        printf("Enter value: ");
        scanf("%d", &value);
        if (value != 0) push(value);
        else printf("Value on top is: %d\n", pop());
    } while (value != -1);
}

void push(int i) {
    if (p1 == (tos + SIZE)) {
        printf("Stack Overflow.\n");
        exit(1);
    }
    p1++;
    *p1 = i;
}

int pop(void) {
    if (p1 == stack) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    p1--;
    return *p1;
}