#include<iostream>
using namespace std;
bool check(const string &s,int i,int j)
{
while(i<j)
{
if(s[i]!=s[j]) return false;
i++;
j--;
}
return true;
}
int main()
{
int start,end,maxi,len;
string ans;
maxi=0;
string s="abarrmalayalamrraab";
for(int i=0;i<s.size();i++)
{
for(int j=i;j<s.size();j++)
{
start=i;
end=j;
if(check(s,start,end))
{
len=end-start+1;
cout<<"Palindromic Substring = "<<s.substr(start,len)<<endl;
if(len>maxi)
{
maxi=len;
ans=s.substr(start,len);
}
}
}
}
cout<<"Longest Palindromic sub string size - "<<maxi<<endl;
cout<<"Longest Palindromic sub string - "<<ans<<endl;

return 0;
}