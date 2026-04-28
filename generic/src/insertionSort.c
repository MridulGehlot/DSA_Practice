#include<mg_sort.h>
#include<stdlib.h>
#include<string.h>
void _insertionSort(void *ptr,int lb,int ub,int es,int (*p2f)(void*,void*))
{
void *block;
block=malloc(es);
int y,z;
y=lb;
while(y<=ub)
{
memcpy(block,(const void *)ptr+(y*es),es);
z=y-1;
while(z>=lb && p2f(ptr+(z*es),block)>0)
{
memcpy(ptr+((z+1)*es),(const void *)ptr+(z*es),es);
z--;
}
memcpy(ptr+((z+1)*es),(const void *)block,es);
y++;
}
}
void insertionSort(void *arr,int size,int sizeOfElement,int (*p2f)(void*,void*))
{
_insertionSort(arr,0,size-1,sizeOfElement,p2f);
}