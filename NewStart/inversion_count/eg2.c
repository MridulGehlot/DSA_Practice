#include<stdio.h>
#include<stdlib.h>
int merge(int *arr,int lb,int mid,int ub,int *tmp)
{
int a,b,c,count;
a=lb;
b=mid+1;
c=0;
count=0;
while(a<=mid && b<=ub)
{
if(arr[a]<=arr[b])
{
tmp[c++]=arr[a++];
}
else
{
//case of inversion
count+=mid-a+1;
tmp[c++]=arr[b++];
}
}
while(a<=mid)
{
tmp[c++]=arr[a++];
}
while(b<=ub)
{
tmp[c++]=arr[b++];
}
c=0;
a=lb;
while(a<=ub)
{
arr[a++]=tmp[c++];
}
return count;
}
int mergeSort(int *arr,int lb,int ub,int *tmp)
{
int count=0;
if(lb<ub)
{
int mid=(lb+ub)/2;
count+=mergeSort(arr,lb,mid,tmp);
count+=mergeSort(arr,mid+1,ub,tmp);
count+=merge(arr,lb,mid,ub,tmp);
}
return count;
}
int invCount(int *arr,int size)
{
int *tmp=(int *)malloc(sizeof(int)*size);
int count=mergeSort(arr,0,size-1,tmp);
free(tmp);
return count;
}
int main()
{
int arr[10]={6,4,12,3,32,76,54,19,27,62};
int count=invCount(arr,10);
printf("Total Number of inversions - %d\n",count);
}