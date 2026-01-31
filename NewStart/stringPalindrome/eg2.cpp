#include<bits/stdc++.h>
using namespace std;
int help(const string &s,int idx)
{
int count=1;
int left=idx-1;
int right=idx+1;
while(left>=0 && right<s.size())
{
if(s[left]!=s[right]) break;
left--;
right++;
count+=2;
}
return count;
}
int main()
{
string s="abarrmalayalamrraab";
string ss="!";
for(char ch:s)
{
ss+=ch;
ss+="!";
}
ss+="!";
vector<int> arr(ss.size(),0);
for(int i=1;i<ss.size();i++) arr[i]=help(ss,i);
auto it=max_element(arr.begin(),arr.end());
int maxi=*it;
int idx=it-arr.begin();
maxi/=2;
cout<<"Longest Plaindromic substring length is = "<<maxi<<endl;
return 0;
}