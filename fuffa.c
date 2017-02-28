#include <stdlib.h>

void swap(int* a, int* b)
{
  int temp= *a;
  *a= *b;
  *b= temp;
  return;
}

int partition(int* array, int len)
{
  int k= 0;
  for(int i= 1; i<len; i++)
    if(array[i]<=array[0])
      swap(&array[i],&array[++k]);
  swap(array,&array[k]);
  return k;
}

int* clone_array(int* array, int len)
{
  int* ret= malloc((len)*sizeof(len));
  for(int i= 0; i<len; i++)
    ret[i]= array[i];
  return ret;
}

void merge(int* left, int* right, int len_l, int len_r, int* array)
{
  int len= len_l+len_r;
  int l= 0, r= 0;
  for(int i=0; i<len; i++)
    array[i]= (left[l]<right[r]) && (l<len_l)? left[l++]: (r<len_r)? right[r++]: left[l++];
  return;
}

int linear_search(int* array, int len, int k)
{
  for(int i= 0; i<len;i++)
    if(array[i]== k) return i;
  return -1;
}

void insertion_sort(int* array, int len)
{
  int j= 0;
  for(int i= 1; i< len; i++)
    {
      int temp= array[i];
      j= i;
      while(j-->0 && array[j]>temp)
	array[j+1]=array[j];
      array[j+1]=temp;
    }
  
  return;
}

void quick_sort(int* array, int len)
{
  if(len>1)
    {
      int q= partition(array, len);
      if(len>2)
	{
	  quick_sort(array, q);
	  quick_sort(&array[q+1],len-q-1);	  
	}
    }
  return;
}

void merge_sort(int* array, int len)
{
  if(len>1)
    {
      int q= len/2;
      int* left= clone_array(array,q); merge_sort(left,q);
      int* right= clone_array(&array[q],len-q); merge_sort(right,len-q);
      merge(left, right, q, len-q, array);
      free(left); free(right);
    }
  return;
}
