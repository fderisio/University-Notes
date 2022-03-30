#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 3041

typedef struct {
    int key;
    char *name;
    int next;
} tElem;

typedef struct {
    int size;
    int numElem;
    tElem list[MAX_SIZE];
} tHashTable;

int findElem(tHashTable t, int key);
int insertElem(tHashTable *t, int key, char *name);
int hashFunction(int key);
void initHashTable(tHashTable *t);
