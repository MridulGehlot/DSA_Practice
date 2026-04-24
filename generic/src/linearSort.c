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
void linearSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*))
{
void *a,*b;
int e,f;
e=0;
while(e<=size-2)
{
f=e+1;
while(f<=size-1)
{
a=arr+(f*sizeOfElement);
b=arr+(e*sizeOfElement);
if(ptr2func(a,b)<0)
{
swap(a,b,sizeOfElement);
}
f++;
}
e++;
}
}
