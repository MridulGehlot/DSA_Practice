//Find missing number given distinct number from 0 to n
#include<stdio.h>
int findMissingElement(int *x,int n)
{
int var,i;
var=0;
for(i=0;i<n;i++)
{
var=var^i^x[i];
}
return var^n;
}

int main()
{
int x[5]={0,3,1,5,2};
printf("Missing Number = %d",findMissingElement(x,5));
return 0;
}