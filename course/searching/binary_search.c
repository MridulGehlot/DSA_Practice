#include<stdio.h>
int binary_search(int arr[],int sz,int key)
{
int lb,ub,mid;
lb=0;
ub=sz-1;
while(lb<=ub)
{
mid=(lb+ub)/2;
if(arr[mid]==key) return mid;
if(arr[mid]>key) ub=mid-1;
else lb=mid+1;
}
return -1;
}
int main()
{
int arr[10]={11,12,23,45,56,77,78,79,80,90};
printf("%d\n",binary_search(arr,10,56));
return 0;
}