#include <stdio.h>
#include <stdlib.h>

/**** SORT ARRAY ****/

/* Return the index of the min. number between from and to*/
size_t get_min_index(int nums[], size_t from, size_t to);

/* Swap numbers in positions i and j */
void swap(int nums[], int i, int j);

/* Sort array of numbers using the selection method
 * Pre: the elements of the array must be comparables
 * Post: the array is sorted (ascendent order) */
void sort_selection(int nums[], size_t n);

void print_nums(int nums[], size_t n);
