#include <stdio.h>

int main() {
    // Declaring variables with different type modifiers
    short int shortVar = 32767; // short int
    unsigned short int uShortVar = 65535; // unsigned short int
    int intVar = 2147483647; // int
    unsigned int uIntVar = 4294967295U; // unsigned int
    long int longVar = 9223372036854775807L; // long int
    unsigned long int uLongVar = 18446744073709551615UL; // unsigned long int

    // Printing the values of the variables
    printf("short int: %d\n", shortVar);
    printf("unsigned short int: %u\n", uShortVar);
    printf("int: %d\n", intVar);
    printf("unsigned int: %u\n", uIntVar);
    printf("long int: %ld\n", longVar);
    printf("unsigned long int: %lu\n", uLongVar);

    return 0;
}