#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int *p;         // puntero a int
int *p[10];     // arreglo de 10 punteros a int
int (*p)[10];   // puntero a un arreglo de 10 int
int (*p)();     // puntero a una funcion que retorna int

// el ultimo puede apuntar a una parte de la memoria que guarda el codigo

// isupper()
size_t contar_mayusculas(const char* s){
    size_t count = 0;
    for (size_t i=0; s[i]; i++) {
        if(isupper(s[i])){
            count++;
        }  
    }
    // tambien puede ser
    // for(const char *c = s; *c != '\0'; c++)
    // if (isupper(*c))
    return count;
}

// islower()
size_t contar_minusculas(const char* s){
    size_t count = 0;
    for (size_t i=0; s[i]; i++) {
        if(islower(s[i])){
            count++;
        }  
    }
    return count;
}

// isdigit()
size_t contar_digitos(const char* s){
    size_t count = 0;
    for (size_t i=0; s[i]; i++) {
        if(isdigit(s[i])){
            count++;
        }  
    }
    return count;
}

// las 3 funciones utilizan el mismo algoritmo pero cambia la funcion 
// entonces vamos a crear UNA func con 2 parametros
// f es un puntero a una funcion que recibe y devuelve int
// el nombre de funcion es la posicion donde esta la funcion
size_t contar(const char* s, int (*f)(int) ){
    size_t count = 0;
    for (size_t i=0; s[i]; i++) {
        if(f(*c))(s[i]){
            count++;
        }  
    }
    return count;
}

// isupper()
size_t contar_mayus(const char* s){
    return contar(s, isupper);
}

// islower()
size_t contar_minus(const char* s){
    return contar(s, islower);
}

// isdigit()
size_t contar_dig(const char* s){
    return contar(s, isdigit);
}

// Que???
int *(*(*f[])(char))(); 
/* arreglo de tamanno no especificado de punteros a una funcion que 
recibe un char y devuelve un puntero a una func que no recibe nada y devuelve un punt a int
*/


// *** TIPO PUNTERO A FUNCION *** //
typedef int (*fchequeo_t)(int); // es un tipo que representa un puntero a una funcion que recibe int y devuelve int

size_t contar(const char* s, fchequeo_t f){
    size_t count = 0;
    for (size_t i=0; s[i]; i++) {
        if(f(*c))(s[i]){
            count++;
        }  
    }
    return count;
}


// *** VOID QSORT *** //
#include <stdlib.h>

// puntero a funcion que recibe 2 punteros genericos que devuelve 1 int
void qsort(
    void *base,     // arreglo de lo que quieras, int, char, etc.
    size_t nmemb,   // cant de bytes de cada elemento del arreglo
    size_t size,    // cant element del arreglos
    int (*compar)(const void *, const void *) // llamada a una func que recibe por parametro y devuelve int
);

// --> los punteros genericos no se pueden desreferenciar, primero tenes que castearlos a algun tipo


int main() {
    const char *s = "Hola Que Tal, Hoy es 25 de Mayo de 2021";
    printf("mayus: %zd, minus %zd, dig: %zd, alpha: %zd",
            contar_mayusculas(s),
            contar_minusculas(s),
            contar_digitos(s),
            contar(s, isalpha)); // tambien se podria llamar directo con el parametro de la func
    
    int (*funciones[])(int) = {isupper, islower, isdigit, isalpha, NULL}; // arreglo de punteros a funciones que reciben int y devuelven int
    for (int i = 0; i < 3; i++) {
        int (*function)(int) = funciones[i];
        size_t cant = contar(s, funcion);
    }

    fchequeuo_t funciones2[] = {isupper, islower, isdigit, isalpha, NULL}; // arreglo de punteros a funciones que reciben int y devuelven int

    return 0;
}

