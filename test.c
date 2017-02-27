#include <stdio.h>
#include <stdlib.h>
#include "./alg.h"

#define N 10

void print_array(int*, int);
void sort_until_k(int*, int, int);

int main(int argc, char* argv[])
{
  if(argc<2)
    {
      puts("inserire numero");
      return 1;
    }
  
  int k= atoi(argv[1]);
  
  int array[N]= {3,4,2,5,9,7,0,6,8,1};

  print_array(array, N);
  
  sort_until_k(array, N, k);
  
  print_array(array, N);
  
  return 0;
}

void print_array(int* array,int len)
{
  for(int i=0; i<len; i++)
    printf("%d ",array[i]);
  puts("");
  return;
}

void sort_until_k(int* array,int len, int k)
{
  swap(&array[linear_search(array,len,k)], array);
  int p= partition(array,len);
  quick_sort(array, p);
  return;
}
