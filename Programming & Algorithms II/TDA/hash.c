#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "hash.h"

void initHashTable(tHashTable *t) {
    int i;
    t->size = MAX_SIZE;
    t->numElem = 0;

    for (i=0; i<MAX_SIZE; i++) {
        t->list[i].key = -1;
        t->list[i].next = -1;
    }
}

int hashFunction(int key) {
    return (key % MAX_SIZE);
}

int insertElem(tHashTable *t, int key, char *name) {

    int h;
    int next, previous;
    bool found;

    if (t->numElem == MAX_SIZE) {
        return -1;
    }

    h = hashFunction(key);
    found = false;
    next = h;
    previous = h;
	while (!found) {
        if (t->list[next].key == -1) {
            found = true;
            t->list[next].key = key;
            t->list[next].name = malloc(sizeof(*name));
            strcpy(t->list[next].name, name);
            if (next != previous) {
                t->list[previous].next = next;
            }
        } else {
            printf("Collision at %d\n", next);
            previous = next;
            next = (next + 1) % MAX_SIZE;
        }
    }

    return next;
}

int findElem(tHashTable t, int key) {

    int h;
    bool found;

    h = hashFunction(key);
    found = false;

    while (!found && t.list[h].key != -1) {
        if (t.list[h].key == key) {
            found = true;
        } else {
            h = t.list[h].next;
        }
    }

    if (found) {
        return h;
    } else {
        return -1;
    }
}
