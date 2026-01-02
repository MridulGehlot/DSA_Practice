//Brute Force
#include<stdio.h>
#include<limits.h>
int main()
{
int arr[10]={10,-3,7,6,-2,4,3,9,-5,12};
int ans,sum;
ans=INT_MIN;
for(int i=0;i<=9;i++)
{
sum=0;
for(int j=i;j<=9;j++)
{
sum+=arr[j];
}
if(sum>ans) ans=sum;
}
printf("Answer - %d",ans);
return 0;
}