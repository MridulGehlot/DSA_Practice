#include<stdio.h>
#include<mg_sort.h>
int cmp(void *a,void *b)
{
int *x,*y;
x=(int *)a;
y=(int *)b;
return *x-*y;
}
int main()
{
int arr[5]={45,12,78,32,44};
mergeSort(arr,5,sizeof(int),cmp);
for(int i=0;i<5;i++) printf("%d ",arr[i]);
}