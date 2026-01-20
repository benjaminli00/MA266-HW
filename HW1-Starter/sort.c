/* MODIFY this file */

#include "sort.h"

void ssort(int * arr, int size) {
	/* For step 3, fill this in to perform a selection sort
	   For step 4, add conditional compilation flags to perform an ascending selection sort instead */

	for(int i = 0; i < size - 1; i++)
	{
		int extrema_i = i;

		for(int j = i + 1; j < size; j++)
		{
#ifdef ASCENDING
			if(arr[j] < arr[extrema_i])
			{
				extrema_i = j;
			}
#else
			if(arr[j] > arr[extrema_i])
			{
				extrema_i = j;
			}
#endif
		}

		int temp = arr[i];
		arr[i] = arr[extrema_i];
		arr[extrema_i] = temp;
	}
}
