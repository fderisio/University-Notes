#include <stdio.h>
#include <stdlib.h>

/**** SORT ARRAY ****/

/* Return the index of the min. number between from and to*/
void insert_ordered(int nums[], size_t i);

/* Order array of numbers using the selection method
 * Pre: the elements of the array must be comparables
 * Post: the array is ordered (ascendent) */
void sort_insertion(int nums[], size_t n);
