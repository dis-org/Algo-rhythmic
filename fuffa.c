#include <stdio.h>
#include <stdlib.h>
#include "fuffa.h"

/*OUTPUT*/
void print_array(int* array,int len)
{
  for(int i=0; i<len; i++)
    printf("%d ",array[i]);
  puts("");
  return;
}

void print_maxHeap(int* array, int len)
{
  if(len>0)
    {
      int rows= lg(len);
      int dim= int_log(10,array[0]);
      int indx= 0;
      int nums= 1;

      for(int i= 0; i< rows; i++)
	{
	  int spc= 1;
	  for(int j= 1; j< rows-i;j++)
	    spc*=2;

	  for(int f= 0; f< nums; f++)
	    {
	      for(int k= 0; k< dim*(spc-1); k++)
		printf(" ");
	      if(indx<len)
		{
		  int dam= dim -int_log(10,array[indx]);
		  for(int s= 0; s< dam; s++)
		    printf(" ");
		  printf("%d",array[indx++]);
		}
	      for(int k= 0; k< dim*(spc); k++)
		printf(" ");
	    }
	  puts("");
	  nums*=2;
	}

    }
  return;
}

/*VARIE*/
void swap(int* a, int* b)
{
  int temp= *a;
  *a= *b;
  *b= temp;
  return;
}

int int_log(int base, int n)
{
  int ret= 0;
  while(n>0)
    {
      n/=base;
      ret++;
    }
  return ret;
}


int lg(int n)
{
  return int_log(2,n);
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

/*RICERCA*/
int linear_search(int* array, int len, int k)
{
  for(int i= 0; i<len;i++)
    if(array[i]== k) return i;
  return -1;
}

int binary_search(int* array, int len, int k)       //iterativo perché sì
{
  int min= 0;
  int max= len-1;
  int mid= (max+min)/2;
  while (min<=max) {
    if(array[mid]==k) return mid;
    else
    {
      if(k<mid) max= mid-1;
      else min= mid+1;
      mid= (max+min)/2;
    }
  }
  return -1;
}

/*ORDINAMENTO*/
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

void heap_sort(int* array, int len)
{
  build_maxHeap(array, len);
  for(int i=len-1; i>0; i--)
  {
    swap(&array[0], &array[i]);
    maxHeapfy(array, i, 0);
  }
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
  if(l<len && array[l]>array[i]) largest= l;
  if(r<len && array[r]>array[i] && array[r]>array[l]) largest= r;
  if(largest!=i)
  {
    swap(&array[i], &array[largest]);
    maxHeapfy(array, len, largest);
  }
}

void build_maxHeap(int* array, int len)
{
  for(int i=len/2-1; i>=0; i--) maxHeapfy(array, len, i);
  return;
}
