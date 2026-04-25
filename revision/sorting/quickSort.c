#include<stdio.h>
#include<stdlib.h>

int findPP(int *arr,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && arr[e]<=arr[lb]) e++;
while(arr[f]>arr[lb]) f--;
if(e<f)
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
else
{
g=arr[f];
arr[f]=arr[lb];
arr[lb]=g;
}
}
return f;
}

void quickSort(int *arr,int lb,int ub)
{
if(lb<ub)
{
int pp=findPP(arr,lb,ub);
quickSort(arr,lb,pp-1);
quickSort(arr,pp+1,ub);
}
}

void Sort(int *arr,int size)
{
quickSort(arr,0,size-1);
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