#include<stdio.h>
#include<stdlib.h> //malloc,free
void bubbleSort(int *x,int lb,int ub)
{
int m,e,f,g;
int size=ub-lb+1;
m=size-2;
while(m>=lb)
{
e=0;
f=1;
while(e<=m)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
e++;
f++;
}
m--;
}
}
void cocktailShakesSort(int *arr,int lb,int ub)
{
int swapCount=1;
int l,r;
l=lb;
r=ub;
while(l<=r)
{
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
stoogeSort(arr,0,req-1);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}