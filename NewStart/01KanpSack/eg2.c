#include<stdio.h>
int main()
{
int capacity,size,row,col,x,y,maxi;
capacity=25;
size=6;
int w[]={1,5,10,15,20,22};
int v[]={5,2,6,4,5,3};
row=size+1;
col=capacity+1;
int dp[row][col];
//setup
for(int i=0;i<row;i++) dp[i][0]=0;
for(int i=0;i<col;i++) dp[0][i]=0;
//calculations
for(int i=1;i<row;i++)
{
for(int j=1;j<col;j++)
{
if(w[i-1]<=j)
{
x=dp[i-1][j];
y=dp[i-1][j-w[i-1]]+v[i-1];
maxi=x>y?x:y;
dp[i][j]=maxi;
}
else dp[i][j]=dp[i-1][j];
}
}
printf("Max Value that we can obtain is %d\n",dp[row-1][col-1]);
/*
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
printf("%d ",dp[i][j]);
}
printf("\n");
}
*/
return 0;
}