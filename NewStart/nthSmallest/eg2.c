#include<stdio.h>
void swap(int *a,int *b)
{
int g=*a;
*a=*b;
*b=g;
}
//Method 2 Min Heap
int findSmallest(int *arr,int size,int k)
{
//create min heap
int ci,ri,y,index;
y=1;
while(y<size)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ci]<arr[ri])
{
swap(&arr[ci],&arr[ri]);
ci=ri;
}
else break;
}
y++;
}
// pop k-1 from min heap
index=size-1;
for(int i=0;i<k-1;i++)
{
swap(&arr[0],&arr[index]);
index--;
y=1;
while(y<=index)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ci]<arr[ri])
{
swap(&arr[ci],&arr[ri]);
ci=ri;
}
else break;
}
y++;
}
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