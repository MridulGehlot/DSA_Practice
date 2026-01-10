#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> sub(vector<int> &arr)
{
vector<vector<int>> ans;
int size=arr.size();
int end=(1<<size)-1;
for(int i=0;i<=end;i++)
{
vector<int> v;
for(int j=0;j<size;j++)
{
int ff=(i>>j)&1;
if(ff) v.push_back(arr[j]);
}
ans.push_back(v);
}
return ans;
}
int main()
{
vector<int> arr1={76,12,92,-3,76,56,12,93,78,56};
vector<int> arr2={77,7,98,78,76,54,12,92,56,93};
vector<vector<int>> s1,s2;
s1=sub(arr1);
s2=sub(arr2);
int maxi=0;
for(int i=0;i<s1.size();i++)
{
for(int j=0;j<s2.size();j++)
{
if(s1[i].size()!=s2[j].size()) continue;
bool same=true;
for(int k=0;k<s1[i].size();k++)
{
if(s1[i][k]!=s2[j][k])
{
same=false;
break;
}
}
if(same)
{
for(int x:s1[i]) cout<<x<<" ";
cout<<endl;
maxi=max(maxi,(int)s1[i].size());
}
}
}
cout<<"\nMaximum Length of common sub sequences is "<<maxi<<endl;
return 0;
}