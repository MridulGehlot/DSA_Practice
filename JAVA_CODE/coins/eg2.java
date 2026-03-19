import java.util.Scanner;
public class psp
{
public static void main(String gg[])
{
int coins[]=new int[3];
coins[0]=2;
coins[1]=3;
coins[2]=5;
Scanner sc=new Scanner(System.in);
System.out.print("Enter the Denomination to make - ");
int x=sc.nextInt();

int dp[][]=new int[coins.length+1][x+1];
for(int i=0;i<=x;i++) dp[0][i]=Integer.MAX_VALUE-1;

for(int j=1;j<=coins.length;j++)
{
for(int i=1;i<=x;i++)
{
if(coins[j-1]<=i)//possible
{
dp[j][i]=Math.min(dp[j-1][i],dp[j][i-coins[j-1]]+1);
}
else dp[j][i]=dp[j-1][i];
}
}

System.out.println("Minimum Number of Coins Required - "+dp[coins.length][x]);
}
}