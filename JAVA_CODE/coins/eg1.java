import java.util.Scanner;
public class psp
{
public static int solve(int [] coins,int sum)
{
if(sum==0) return 0;
int res=Integer.MAX_VALUE;
for(int i=0;i<coins.length;i++)
{
if(coins[i]<=sum)
{
int s=solve(coins,sum-coins[i]);
if(s!=Integer.MAX_VALUE) res=Math.min(s+1,res);
}
}
return res;
}
public static void main(String gg[])
{
int coins[]=new int[3];
coins[0]=2;
coins[1]=5;
coins[2]=10;
Scanner sc=new Scanner(System.in);
System.out.print("Enter the Denomination to make - ");
int x=sc.nextInt();
int mini=solve(coins,x);
System.out.println("Minimum Number of Coins Required - "+mini);
}
}