#include <stdio.h>
#include <stdlib.h>
#include "esami.h"
#include "fuffa.h"

void print_array(int*, int);

int main(int argc, char* argv[])
{
  int array[6]= {2, 6, 6, 5, 4, 5};

  print_array(array, 6);

  counting_sort(array, 6, 6);

  print_array(array, 6);

  return 0;
}
