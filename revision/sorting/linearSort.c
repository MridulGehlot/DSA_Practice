#include<stdio.h>
#include<stdlib.h>

void Sort(int *arr,int size)
{
int e,f,m,g,ep;
ep=size-2;
m=0;
while(m<=ep)
{
e=m;
f=m;
while(e<=size-1)
{
if(arr[f]>arr[e])
{
g=arr[f];
arr[f]=arr[e];
arr[e]=g;
}
e++;
}
m++;
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
Sort(arr,req);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}