/*
Find Missing NUmber (Not DIstinct)
input -> sz  n(1-n)

arr[n] 0 -> n-1

1. Counting
2. Indexing
*/
#include<stdio.h>
#include<stdlib.h>

void approach1(int *arr,int sz,int n)
{
int tmp[n];
for(int i=0;i<n;++i) tmp[i]=0;

for(int i=0;i<sz;++i) tmp[arr[i]-1]++;

printf("Missing Elements are :\n");
for(int i=0;i<n;++i) if(tmp[i]==0) printf("%d ",i+1);
}

void approach2(int *arr,int sz,int n)
{
int elem;
for(int i=0;i<sz;++i)
{
elem=abs(arr[i]);
if(arr[elem-1]>0) arr[elem-1]*=-1;
}

printf("Missing Elements are :\n");
for(int i=0;i<n;++i) if(arr[i]>0) printf("%d ",i+1);
}


int main()
{
int arr[8]={2,2,4,3,2,3,2,3};
int sz=8;
int n=5;
approach1(arr,sz,n);
approach2(arr,sz,n);
return 0;
}
