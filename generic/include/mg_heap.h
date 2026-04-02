#ifndef __mg_heap
#define __mg_heap

typedef struct __heap
{
void *collection;
int size,capacity;
}Heap;

//functions
Heap * createHeap(int (*ptr2func)(void *,void *),&succ);
void insert(Heap *heap,void *data,int &succ);
void * remove(Heap *heap,int &succ);
int isHeapEmpty();
int getSizeOfHeap();

#endif