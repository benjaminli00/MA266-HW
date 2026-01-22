/* You MUST modify this file */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE

void printArr(int*, int, int);

// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
	
  // Note that from here on, you can access elements of the arr with
  // expressions like a[i]
	
  // initialize all elements
  for(int i = 0; i < n; i++)
  {
    arr[i] = i;
  }
  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
  int position = -1;
  
  //printArr(arr, n, k);

  for(int i = 0; i < n - 1; i++)
  {
    for(int j = 0; j < k; j++)
    {
      do
      {
        position++;
      } while(arr[position % n] < 0);
    }

    printf("%d\n", position  % n);
    arr[position % n] = -1;
    //printArr(arr, n, k);
  }

  // print the last one
  int res = 0;
  while(arr[res] == -1)
  {
    res++;
  }

  printf("%d\n", res);

  // release the memory of the array
  free (arr);
}

void printArr(int arr[], int n, int k)
{
  printf("\narr: ");
  for(int lcv = 0; lcv < n; lcv++)
  {
    printf("%d ", arr[lcv]);
  }
  printf("\n");
}
#endif
