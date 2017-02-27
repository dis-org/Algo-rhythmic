#include "fuffa.h"

void sort_until_k(int* array,int len, int k)
{
  swap(&array[linear_search(array,len,k)], array);
  int p= partition(array,len);
  quick_sort(array, p);
  return;
}
