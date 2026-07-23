#include<stdio.h>
#include<stdlib.h> //for malloc and free
void bubble_sort(int *arr,int size,int (*p2f)(void *,void *))
{
int ep,e,f,g;
ep=size-2;
while(ep>=0)
{
e=0;
f=e+1;
while(e<=ep)
{
if(p2f(&arr[f],&arr[e]))
{
//swap
g=arr[f];
arr[f]=arr[e];
arr[e]=g;
}
e++;
f++;
}
ep--;
}
}
int comp(void *l,void *r)
{
int *x=(int *)l;
int *y=(int *)r;
return *x<*y;
}
int main()
{
int req;
printf("Enter How Many Numbers : ");
scanf("%d",&req);
if(req<0)
{
printf("Invalid Requirements");
return 0;
}
int *arr=(int *)malloc(sizeof(int)*req);
for(int i=0;i<req;i++) scanf("%d",&arr[i]);
bubble_sort(arr,req,comp);
for(int i=0;i<req;i++) printf("%d ",arr[i]);
free(arr);
return 0;
}