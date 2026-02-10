#include<stdio.h>
int temp[10]={0};
void preCompute(int *x,int sz)
{
for(int i=0;i<sz;i++)
{
if(i>0) temp[i]=x[i]+temp[i-1];
else temp[i]=x[i];
}
}
int getRangeSum(int s,int e)
{
if(s==0) return temp[e];
return temp[e]-temp[s-1];
}
int main()
{
int x[10]={2,34,12,2,5,6,9,3,1,5};
preCompute(x,10);
printf("Range sum from %d to %d is %d",3,6,getRangeSum(3,6));
return 0;
}