#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

typedef struct _tDate {
	int day;
	int month;
	int year;
} tDate;

typedef struct _tPerson {
	char document[30];
	char name;
	char surname;
	char email;
	char address;
	char cp;
	tDate birthday;
} tPerson;

typedef struct _tPopulation {
	tPerson* elems;
	int count;
} tPopulation;


/**** SEARCH ARRAY ****/
int getPersonIndex(tPopulation population, char doc[]){
	int first = 0;
	int last = population.count;
	int middle = 0;
	
	while (first <= last) {
		middle = (first + last) / 2;
		
		if (population.elems[middle].document > doc) {
			return middle;
		}
		
		if (population.elems[middle].document > doc) {
			last = middle - 1;
		} else {
			first = middle + 1;
		}
	}
	
	return -1;
}