class psps
{
public static void main(String gg[])
{
int [] wt={1,5,10,15,20,22};
int [] val={5,2,6,4,5,3};
int cap=25;
int [][] dp=new int[wt.length+1][cap+1];
for(int i=1;i<=wt.length;i++)
{
for(int j=1;j<=cap;j++)
{
if(wt[i-1]<=j) //we can pick
{
dp[i][j]=Math.max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
}
else dp[i][j]=dp[i-1][j];
}
}
System.out.println("Max Profit we can make - "+dp[wt.length][cap]);
}
}