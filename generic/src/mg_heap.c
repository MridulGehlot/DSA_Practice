#include<mg_heap.h>
#include<mg_error.h>
#include<stdlib.h>

//functions
Heap * createHeap(int (*ptr2func)(void *,void *),int *succ)
{
*succ=FAILURE;
if(ptr2func==NULL) return NULL;
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
void floatChildToTop(Heap *heap)
{
//logic to float child to top
int ci,ri;
void *g;
ci=heap->size-1;
while(ci>0)
{
ri=(ci-1)/2;
if(heap->cmp(heap->collection[ci],heap->collection[ri])!=0) // !=0 means success function return true;
{
g=heap->collection[ci];
heap->collection[ci]=heap->collection[ri];
heap->collection[ri]=g;
ci=ri;
}
else break;
}
}
void insert(Heap *heap,void *data,int *succ)
{
*succ=FAILURE;
if(heap==NULL || heap->collection==NULL) return;
if(heap->size==heap->capacity)
{
//reallocate Memory
int newCapacity = heap->capacity * 2;
void **tmp = realloc(heap->collection, sizeof(void *) * newCapacity);
if(tmp == NULL) return;
heap->collection = tmp;
heap->capacity = newCapacity;
}
heap->collection[heap->size++]=data;
floatChildToTop(heap);
*succ=SUCCESS;
}
void heapify(Heap *heap)
{
int ri,lastIndex,lci,rci,sci;
void *g;
ri=0;
lastIndex=heap->size-1;
while(ri<lastIndex)
{
lci=(2*ri)+1;
rci=lci+1;
if(lci>lastIndex) break;
if(rci>lastIndex) sci=lci;
else
{
if(heap->cmp(heap->collection[lci],heap->collection[rci])!=0) sci=lci;
else sci=rci;
}
//now we found sci
if(heap->cmp(heap->collection[sci],heap->collection[ri])!=0) //cmp returns true
{
g=heap->collection[ri];
heap->collection[ri]=heap->collection[sci];
heap->collection[sci]=g;
ri=sci;
}
else break;
} //ri<lastIndex loop
}
void * removeFromHeap(Heap *heap,int *succ)
{
*succ=FAILURE;
if(heap==NULL || heap->collection==NULL || heap->size==0) return NULL;
void *data;
data=heap->collection[0];
heap->collection[0]=heap->collection[heap->size-1];
heap->size--;
heapify(heap);
*succ=SUCCESS;
//adjust DMA size
if(heap->size<heap->capacity/4 && heap->capacity>10)
{
heap->capacity=heap->capacity/2;
void **tmp;
tmp=realloc(heap->collection,sizeof(void *)*heap->capacity);
if(tmp==NULL)
{
heap->capacity*=2;
return data;
}
heap->collection=tmp;
}
//Adjust DMA Ends Here
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

void destroyHeap(Heap *heap)
{
if(heap==NULL) return;
free(heap->collection);
free(heap);
}