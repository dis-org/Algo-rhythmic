#include <stdio.h>
#include <stdlib.h>
#include "esami.h"
#define N 10

void print_array(int*, int);

int main(int argc, char* argv[])
{
  int k= 0;
  if(argc<2)
    {
      puts("inserire numero");
      scanf("%d",&k);
    }
  else
    k= atoi(argv[1]);

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

