#include "fuffa.h"
#include "esami.h"

void sort_under_k(int* array, int len, int k)
{
  swap(&array[linear_search(array,len,k)], array);
  int p= partition(array,len);
  quick_sort(array, p);
  return;
}

int how_many_twos(int* array, int len)
{
  int last_two= search_last(array,0,len-1,2);
  if(last_two<0)
    return 0;
  int last_one= search_last(array,0,len-1,1);
  if(last_one<0)
    return last_two+1;
  return last_two -last_one;
}

int search_last(int* array, int f, int l, int k)
{
  if(f<l)
    {
      int m= (f+l)/2;
      if(array[m]== k && array[m+1]>k)
	return m;
      if(array[m]> k)
	return search_last(array, f, m-1,k);
      else
	return search_last(array, m+1, l,k);
    }
  else if(array[f]== k) return f;
  else return -1;
}

int one_two_sum(int* array, int len)
{
  int ones= search_last(array,0,len-1,1) +1;
  int twos= len- ones;
  return ones + 2*twos;
}
