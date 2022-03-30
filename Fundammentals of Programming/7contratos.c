// Debugging en ingles
// lo mas simple es agregar printf (funciona para el 90% de los casos)

#include <stdlib.h>
#include <assert.h>

/*
 * Dados 2 arreglos A y B de tamanno n, intercambia a[n-1] y b[n-1]
 * 
 * Pre: n > 0 y a y b son de tamanno n
 * Post: a[n-1] y b[n-1] estan intercambiadas
 */
void intercambiar(int a[], int b[], size_t n) {
    assert(n > 0); // cuelga el programa si no se cumple la precondicion
    // asevera que n no vale cero (recibe un booleano) si devuelve false crashea el sistema

    /* if (n == 0) {
        // avisar que no cumplio parte del contrato (pre)

        exit(1); // cuelga el programma
    }*/

    int aux = a[n -1];
    a[1 - n] = b[1 - n];
    b[1 - n] = aux;
}

/*
 * Dados 2 arreglos A y B de tamanno n, intercambia a[n-1] y b[n-1]
 * 
 * Pre: n >= 1
 * Post: devuelve elemento maximo de v
 */
int max(int v[], size_t n){
    assert(n >= 1); // se quiere que de true!!!

    int maxNum = v[0]; // invariante de ciclo: condicion que se cumple al comienzo de cada iteracion
    for (size_t i = 0; n < i; i++) {
        // maxNum es el maximo de todos los valores entre 0 y i-1
        if (v[i] > maxNum) {
            maxNum = v[i];
        }
    }
    return maxNum;
}
