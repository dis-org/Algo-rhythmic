#include <stdlib.h>
#include<stdio.h>

void print_array(int* array,int len)
{
  for(int i=0; i<len; i++)
    printf("%d ",array[i]);
  puts("");
  return;
}


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

void counting_sort(int* array, int len, int max)
{
  int erval= max+1;
  int* ermediate= malloc(erval*sizeof(erval));

  for(int i=0; i<len; i++)
    ermediate[array[i]]++;

  for(int i=1; i<erval; i++)
    ermediate[i]+= ermediate[i-1];

  int* copy= clone_array(array,len);

  for(int i=len-1; i>=0; i--)
  {
    array[ermediate[copy[i]]-1]= copy[i];
    --ermediate[copy[i]];
  }
  free(copy); free(ermediate);
  return;
}

/*HEAP*/

int parent(int i)
{
  return i/2;
}

int leftchild(int i)
{
  return 2*i+1;
}

int rightchild(int i)
{
  return 2*i+2;
}

void maxHeapfy(int* array, int len, int i)
{
  int l= leftchild(i);
  int r= rightchild(i);
  int largest= i;
  if(l<=len && array[l]>array[i]) largest= l;
  if(r<=len && array[r]>array[i] && array[r]>array[l]) largest= r;
  if(largest!=i)
  {
    swap(&array[i], &array[largest]);
    maxHeapfy(array, len, largest);
  }
}

void buildMaxHeap(int* array, int len)
{
  for(int i=len/2-1; i>=0; i--) maxHeapfy(array, len, i);
}
