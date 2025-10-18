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
void print(int *arr,int size)
{
int i=0;
while(i<size)
{
printf("%d\n",arr[i]);
i++;
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
linearSort(arr,req,sizeof(int),comparator);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}