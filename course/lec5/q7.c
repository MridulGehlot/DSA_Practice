//range sum
/*
arr = [1,5,3,4,68,2,45,10]
input start,end
O(n)

Prefix Sum -> O(1)
*/
#include<stdio.h>

int main()
{
int arr[5]={1,2,3,4,5};
int temp[5];
//cumilitive sum
//{1,3,6,10,15}
temp[0]=arr[0];
for(int i=1;i<5;++i)
{
temp[i]=arr[i]+temp[i-1];
}
int s,e;
scanf("%d",&s);
scanf("%d",&e);
int sum=temp[e]- (s!=0?temp[s-1]:0);
printf("Range SUm is %d",sum);
return 0;
}