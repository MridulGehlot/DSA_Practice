#include<stdio.h>
#include<stdlib.h>

void Sort(int *arr,int size)
{
int e,f,si,ep,g;
ep=size-2;
e=0;
while(e<=ep)
{
si=e;
f=e+1;
while(f<=size-1)
{
if(arr[f]<arr[si]) si=f;
f++;
}
g=arr[e];
arr[e]=arr[si];
arr[si]=g;
e++;
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