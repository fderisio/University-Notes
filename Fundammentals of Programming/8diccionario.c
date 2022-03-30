#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef enum {
    BUENOS_AIRES, CATAMARCA, CHACO, CHUBUT, TIERRA_DEL_FUEGO
} tProvinciaId;

tProvinciaId id;

// como agregar el area de cada provincia rapidamente?
// Tabla de búsqueda: diccionario
unsigned int area_km2[] = {
    [BUENOS_AIRES] = 360000,
    [CATAMARCA] = 36000,
    [CHACO] = 4521,
    [CHUBUT] = 1234,
    [TIERRA_DEL_FUEGO] = 4521,

};

// seria lo mismo que hacer estos 2:
/*unsigned int area_km2[] = {
    360000,
    36000,
    4521,
    1234,
    4521,
}*/

/*unsigned int area_km2[] = {
    [0] = 360000,
    [1] = 36000,
    [2] = 4521,
    [3] = 1234,
    [4] = 4521,
}*/

// la table de busqueda podria estar en el main, pero si es 
// asi ocuparia memoria en el Stack
// para tablas muy grandes seria mejor crearlas fuera del main

int main() {
    tProvinciaId idChaco = CHACO;
    int area_provincia = area_km2[idChaco];
    printf("area %d\n", area_provincia);
    return 0;
}
