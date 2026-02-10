#include<stdio.h>
int getMaxProfit(int *x,int size)
{
int maxi,i,bestBuy,profit;
maxi=0;
bestBuy=x[0];
for(i=1;i<size;i++)
{
if(x[i]<bestBuy) bestBuy=x[i];
else
{
profit=x[i]-bestBuy;
if(profit>maxi) maxi=profit;
}
}
return maxi;
}
int main()
{
//int x[10]={3,56,12,2,34,12,67,2,23,10};
int x[10]={50,50,50,50,50,50,50,40,30,20};
printf("Max Profit = %d\n",getMaxProfit(x,10));
return 0;
}