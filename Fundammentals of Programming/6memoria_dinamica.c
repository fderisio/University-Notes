#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// crear funcion que reciba una cadena y un numero y la repita por esa cantidad
void repetirOptA(int n, const char *s, char buf[]);
char *repetirOptB(int n, const char *s);


/* char *repetirOptB(int n, const char *s) {
    size_t len = strlen(s);
    char result[n * strlen(s) + 1]; // NO HAY QUE HACER!!!! porque devuelve direccion memoria de ver local   
    for (int i = 0; i < n; i++) {
        strcpy(&result[i * len], s);
    }
    return result; // char * = char[] un arreglo ya es una direccion de memoria
    // retorna direccion de memoria de variable local!!!!!!
} */

// los punteros pueden apuntar al stack, al heap
// para que funcione hay que guardar el resultado en el heap --> llamando a la funcion malloc

char *repetirOptB(int n, const char *s) {
    size_t len = strlen(s);
    char *result = malloc(n * len + 1);

    if (*result == NULL) {
        printf("not enought memory");
        return NULL;
    } else {
        for (int i = 0; i < n; i++) {
            strcpy(&result[i * len], s);
        }
    }
    // aca no se libera memoria porque sino pasa lo mismo y no devuelve
    return result;
}

int main() {
    // malloc = memory allocate (recibe un parametro, la cant de bytes)
    // void * malloc = devuelve malloc * porque no se sabe que tipo de dato se guarda en esa memoria
    // ej para reservar 200 enteros:
    int *p = /* casteo implicito de void* a int* */ malloc(200 * sizeof(int));
    // la memoria reservada existe para siempre hasta que hagamos free()
    free(p); // casteo automatico de puntero int a puntero void *
    // free no borra datos, sino que la memoria puede ser utilizada para otra cosa
    // malloc puede fallar, si no se puede alocar la memoria devuelve NULL
    if (p == NULL) {
        // todo bien
    } else {
        // todo mal
        free(p);
    }

    char *s = repetir(3, "hola"); // si esta funcion puede devolver NULL tambien hay que chequearlo
    if (s == NULL) {
        printf(":( \n");
        return 1;
    }
    printf("%s \n", s);
    free(s);

    /* ***** EJERCICIOS ***** */

    // EJER 1
    int *p, *q;
    p = malloc(10 * sizeof(int)); // p apunta a una direccion de memoria
    q = p; // q apunta a la misma direccion que p
    free(p); // se libera p
    free(q); // NO ES NECESARIO!! ya fue liberada con p

    // EJER 2
    int *punt = malloc(10 * sizeof(int)); // p apunta a una direccion de memoria
    free(punt + 5); // punt + 5 apunta a la mitad del bloque de memoria guardado, NO se puede!!
    // el puntero creado con malloc, es el que SE TIENE QUE PASAR EN free()


    // EJER 3
    // quiero guardar una cadena en heap
    char *p = malloc(5); // con char no es necesario sizeof porque c/u es 1 byte.
    p = "hola"; // NOOO cuando se escribe una cadena, solo vive en donde se puede leer pero no escribir
    // en cuanto un puntero a malloc (direccion heap) se iguala a una cadena, automaticamente
    // pasa a apuntar una direccion de la memoria "data" y no al heap, ni siquiera 
    strcpy(p, "hola"); // OK!!


    // EJER 4
    // quiero guardar un arreglo en heap
    int *p = malloc(3 * sizeof(int));
    memcpy(p, (int[3]){10, 20, 30}, 3 * sizeof(int)); // (puntero, lo que quiero guardar, cuantos lugares)

    // EJER 5
    // reserve memoria pero necesito mas lugar
    char *p = malloc(5);
    strcpy(p, "hola");
    // necisto mas lugar!!
    // OPt 1
    char *aux = malloc(10);
    memcpy(aux, p, 5);
    free(p);
    p = aux;
    strcpy(p + 4, "chau");
    
    // Opt 2
    char *aux = realloc(p, 10);
    // primero intenta reserva mas memoria, si realloc falla, devuelve NULL pero no la memoria anterior no se libera
    // memory leak = reservar memoria sin liberarla
    // entonces primero tenemos que evaluar si da NULL
    if (aux == NULL) { // puede ser NULL porque realloc llama a malloc
        // todo mal
    } else {
        // todo bien
        p = aux;
    }
    free(p);

    // EQUIVALENCIAS
    malloc(0);          // le puedo pedir 0 bytes retorna siempre NULL --> devuelve puntero nulo
    free(NULL);         // es valido
    realloc(NULL, n);   // equivale a: malloc(n)
    realloc(p, 0);      // equivale a: free(p)

    // CUANDO USAR MEMORIA DINAMICA
    // --> para una funcion que devuelve una cadena nueva
    // --> para devolver arreglos dinamicos y no se sabe que tamaño tendra

    // 1) declaro memoria para un arreglo de 5 enteros
    int *arreglo_heap = malloc(5 * sizeof(int));
    // 2) para acceder a un valor del arreglo en i=3
    int valor = p[3]; // tambien es valido *(p+3);

    // --> arreglo a punteros de elementos dinamicos
    // por ejemplo: un libro con 5 autores
    // declaro un arreglo de punteros (en el stack) que apuntan a contenido del heap
    char *arreglo_char[5];
    arreglo_char[0] = malloc(20); // hay que hacer a un malloc por cada uno
    arreglo_char[1] = malloc(7);
    // 2) para acceder a un valor del arreglo string
    char valor_string = arreglo_char[2][10]; 
    
    // **** arreglo dinamico de punteros a cosas dinamicas
    // si necesito que algunos libros tengan 4 autores y otros 6
    // todo vive en el heap
    // p_stack vive en el stack y sera un pentero a un arreglo completo en heap
    char **p_a_puntero_heap = malloc(5 * sizeof(char *)); // doble casteo de p_stack para que sea puntero de un puntero
    p_a_puntero_heap[0] = malloc(5); // este elemento ya esta en el Heap
    p_a_puntero_heap[1] = malloc(22);

    // OJO CON EL FREE!!
    // 1) hacer free de cada uno
    free(p_a_puntero_heap[0]);
    free(p_a_puntero_heap[1]);
    free(p_a_puntero_heap[2]);
    free(p_a_puntero_heap[3]);
    free(p_a_puntero_heap[4]);

    // 2) despues free al arreglo
    free(p_a_puntero_heap);

    // **** matrices dinamicas a cosas del mismo tamanno
    int **p_stack = malloc(4 * sizeof(int)); // 4 filas
    p[0] = malloc(5 * sizeof(int)); // 5 columnas
    p[1] = malloc(5 * sizeof(int));
    p[2] = malloc(5 * sizeof(int));
    p[3] = malloc(5 * sizeof(int));

    // tambien hacer un solo malloc para toda la matriz
    int *p_matrix = malloc(20 * sizeof(int));
    // para acceder a un elemento hay que hacer cuenta a mano
    int value = p[1 * 5 + 2]; // ir al 3er elemento de la 2da fila
    // 5 x cant filas + cant de col

    /***** CONCLUSION *****/
    // NO SE PUEDE agrandar algo en el stack --> se llama memoria estatica
    // stack --> una vez declarada la memoria no se puede cambiar
    // heap --> memoria dinamica
    // tener en cuenta el tipo de puntero para llamar a malloc
    // tener en cuenta en que orden llamar a free
    
    return 0;
}
