void swap(int*, int*);             // O(1)
int partition(int*,int);           // O(n)
int* clone_array(int*, int);       // O(n)
void merge(int*,int*,int,int,int*);// O(n)

/*RICERCA*/
int linear_search(int*, int, int); // O(n)

/*ORDINAMENTO*/
void insertion_sort(int*,int);     // O(n^2)
void quick_sort(int*,int);         // O(n^2) avg: O(nlogn)
void merge_sort(int*, int);        // O(nlogn)
