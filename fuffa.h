#include "distruct.h"

/*VARIE*/
void swap(int* a, int* b);                         // O(1)
int int_log(int base, int n);                      // O(1)
int lg(int n);                                     // O(1)
int partition(int* array, int len);                // O(n)
int* clone_array(int* array, int len);             // O(n) - memory allocation
void merge(int* left, int* right, int len_l,int len_r,int* array); // O(n)

/*RICERCA*/
int linear_search(int* array, int len, int k);     // O(n)
int binary_search(int* array, int len, int k);     // O(logn)

/*ORDINAMENTO*/
void insertion_sort(int* array, int len);          // O(n^2) - in place
void quick_sort(int* array, int len);              // O(n^2) avg: O(nlogn) - in place
void merge_sort(int* array, int len);              // O(nlogn)
void counting_sort(int* array, int len, int k);    // O(n) - stable
//void radix_sort(int*, int, int);
void heap_sort(int* array, int len);               // O(nlogn)

/*HEAP*/
int parent(int i);                                 // O(1)
int leftchild(int i);                              // O(1)
int rightchild(int i);                             // O(1)
void maxHeapfy(int* array, int len, int i);        // O(logn)
void build_maxHeap(int* array, int len);           // O(n)

/*UNION-FIND*/
Set_t* make_Set(Set_t* New, char e);               // O(1)
Set_t* union_Set(Set_t* A, Set_t* B);              // O(n)
Set_t* find_Set(Set_t* Sets, int len, char e);     // O(n)

/*OUTPUT*/
void print_array(int* array, int len);
void print_maxHeap(int* array, int len);
void print_Sets(Set_t* Sets, int len);
void print_Set(Set_t*);
