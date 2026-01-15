#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int dp[1001];
int solve(int val,int sum,int count)
{
if(sum==val) return count;
if(sum>val) return val;
if(dp[sum]!=-1) return dp[sum];
int a=solve(val,sum+10,count+1);
int b=solve(val,sum+5,count+1);
int c=solve(val,sum+2,count+1);
int x=a<b?a:b;
int ans=x<c?x:c;
return dp[sum]=ans;
}
int main()
{
memset(dp, -1, sizeof(dp));
int val;
printf("Enter the value (should be >3) -> ");
scanf("%d",&val);
if(val<=3)
{
printf("INVALID VALUE\n");
return 0;
}
int ans=solve(val,0,0);
printf("Minimum %d Number of coins are required\n",ans);
return 0;
}