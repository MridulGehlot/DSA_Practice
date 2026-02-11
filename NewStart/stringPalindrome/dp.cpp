#include<iostream>
using namespace std;
int main()
{
int maxi,sp,ep;
string s="abarrmalayalamrraab";
int n=s.size();
bool dp[n][n];

// default;
sp=ep=0;
maxi=1;

//pre processing done
for(int i=0;i<n;i++)
{
for(int j=0;j<=i;j++)
{
if(i==j) dp[i][j]=true;
else dp[i][j]=false;
}
}

//len 2
for(int i=0;i<n-1;i++)
{
if(s[i]==s[i+1]) 
{
maxi=2;
sp=i;
ep=sp+1;
dp[i][i+1]=true;
}
else dp[i][i+1]=false;
}

//len 3 or more
int i,j;
int idx=2;
while(idx<n)
{
i=0;
j=idx++;
while(i<n && j<n)
{
if(s[i]!=s[j])
{
dp[i][j]=false;
}
else
{
if(dp[i+1][j-1]==true)
{
maxi=j-i+1;
sp=i;
ep=j;
dp[i][j]=true;
}
else dp[i][j]=false;
}
i++;
j++;
}
}
cout<<"Longest Palindromic Substring is - "<<maxi<<endl;
cout<<"String - "<<s.substr(sp,ep-sp+1)<<endl;
return 0;
}