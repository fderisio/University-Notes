#include <stdint.h>

uint8_t age_jane = 23; // unsigned int de 8 bits

// int8_t --> 8 bits
// int16_t --> 16 bits
// int32_t --> 32 bits

// uint8_t --> 8 bits
// uint16_t --> 16 bits
// uint32_t --> 32 bits

// Enums
typedef enum {LUN, MAR, MIE, JUE, VIE, SAB, DOM} tDia;
tDia dia = VIE; // stack --> diaClase = 4

// Equivalente a 
#define LUN 0
#define MAR 1 // etc...

// <stdbool.h>
typedef _Bool bool;
#define false 0
#define true 1;

// do while
int i = 0;
do {
    //instruccion o bloque
} while (i < 20);

// switch
switch (dia) {
    case LUN:
        printf("Es lunes");
        break;
    case SAB:  // tanto SAB como DOM ejecuta el mismo printf
    case DOM:
        printf("Finde!");
        break;
    default:
        printf("Uffff....");
        break;
}
