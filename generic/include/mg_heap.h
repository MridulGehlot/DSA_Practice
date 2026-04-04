#ifndef __mg_heap
#define __mg_heap

typedef struct __heap
{
void **collection;
int size,capacity;
int (*cmp)(void *,void *);
}Heap;

//functions
Heap * createHeap(int (*ptr2func)(void *,void *),int *succ);
void insert(Heap *heap,void *data,int *succ);
void * removeFromHeap(Heap *heap,int *succ);
int isHeapEmpty(Heap *heap);
int getSizeOfHeap(Heap *heap);

#endif