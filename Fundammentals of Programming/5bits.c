#include <stdio.h>
#include <stdbool.h>

// RGB 24 bit Color: Red=8 bits, Green=8bits, Blue=8bits

// 255 0 0 es rojo
// 255 255 255 blanco
// 0 0 0 negro
// 0 255 0 verde

// # Color HEX
// 45 70 45 = #2d 46 2d

// En C

/*** FLAGS ***/
// no puede haber mas de 32 tipos con esta tecnica - 32bits
typedef enum {
    AGUA=0,     // 0000 0001
    FUEGO,      // 0000 0010
    TIERRA,     // 0000 0100
    ELECTRICO,  // 0000 1000
    PLANTA,     // 0001 0000
    VENENO      // 0010 0000
} tipo_pokemon_t;

tipo_pokemon_t tipo_pikachu = ELECTRICO;
tipo_pokemon_t tipo_charmander = FUEGO;
tipo_pokemon_t tipo_pikachu = PLANTA | VENENO;

bool es_tipo_tierra(tipo_pokemon_t t){
    return (t & TIERRA) != 0; // 0000 0?00
}

tipo_pokemon_t agregar_tipo_agua(tipo_pokemon_t t){
    return t | AGUA;
}

tipo_pokemon_t quitar_tipo_agua(tipo_pokemon_t t){
    return t & ~FUEGO;
}


