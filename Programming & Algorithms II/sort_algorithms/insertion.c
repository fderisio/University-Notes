#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"

/**** SORT ARRAY ****/

/* Return the index of the min. number between from and to*/
void insert_ordered(int nums[], size_t i){
	
	// get number in i position
	int v = nums[i];
	// get previous position
	int j = i-1;
	
	while (j >= 0 && nums[j] > v) {
		nums[j+1] = nums[j];
		j--;
	}
	
	nums[j+1] = v;
}

/* Order array of numbers using the selection method
 * Pre: the elements of the array must be comparables
 * Post: the array is ordered (ascendent) */
void sort_insertion(int nums[], size_t n){
	for (size_t i = 1; i < n; i++) {
		insert_ordered(nums, i);
	}
}