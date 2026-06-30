#include<stdio.h>
#include<math.h>
int jump_search(int arr[],int sz,int key)
{
int i,jump,j,ep;
jump=sqrt(sz);
i=0;
while(i<sz)
{
if(arr[i]>key) break;
i+=jump;
}
//reverse linear order
ep=i;
if(i>=sz) ep=sz-1;
j=ep;
while(j>=0 && j>=ep-jump)
{
if(arr[j]==key) return j;
j--;
}
return -1;
}
int main()
{
int arr[10]={11,12,23,45,56,77,78,79,80,90};
printf("%d\n",jump_search(arr,10,79));
return 0;
}