public class Sqeuence
{
public static int x[];
public static int y[];
public static int copies;
public static int dp[][];
static
{
x=new int[8];
for(int i=0;i<8;i++) x[i]=i;
y=new int[6];
for(int i=0;i<6;i++) y[i]=i;
y[4]=19;
y[2]=54;
dp=new int[8][6];
}
public static int findLengthOfLCS(int e,int f)
{
copies++;
if(e==x.length || f==y.length) return 0;
if(x[e]==y[f]) return 1+findLengthOfLCS(e+1,f+1);
int l=findLengthOfLCS(e+1,f);
int r=findLengthOfLCS(e,f+1);
return Math.max(l,r);
}

public static int findLengthOfLCSDP(int e,int f)
{
copies++;
if(e==x.length || f==y.length) return 0;
if(dp[e][f]!=0) return dp[e][f];
if(x[e]==y[f]) return dp[e][f]=1+findLengthOfLCSDP(e+1,f+1);
int l=findLengthOfLCSDP(e+1,f);
int r=findLengthOfLCSDP(e,f+1);
return dp[e][f]=Math.max(l,r);
}

public static void main(String gg[])
{
copies=0;
System.out.println("Length of LCS is "+findLengthOfLCS(0,0));
System.out.println("Number of copies "+copies);
copies=0;
System.out.println("Length of LCS is "+findLengthOfLCSDP(0,0));
System.out.println("Number of copies "+copies);
}
}