#include<stdio.h>
#include<stdlib.h>
#include<mg_heap.h>
int cmp(void *a,void *b)
{
int *x,*y;
x=(int *)a;
y=(int *)b;
return *x<*y;
}
int main()
{
printf("Program Started\n");
int succ,res,cost;
int *a,*b;
Heap *heap=createHeap(cmp,&succ);
int arr[6]={10,4,7,5,9,20};
for(int i=0;i<6;i++)
{
a=(int *)malloc(sizeof(int));
*a=arr[i];
insert(heap,(void *)a,&succ);
}
cost=0;
while(getSizeOfHeap(heap)>1)
{
a=(int *)removeFromHeap(heap,&succ);
b=(int *)removeFromHeap(heap,&succ);
res=*a+*b;
printf("Merge %d with %d -> cost = %d\n",*a,*b,res);
cost+=res;
free(a);
free(b);
a=(int *)malloc(sizeof(int));
*a=res;
insert(heap,(void *)a,&succ);
}
printf("Total Cost = %d\n",cost);
return 0;
}