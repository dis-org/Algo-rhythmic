
/*UNION-FIND*/

typedef struct Let {
  char name;
  struct Let* Head;
  struct Let* Next;
} Let_t;

typedef struct Set {
  int size;
  char tag;
  struct Let* Head;
  struct Let* Tail;
} Set_t;
