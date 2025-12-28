#include<stdio.h>
int main()
{
int arr[10]={0,1,2,3,4,5,6,7,8,9};
for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
for(int k=0;k<10;k++)
{
printf("%d%d%d ",arr[i],arr[j],arr[k]);
}
}
}
return 0;
}