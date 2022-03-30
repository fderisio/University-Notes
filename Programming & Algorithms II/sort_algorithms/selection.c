#include <stdio.h>
#include <stdlib.h>
#include "selection.h"

/**** ORDENAMIENTO POR SELECCION (VECTOR) ****/

/** Return the index of the min. number between from and to*/
size_t get_min_index(int nums[], size_t from, size_t to) {
	size_t posMin = from;
	for (size_t i = from + 1; i <= to; i++) {
		if (nums[i] < nums[posMin]) {
			posMin = i;
		}
	}
	return posMin;
}

/** Swap numbers in positions i and j */
void swap (int nums[], int i, int j) {
	// aux with value in given position
	int aux = nums[i];
	
	// swap numbers
	nums[i] = nums[j];
	nums[j] = aux;
}

/* Sort array of numbers using the selection method
 * Pre: the elements of the array must be comparables
 * Post: the array is ordered (ascendent) */
void sort_selection (int nums[], size_t n) {
	// navigate until n-2
	for (size_t i = 0; i < n-1; i++) {
		size_t pos = get_min_index(nums, i, n-1);
		swap(nums, pos, i);
	}
}

void print_nums(int nums[], size_t n) {
	for (size_t i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}
