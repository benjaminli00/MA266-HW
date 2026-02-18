// ***
// *** You MUST modify this file
// ***

#include "msort.h"
#include "hw6.h"
#include <stdio.h>

/*
Merge sort function. Sorts an array with base address base, with nel elements where each element takes up space of size width.

INPUT:
base: a pointer to the beginning of the array to be sorted
nel: the number of elements in the array pointed to by base
compar: a function pointer to compare two elements in the base array

OUTPUT:
the function has no return value,
but after msort, base now should point to a sorted array
*/
#ifndef OMIT_MSORT
void msort(Student * base, int nel, int (*compar)(const void *, const void *)) {
	
	//Base case: if the array has one or fewer elements, it's already sorted
	//so just return.

	//FILL IN
	
	//Inductive case: split the array in two, sort the two pieces with msort,
	//merge the	sorted pieces
		
	//We're going to do this without explicitly creating the two separate arrays
	//We'll take advantage of the fact that to C, an array is just a pointer to
	//a region of memory. If we call msort on base, but pass in a smaller number
	//of elements, it will sort just that subarray. Similarly, if we call msort
	//but pass in the address of an element in the middle of the array, it will
	//sort the array *starting* from that element.
		
	//1. Find the midpoint of the array

	//FILL IN
	
	//2a. Sort the first half of the array (remember to adjust the # elements)

	//FILL IN
	
	//2b. Sort the second half of the array. Pass in the address of the 
	//beginning of the second half of the array (remember to use the right # of 
	//elements)

	//FILL IN
	
	//3a. Merge the two arrays (use merge)

	//FILL IN
	
	//3b. Copy the merged array over top of the original array (use copy)
	//Don't forget to free the array you returned from merge -- you don't need it after the copy!

	//FILL IN
		
	return;
}
#endif



/*
Merge two sorted arrays together to produce a new sorted array

INPUT:
base1: a pointer to the beginning of sorted array 1
nel1: the number of elements in array 1
base2: a pointer to the beginning of sorted array 2
nel2: the number of elements in array 2
compar: a function pointer to compare two elements in the base array

OUTPUT:
return value: a pointer to the beginning of a sorted array that is the merged version of the two input arrays
*/
#ifndef OMIT_MERGE
Student * merge(Student * base1, int nel1, Student * base2, int nel2, int (*compar)(const void *, const void *)) {
	
	//1. Allocate space for the returned merged array
	
	//FILL IN
	
	//2. Create indices to keep track of where you are in the three arrays

	//FILL IN
	
	//3. Go through base1 and base2, and merge them into the returned array

	//FILL IN
	
	//4. Return the merged array

	//FILL IN

}

/*
Copy contents of array from to array to, nel is the number of elements in each array
*/
void copy(Student * to, Student * from, int nel) {
	/*
	An efficient implementation of this would use memcpy:
	memcpy(to, from, nel * width);

	We will do an element-by-element copy so you can see how it is done
	*/
	
	//loop over the from array and copy it byte by byte to the to array.
	for (int i = 0; i < nel; i++) {
		to[i] = from[i];
	}
	
	return;
}
#endif
