void swap(int* a, int* b)
{
  int temp= *a;
  *a= *b;
  *b= temp;
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

int partition(int* array, int len)
{
  //array[0] = k pivot
  int k= 0;
  for(int i= 1; i<len; i++)
    if(array[i]<=array[0])
      swap(&array[i],&array[++k]);
  swap(array,&array[k]);
  return k;
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
