#ifndef __mg_heap
#define __mg_heap
#include<mg_error.h>
#include<stdlib.h>

typedef struct __heap
{
void **collection;
int size,capacity;
int (*cmp)(void *,void *);
}Heap;

//functions
Heap * createHeap(int (*ptr2func)(void *,void *),int *succ)
{
*succ=FAILURE;
Heap *heap=(Heap *)malloc(sizeof(Heap));
if(heap==NULL) return NULL;
heap->collection=(void **)malloc(sizeof(void *)*10);
if(heap->collection==NULL)
{
free(heap);
return NULL;
}
heap->size=0;
heap->capacity=10;
heap->cmp=ptr2func;
*succ=SUCCESS;
return heap;
}
void heapfiy(Heap *heap)
{
//logic to heapify
}
void insert(Heap *heap,void *data,int *succ)
{
*succ=FAILURE;
if(size==capacity)
{
//reallocate Memory
void **tmp;
heap->capacity=heap->capacity*2;
tmp=(void **)realloc(heap->collection,sizeof(void *)*heap->capacity);
heap->collection=tmp;
}
heap->collection[size++]=data;
heapify(heap);
*succ=SUCCESS;
}
void * remove(Heap *heap,int &succ)
{
*succ=FAILURE;
if(heap==NULL || heap->collection==NULL || heap->size==0) return NULL;
void *data;
memcpy(data,(void *)heap->collection[0],sizeof(void *));
memcpy(heap->collection[0],(void *)heap->collection[size-1],sizeof(void *));
heap->size--;
heapify(heap);
*succ=SUCCESS;
return data;
}
int isHeapEmpty(Heap *heap)
{
if(heap==NULL) return 1;
return heap->size==0;
}
int getSizeOfHeap(Heap *heap)
{
if(heap==NULL) return 0;
return heap->size;
}

#endif