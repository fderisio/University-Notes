/*
 * File: practica.c
 * Author: Fiorella
 * Date: 23-09-2021
 * Description: Practicing Lists - this file contains the functions and commands related to the groceries list
 */

/* System header files */
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/* Application header files */
#include "practica.h"

tGroceriesList* tGroceriesList_create(){
    tGroceriesList *list = malloc(sizeof(tProduct) * MAX_PRODUCTS);
	list->count = 0;
    return list;
}

void groceriesList_add(tGroceriesList *list, tProduct product) {
    // check pre-conditions
	assert(list->count <= MAX_PRODUCTS && list->count >= 0);

    bool isFound = false;
	int i = 0;

    // if list is empty
    if (list->count == 0) {
        // add at the beginning
        list->products[list->count] = product;
        list->count++;
    } else {

        // check if already exists on the list
        while(i < list->count && !isFound) {
			// increase quantity if exists
			if (strcmp(list->products[i].id, product.id) == 0) {
                list->products[i].cant++;
				isFound = true;
			}
			i++;
		}
		
		// if it doesnt exist, add data to the list
		if (!isFound) {
			list->products[list->count] = product;
			list->count++;
		}
		// if they are on the list, do not make any changes
    }

}

void groceriesList_del(tGroceriesList *list, int id){
    
    bool isFound = false;
	int i = 0;
    int delPos = 0;
    
    // if list is empty
    if (list->count == 0) {
        printf("[INFORMATION] The list is empty.");
    }

    // check if already exists on the list
    while(i < list->count && !isFound) {
        if (strcmp(list->products[i].id, id) == 0) {
            delPos = i;
            isFound = true;
        }
        i++;
    }

    // remove from the list
    if (isFound) {
		for (i = delPos; i < list->count-1; i++) {
            list->products[i] = list->products[i+1];
        }
		list->count--;
	}

}

void groceriesList_print(tGroceriesList list){
    for (int i = 0; i < list.count; i++) {
        printf("ID: %d - Product: %s - Quantity: %d - Type: %s", 
                list.products[i].id,
                list.products[i].name,
                list.products[i].cant,
                list.products[i].type);
    }
}

void groceriesList_destroy(tGroceriesList* list){
    free(list);
}

int main() {
    // TODO
    return 0;
}
