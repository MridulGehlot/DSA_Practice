#include<stdio.h>
#include<stdlib.h> //malloc,free
//Also Known As Brick Sort
void swap(int *x,int *y)
{
int tmp;
tmp=*x;
*x=*y;
*y=tmp;
}
void oddEvenSort(int *arr,int size)
{
int swapCount;
swapCount=1;
while(swapCount!=0)
{
swapCount=0;
//odd
for(int i=1;i<size-1;i+=2)
{
if(arr[i]>arr[i+1]) 
{
swap(&arr[i],&arr[i+1]);
swapCount++;
}
}
for(int i=0;i<size-1;i+=2)
{
if(arr[i]>arr[i+1]) 
{
swap(&arr[i],&arr[i+1]);
swapCount++;
}
}

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
oddEvenSort(arr,req);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}