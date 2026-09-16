/*
Stock buy sell
input -> prices
1 time buy 1 time sell
max profit
*/
#include<stdio.h>
int main()
{
int arr[10]={20,5,64,10,87,21,30,4,5,62};
int best_buy,profit,ans;
ans=0;
best_buy=9999999;
profit=0;
for(int i=0;i<10;++i)
{
if(arr[i]<best_buy) best_buy=arr[i];
else
{
profit=arr[i]-best_buy;
if(profit>ans) ans=profit;
}
}
printf("Maximum Profit That Can be Achieved is : %d",ans);
return 0;
}