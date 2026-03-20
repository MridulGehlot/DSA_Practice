class psp
{
public static void main(String gg[])
{
String s="abarrmalayalamrraab";
int maxi,start,n,col;
n=s.length();
start=0;
maxi=1;
int [][] dp=new int[n][n];
for(int i=0;i<n;i++) dp[i][i]=1;
//compare 2 distances
for(int i=0;i<n-1;i++)
{
if(s.charAt(i)==s.charAt(i+1))
{
maxi=2;
start=i;
}
}
//now for 3 to n len fill diagonally
col=2;
int i,j;
while(col<n)
{
i=0;
j=col;
while(i<n && j<n)
{
if(s.charAt(i)==s.charAt(j)) //first and last match
{
dp[i][j]=dp[i+1][j-1];
if(dp[i][j]==1) //valid
{
if(j-i+1>maxi)
{
maxi=j-i+1;
start=i;
}
}
}
else dp[i][j]=0;
i++;
j++;
}
col++;
}
System.out.println("Longest Plaindromic Substring is of legnth - "+maxi);
System.out.println(s.substring(start,maxi+1));
}
}