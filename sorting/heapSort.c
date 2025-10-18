#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//convert into max heap
void heapify(int *arr,int lb,int ub)
{
int y,ri,ci,tmp;
y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ci]>arr[ri])
{
tmp=arr[ci];
arr[ci]=arr[ri];
arr[ri]=tmp;
ci=ri;
}
else break;
}
y++;
}
}
void heapSort(int *arr,int size)
{
int i,tmp;
heapify(arr,0,size-1);
i=size-1;
while(i>0)
{
tmp=arr[0];
arr[0]=arr[i];
arr[i]=tmp;
i--;
heapify(arr,0,i);
}
}
void show(int *arr,int size)
{
for(int i=0;i<size;i++) printf("%d\n",arr[i]);
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
heapSort(arr,req);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}