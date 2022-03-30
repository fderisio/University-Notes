#include <stdio.h>

char w = 'W';
char x = 'X';
char y = 'Y';
char z = 'Z';

void func(char x, char y) {
    w = 'W'; // modifica a la global
    x = '+'; // modifica al parámetro
    printf("%c %c %c %c\n", w, x, y, z); // w + Y Z
    char z = 'z';
    printf("%c %c %c %c\n", w, x, y, z); // w + Y z
}

int main() {
    char x = 'x';
    printf("%c %c %c %c\n", w, x, y, z); // W x Y Z
    f(x, y);
    printf("%c %c %c %c\n", w, x, y, z); // w x Y Z
    return 0;
}

// retorno
// W x Y Z
// w + Y Z
// w + Y z
// w x Y Z

// las variables locales viven en el stack
// las funciones tienen lugar privado en el stack
// lugar privado = marco de la funcion (lugar en el stack)

// las variables globales SOLO deben ser CONST
