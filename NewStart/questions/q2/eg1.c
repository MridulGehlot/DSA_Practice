//Find missing number given distinct number from 0 to n
#include<stdio.h>
int findMissingElement(int *x,int n)
{
int sum,expectedSum;
sum=0;
for(int i=0;i<n;i++) sum+=x[i];
expectedSum=(n*(n+1))/2;
return expectedSum-sum;
}

int main()
{
int x[5]={0,3,1,4,2};
printf("Missing Number = %d",findMissingElement(x,5));
return 0;
}