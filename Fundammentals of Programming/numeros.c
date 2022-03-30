#include <stdio.h>

int main() {
    // ejemplo numeros 
    unsigned char num1 = 255;
    printf("Numero original: %d \n", num1);
    num1 = num1 + 1;
    printf("Le sumamos 1: %d \n", num1); // da 0

    signed char num2 = 127;
    printf("Numero original: %d \n", num2);
    num2 = num2 + 1;
    printf("Le sumamos 1: %d \n", num2); // da –128*

    return 0;
}
