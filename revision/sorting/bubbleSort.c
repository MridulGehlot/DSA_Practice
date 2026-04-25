#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr,int size)
{
int e,f,m,g;
m=size-2;
while(m>=0)
{
e=0;
while(e<=m)
{
f=e+1;
if(arr[f]<arr[e])
{
g=arr[f];
arr[f]=arr[e];
arr[e]=g;
}
e++;
}
m--;
}
}
void print(int *arr,int sz)
{
for(int i=0;i<sz;i++) printf("%d ",arr[i]);
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
bubbleSort(arr,req);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}