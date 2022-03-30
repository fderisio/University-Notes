#include <stdio.h>
#include <string.h>
#include <stddef.h>

void f(int v){
    v = 5;
}

void fPunt(int *v){
    *v = 5;
}

/*** FUNCION PARA DEVOLVER MAS DE UN VALOR ***/
void pasarAhsm(int segundos, int *h, int *m, int *s){
    *h = segundos / 3600;
    *m = (segundos % 3600) / 60;
    *s = (segundos % 3600) % 60;
}

int main() {
    int i = 4;
    f(i);
    printf("%d \n", i); // siempre va a dar 4
    fPunt(&i); // manda como parametro la direccion de memoria de i
    printf("%d \n", i); // 5

    float x = 3.14;
    float *p = &x;
    printf("%p", &x);   // dirección donde vive x
    printf("%p", p);    // contenido de p (dirección de x)
    printf("%p", &p);   // dirección donde vive p
    printf("%f", *p);   // contenido de la dirección que guarda
    // el valor de a donde apunta p
    
    // Funcion para devolver varios resultados --> void con puntero
    int h;
    int m;
    int s;
    pasarAhsm(582, &h, &m, &s);


    /*** ARREGLOS VS PUNTEROS ***/
    int valores[] = {10, 20, 30, 40};
    int *p2 = valores;
    printf("%p \n", p2);        // dirección donde vive valores
    printf("%p \n", valores);   // dirección de memoria donde empieza el arreglo
    printf("%d \n", *p2);       // valor del lugar de memoria
    printf("%d \n", *valores);  // valor del lugar de memoria


    int values[4];
    int *p3;
    p3 = values;
    // values = p; --> NO!! el arreglo no puede apuntar a otro lado
    sizeof(values); // 16  (solo si el compilador sabe el tamano del arreglo)
    sizeof(p); // 8


    char a[] = "hola"; // ocupa 5 espacios de memoria stack (4+1)
    char *p4 = "hola"; // guarda p  en el stack y la palabra hola+0 en otra region de la que solo se puede LEER
    // el segundo ocupa mucho mas espacio

    // Que hace le compilador? VENTAJA
    char *q = "hola";
    char *qq = "hola";
    printf("%p \n", q);
    printf("%p \n", qq); 
    // como los strings son iguales y para ahorrar memoria ambos llaman al mismo lugar
    // en vez de muchas copias de una cadena, muchos punteros a una misma cadena
    
    

    /*** ARITMETICA DE PUNTEROS ***/
    int *p5 = valores;
    printf("%p \n", p5);       // memoria donde empieza valores
    printf("%d \n", *p);       // 10
    printf("%d \n", p5[0]);    // 10
    printf("%p \n", p5 + 2);   // posicion de memoria + 2, es el tercer lugar.
    printf("%p \n", *(p5 + 2));// 30
    printf("%d \n", p5[2]);    // 30

    // p[x] = *(p + x)
    // para usar arreglos: p[x] 
    // para usar punteros: *(p + x)
    // cuando el compilador ve p[x] lo tranforma a la otra forma
    

    /*** PUNTERO GENERICO - VOID * ***/
    
    // p6 **** primer uso de puntero void*
    // string.h hay muchas funciones para trabajar con arreglos de chars
    void *memcpy(void *dest, const void *src, size_t n);
    int n = 42;
    char c = 8;
    void *p6 = &n; // permite definir un puntero sin saber que tipo de dato es n
    p6 =  &c;

    // p7 **** casteo de punteros void *
    int num[] = {0x1a2b3c4d, 0x5a6b7c8d}; // hex cada 2 caract es un byte 1a 2b 3c 4d
    void *p7 = n;
    // printf("%d \n", *p7); // NO SE PUEDE, no sabe de que tipo es
    // castear el punteroa int
    printf("0x%x \n", *(int*)p7);       // 0x1a2b3c4d
    printf("0x%x \n", *(char*)p7);      // 0x4d  
    // !little-endien guarda en memoria el bit mas significativo al final 
    // 4d 3c 2b 1a 8d 7c 6b 5a
    // en big-endian se guarda bien 
    printf("0x%x \n", *((int*)p7+1));  // 0x5a6b7c8d
    printf("0x%x \n", *(int*)(p7+1));  // (p7+1) se avanza de a 1 byte y despues castea
    // retorna 8d 1a 2b 3c


    /*** PUNTEROS A NADA ***/
    // en cabecera stddef.h --> #define NULL (void *)0
    int *p = NULL;

    /*** BONUS TRACK ***/
    // stdlib.h
    int atoi(const char *string);
    long strlon(const char *string, char **endptr, int base);
    double strtod(const char *string, char **endptr);

    // char ** --> devuelve un puntero a char*
     
    return 0;
}