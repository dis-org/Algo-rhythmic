#include <stdio.h>
#include <stdlib.h>
#include "esami.h"
#include "fuffa.h"

int main(int argc, char* argv[])
{

  int len= argc -1;
  int array[len];

  for(int i= 0; i<len; i++)
    array[i]= atoi(argv[i+1]);

  heap_sort(array,len-1);

  print_array(array, len-1);
  printf("obj: %d\n",array[len-1]);
  
  int lin= linear_search(array, len-1, array[len-1]);
  int bin= binary_search(array, len-1, array[len-1]);

  printf("lin: %d\nbin: %d\n",lin,bin);

  return 0;
}
