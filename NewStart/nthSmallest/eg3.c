#include<stdio.h>
void swap(int *a,int *b)
{
int g=*a;
*a=*b;
*b=g;
}
//Method 3 Max Heap of Size k
int findSmallest(int *arr,int size,int k)
{
int ri,ci,index,y;
//create max heap of size k
y=1;
while(y<k)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ci]>arr[ri])
{
swap(&arr[ci],&arr[ri]);
ci=ri;
}
else break;
}
y++;
}
//traverse remaining elements
while(y<size)
{
if(arr[y]<arr[0])
{
swap(&arr[y],&arr[0]);
//heapify
for(int i=1;i<k;i++)
{
ci=i;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ci]>arr[ri])
{
swap(&arr[ci],&arr[ri]);
ci=ri;
}
else break;
}
}
//heapify ends here
}
y++;
}
return arr[0];
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