#include <stdio.h>
#include <stdbool.h>

bool f() {
    printf("en f()");
    return false;
}

bool g() {
    printf("en g()");
    return true;
}

bool esPar(int n) {
    return !(n % 2); // es igual que: return (n % 2 == 0)
}

int main () {

    /**** corto circuito!! ****/
    bool r = f() && g();
    printf("r = %d", r); // imprime f() porque la primer funcion es falsa, entonces no se ejecutan las 2

    bool s = g() && f();
    printf("r = %d", s); // imprime en f() porque la primer
    // se ejecutan las dos funciones porque la primera es true

    /**** igualar a cero ****/
    // if (x != 0) es igual que if (x)
    // if (x == 0) es igual a if (!x)

    /**** es par? ****/

    return 0;
}
