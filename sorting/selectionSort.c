#include<stdio.h>
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
void show(int *arr,int size)
{
for(int i=0;i<size;i++)
{
printf("%d\n",arr[i]);
}
}
int comparator(void *a,void *b)
{
int *left=(int *)a;
int *right=(int *)b;
return (*left)-(*right);
}
int main()
{
int req;
int *arr;
printf("Enter Requirement - ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement");
return 0;
}
arr=(int *)malloc(sizeof(int)*req);
if(arr==NULL)
{
printf("Unable To Allocate Memory");
return 0;
}
for(int i=0;i<req;i++)
{
printf("Enter A Number - ");
scanf("%d",&arr[i]);
}
selectionSort(arr,req,sizeof(int),comparator);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}