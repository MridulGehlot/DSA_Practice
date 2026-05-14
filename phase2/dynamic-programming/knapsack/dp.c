#include<stdio.h>

int main()
{
int e,f,numberOfItems,capacity;
typedef struct
{
int price;
int weight;
}item;
item items[5]={
{10,3},
{11,2},
{12,5},
{60,1},
{40,4}
};
item tmp;
numberOfItems=5;
capacity=9;
//sort the items in ascending order by weight
for(e=0;e<numberOfItems-1;e++)
{
for(f=e+1;f<numberOfItems;f++)
{
if(items[f].weight<items[e].weight)
{
tmp=items[f];
items[f]=items[e];
items[e]=tmp;
}
}
}
int dp[numberOfItems+1][capacity+1];
for(int i=0;i<=capacity;i++) dp[0][i]=0;
for(int i=0;i<=numberOfItems;i++) dp[i][0]=0;
for(int i=1;i<=numberOfItems;i++)
{
for(int j=1;j<=capacity;j++)
{
if(items[i-1].weight<=j)
{
e=dp[i-1][j];
f=dp[i-1][j-items[i-1].weight]+items[i-1].price;
if(e>f) dp[i][j]=e;
else dp[i][j]=f;
}
else dp[i][j]=dp[i-1][j];
}
}
printf("Total Profit : %d\n",dp[numberOfItems][capacity]);
return 0;
}