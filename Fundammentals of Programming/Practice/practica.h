/*
 * File: practica.h
 * Author: Fiorella
 * Date: 23-09-2021
 * Description: Practicing Lists
 */

/* System header files */
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 100
#define MAX_PRODUCTS 50

typedef enum {BAKERY=1, FRESH, DRINKS, FROZEN, BEAUTY, BREAKFAST} tProductType;

// Product
typedef struct {
    int id;
    char name[MAX_CHAR];
    int cant;
    tProductType type;
} tProduct;

// Lista de compras
typedef struct {
    tProduct products[MAX_PRODUCTS];
    int count;
} tGroceriesList;

// Initialize structure
void groceriesList_init(tGroceriesList *list);

// Add new location to the locations list only if it doesnt exist at the given date/time
void groceriesList_add(tGroceriesList *list, tProduct product);

// Delete product. If not found, do not make any changes.
void groceriesList_del(tGroceriesList *list, int id);

// Print the geolocation data (latitude and longitude with 4 decimals according to the excercise)
void groceriesList_print(tGroceriesList list);
