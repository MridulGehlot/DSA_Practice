#include<stdio.h>
int linear_search(int arr[],int sz,int key)
{
for(int i=0;i<sz;++i) if(arr[i]==key) return i;
return -1;
}
int main()
{
int arr[10]={11,12,23,45,56,77,78,79,80,90};
printf("%d\n",linear_search(arr,10,55));
return 0;
}