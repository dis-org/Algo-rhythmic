#include <stdio.h>
#include <stdlib.h>
#include "esami.h"
#include "fuffa.h"

void print_array(int*, int);

int main(int argc, char* argv[])
{
  int array[15]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  print_array(array, 15);

  buildMaxHeap(array, 15);

  print_array(array, 15);

  return 0;
}
