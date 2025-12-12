#include<stdio.h>
#include<stdlib.h> //malloc,free
void stoogeSort(int *arr,int lb,int ub)
{
int g;
if(arr[lb]>arr[ub])
{
g=arr[lb];
arr[lb]=arr[ub];
arr[ub]=g;
}
int sz=(ub-lb+1);
if(sz>2)
{
int twoThird=sz-(sz/3);
stoogeSort(arr,lb,lb+twoThird-1);
stoogeSort(arr,ub-twoThird+1,ub);
stoogeSort(arr,lb,lb+twoThird-1);
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