#include<stdio.h>
void swap(int *a,int *b)
{
int g=*a;
*a=*b;
*b=g;
}
//Method 1 Partition Point
int findSmallest(int *arr,int size,int k)
{
int swapCount,index;
index=k-1;
do
{
swapCount=0;
for(int i=0;i<index;i++)
{
if(arr[i]>arr[index])
{
swap(&arr[i],&arr[index]);
swapCount++;
break;
}
}
for(int i=size-1;i>index;i--)
{
if(arr[i]<arr[index])
{
swap(&arr[i],&arr[index]);
swapCount++;
break;
}
}
}while(swapCount!=0);
return arr[index];
}
int main()
{
int k,ans;
int arr[10]={12,45,78,89,56,23,10,94,76,61};
printf("Enter k - ");
scanf("%d",&k);
ans=findSmallest(arr,10,k);
printf("%d th smallest in array is %d",k,ans);
return 0;
}