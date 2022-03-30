#include <stdio.h>
#include <stdlib.h>

// cuando declaro variable se reserrva memoria
// con un arreglo de 4 se reservan 4 lugares en la memoria

// vector con contenido basura
int valores1[4];

// el compilador es bueno y se inicializan con 10, 20, 0, 0
int valores2[4] = {10, 20};  

// para inicializar todos los valores con cero
int valores3[4] = {0};

// para inicializar todos cero salvo uno o dos
int valores4[4] = { [1]=20 };
int valores5[4] = { [1]=20, [3]=10 };

// en la posicion 1 es 20 y la siguiente 32
int valores6[4] = { [1]=20, 32 };


/*** sizeof() ARREGLO ***/
// si lo recibis como parametro podes no identificar el length
void f(int valores[]) { 
    printf("%p dir de memoria\n", valores); // direccion memoria donde empieza valores
    printf("%zd sizeof de arreglo\n", sizeof(valores)); // 8 (lo que ocupa la direccion de memoria)
}

// cuando un vector pasa como parametro se dice que decae como puntero
// lo unico que recibe como parametro es la direccion, solo sabe donde empieza y no donde termina
// la direccion ocupa 8 bytes por eso devuelve 8
// el compilador no sabe cuanto ocupa ese arreglo


/*** IMPRIMIR ARREGLO ***/
// siempre hay que pasar 2 parametros, el arreglo y cant de elem
// por convención n = cantElementos
void imprimirArreglo(int valores[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", valores[i]);
    }
}
// off by one: cuando se empieza de 0, pero te pasas de 1.
// ej: for (int i = 0; i <= n; i++) {


/*** devolver longitud cadena ***/
int lognitudCadena(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}
// incluida en string.h
// --> size_t strlen(const char *s);
// size_t es un tipo de dato definido en stdlib.h --> entero positivo
// typedef unsigned ??? size_t;
// size_t se utiliza para representar el tamaño de un valor almacenado en memoria en bytes

int main() {
    // se pueden modificar los valores de cualquier arreglo
    int valores[] = {10 , 20, 30, 40, 50};
    valores[1] = 100; // --> OK
    // valores[4] = 5; --> no hay memoria
    // valores[15000000] = 5; --> al ejecutarse el SO lo va a matar

    int valores7[] = {10, 20, 30, 40};
    printf("%d \n", sizeof(int));       // 4
    printf("%zd \n", sizeof(valores7));  // 20
    printf("%p \n", valores7);  // dirección de memoria donde vive el vector

    f(valores7);

    /*** MATRICES ***/
    // inicilizacion por filas
    int M[4][3] = {   // Matriz M
        {1},          //  1 0 0 --> inicializa solo el primer elemento de la fila
        {0, 2},       //  0 2 0
        {3, [2]=4}    //  3 0 4
    };                //  0 0 0 --> ultima fila vacia  

    int A[4][3] = {   // Matriz A
        [0][1] =3,    //  0 3 0 --> inicializa solo el primer elemento de la fila
        [2][2]=7      //  0 0 0
    };                //  0 0 7
                      //  0 0 0 --> ultima fila vacia  
    
    // NO HACER!!!! faltan llaves en el medio para delinear las filas
    int B[4][3] = {1, 3, 5, 2, 4 , 6, 3, 5, 7};
    // 1 3 5
    // 2 4 6
    // 3 5 7
    // 0 0 0
    

    /***    ARREGLO STRING EQUIVALENCIAS     ***/
    char sa[] = "hola"; // en memoria se reserva lugar para 5 caracteres
    // stack: 104 111 108 97 0
    char sb[] = {104, 111, 108, 97, 0};
    char sc[] = {'h', 'o', 'l', 'a', '\0'};

    // 0 al final: convencion que todas las cadenas terminen en 0 (en ASCII es nulo) el digito 0 es 48 en ASCII

    // comillas simples para representar caracter
    // comillas dobles para representar cadena de caracteres
    // 'h' es un character
    // "h" es un string --> memoria 2 lugares: h 0


    /***    SECUENCIAS DE ESCAPE (escape sequences)    ***/
    // (no solo funcionan con printf, tambien dentro de strings)
    // fin de linea
    
    //printf("hola
    //            que tal"); NO COMPILA!!!!
    printf("hola %c que tal", 0x0A);
    printf("hola %c que tal", 10);
    printf("hola %c que tal", 0); // el printf sabia que seguia la cadena y no freno en el 0
    printf("hola \000 que tal"); // hola
    printf("hola %c que tal", 0x0A);

    // \a suena una campana

    char s1[] = "hola";
    char s2[] = "hola";
    //if (s1 == s2) --> NO COMPARA cadenas, solo posiciones de memoria y siempre da false
    // para comparar cadenas, hay que hacer caracter a caracter
    // if s1[0] == s2[0] y asi con cada caracter
    // if (strcmp(s1, s2 == 0)) 

    /*** ENTRADA/SALIDA EN stdio.h ***/
    // entrada - stdin (default: teclado)
    int getchar(); // lee un character y devuelve un entero
    char *fgets(char *dest, int n, FILE *source); // leer linea completa de caracteres, interactua con ususario

    // salida - stdout (default: terminal)
    int putchar(int c); // muestra un caracter
    int puts(const char *s); // imprime una cadena man 3puts agrega el \n automatico
    int printf(const char *format, ...);

    // la diferencia entre pputs y printf es que puts agrega el fin de lineA
    // printf permite cadena de formato con distintos tipos de valores dentro 

    char edad[30];
    fgets(edad, 30, stdin);

    // Transformar string a numero
    // #include <stdlib.h>
    int n = atoi(edad);
    // atof() --> devuelve double
    // strtol() -->

    return 0;
}

//El estandar de C llama "comportamiento no definido" a tratar de agregr un elemento en arerglo[-1]
