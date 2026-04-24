#include<mg_sort.h>
#include<stdlib.h> //malloc,free
#include<string.h> //memcpy
void swap(void *a,void *b,int elementSize)
{
void *c=malloc(elementSize);
memcpy(c,a,elementSize);
memcpy(a,b,elementSize);
memcpy(b,c,elementSize);
free(c);
}
void selectionSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*))
{
void *a,*b;
int e,f,smallestIndex;
e=0;
while(e<size-1)
{
smallestIndex=e;
f=e+1;
while(f<size)
{
a=arr+(smallestIndex*sizeOfElement);
b=arr+(f*sizeOfElement);
if(ptr2func(b,a)<0) smallestIndex=f;
f++;
}
swap(arr+(e*sizeOfElement),arr+(smallestIndex*sizeOfElement),sizeOfElement);
e++;
}
}
