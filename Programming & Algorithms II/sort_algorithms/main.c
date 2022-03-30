#include <stdio.h>
#include <stdlib.h>
#include "selection.h"
#include "insertion.h"
#include "hash.h"

int main(int argc, char **argv)
{
	int nums[] = {51, 66, 7, 10, 3, 15, 101, 99};
	size_t n = sizeof(nums) / sizeof(int);
	
	printf("***** SELECTION SORT ****** \n");
	printf("original array: ");
	print_nums(nums, n);
	
	sort_selection(nums, n);
	
	printf("sorted array: ");
	print_nums(nums, n);
	

	printf("\n***** INSERTION SORT ****** \n");
	int nums2[] = {51, 66, 7, 10, 3, 15, 101, 99};
	
	printf("original array: ");
	print_nums(nums2, n);
	
	sort_insertion(nums2, n);
	
	printf("sorted array: ");
	print_nums(nums2, n);
	
	printf("\n");
	
	
	tHashTable list;
    int cell;
    int key;
    char *name;

    initHashTable(&list);

    key = 12345678;
    name = "NAME12345678";
    cell = insertElem(&list, key,name);

    key = 98563211;
    name = "NAME98563211";
    cell = insertElem(&list, key,name);
	
	key = 33330001;
    name = "NAME33330001";
    cell = insertElem(&list, key,name);

    key = 30410641;
    name = "NAME30410641";
    cell = insertElem(&list, key,name);

    cell = findElem(list, 30410641 );
    printf("Key 30410641 has been found at cell %d\n", cell);

    cell = findElem(list, 33330001 );
    printf("Key 33330001 has been found at cell %d\n", cell);

    cell = findElem(list, 55558888 );
    printf("Key 55558888 has been found at cell %d\n", cell);
	
	return 0;
}
