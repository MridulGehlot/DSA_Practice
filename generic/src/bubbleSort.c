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
void bubbleSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*))
{
void *a,*b;
int m,e,f;
m=size-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=arr+(f*sizeOfElement);
b=arr+(e*sizeOfElement);
if(ptr2func(a,b)<0)
{
swap(a,b,sizeOfElement);
}
e++;
f++;
}
m--;
}
}