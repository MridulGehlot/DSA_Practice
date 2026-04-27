#include<stdio.h>
int bs(int *arr,int lb,int ub,int key)
{
if(lb<=ub)
{
int mid=(lb+ub)/2;
if(arr[mid]==key) return mid;
if(key>arr[mid]) return bs(arr,mid+1,ub,key);
else return bs(arr,lb,mid-1,key);
}
return -1;
}
int main()
{
int arr[10]={12,13,23,24,45,46,56,78,89,95};
int x,idx;
printf("Enter Element To Search : ");
scanf("%d",&x);
idx=bs(arr,0,9,x);
if(idx==-1) printf("Element Not Found");
else printf("Element Found at INdex %d\n",idx);
return 0;
}