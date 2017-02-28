void swap(int*, int*);                       // O(1)
int partition(int*,int);                     // O(n)
int* clone_array(int*, int);                 // O(n)
void merge(int*,int*,int,int,int*);          // O(n)
void print_array(int*, int);                 // 0(n) (sì sì, poi lo spostiamo al posto giusto)

/*RICERCA*/
int linear_search(int*, int, int); // O(n)

/*ORDINAMENTO*/
void insertion_sort(int*,int);               // O(n^2) - in place
void quick_sort(int*,int);                   // O(n^2) avg: O(nlogn) - in place
void merge_sort(int*, int);                  // O(nlogn)
void counting_sort(int*, int, int);          // O(n) - stable - per nulla in place
