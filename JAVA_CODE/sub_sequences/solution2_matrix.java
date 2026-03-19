public class Sqeuence
{
public static int x[];
public static int y[];
static
{
x=new int[8];
for(int i=0;i<8;i++) x[i]=i;
y=new int[6];
for(int i=0;i<6;i++) y[i]=i;
y[4]=19;
y[2]=54;
}
public static void main(String gg[])
{
int dp[][]=new int[x.length+1][y.length+1];
int maxi=0;
for(int i=1;i<=x.length;i++)
{
for(int j=1;j<=y.length;j++)
{
if(x[i-1]==y[j-1]) dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
maxi=Math.max(dp[i][j],maxi);
}
}
System.out.println("Length of LCS is "+maxi);
System.out.println("Trying to print Result");
for(int i=0;i<=x.length;i++)
{
for(int j=0;j<=y.length;j++)
{
if(i<x.length && j<y.length)
{
if(dp[i][j]+1==dp[i+1][j+1]) 
{
if(dp[i][j]==dp[i][j+1] && dp[i][j]==dp[i+1][j])
{
System.out.print(x[j]);
//System.out.print("i - "+i+" , j - "+j+"\n");
}
}
}
}
}

}
}