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
  
  print_array(array, len);

  build_maxHeap(array, len);

  print_maxHeap(array, len);
  
  return 0;
}
