#include <stdio.h>
#include <stdlib.h>
#include "esami.h"
#include "fuffa.h"

void print_array(int*, int);

int main(int argc, char* argv[])
{
  int array[8]= {9,6,5,3,2,4,6,1};
  
  print_array(array, 8);

  merge_sort(array, 8);
  
  print_array(array, 8);
  
  return 0;
}

void print_array(int* array,int len)
{
  for(int i=0; i<len; i++)
    printf("%d ",array[i]);
  puts("");
  return;
}

