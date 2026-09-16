//Climb Stairs
/*
input -> n
step 1/2
Determine Number of ways 
*/

#include<stdio.h>

int solve(int n,int *dp)
{
if(n<=3) return n;
if(dp[n]!=-1) return dp[n];
return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}

int main()
{
int n;
printf("Enter Number of Stairs : ");
scanf("%d",&n);
if(n<0)
{
printf("Invalid Input");
return 1;
}
/*
int dp[n+1];
for(int i=0;i<=n;++i) dp[i]=-1;
*/
int ans;
if(n<=3)
{
ans=n;
}
else
{
int e,f,rr;
e=2;
f=3;
for(int i=4;i<=n;++i)
{
rr=e+f;
e=f;
f=rr;
}
ans=rr;
}
printf("Number of ways = %d",ans);
return 0;
}