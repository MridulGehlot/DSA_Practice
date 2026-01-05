#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subSequence(vector<int> &arr)
{
int prev,e,f,maxi,count,n;
n=arr.size();
vector<int> flags(n,0);
vector<vector<int>> ans;
e=0;
while(e<=n-2)
{
if(flags[e]) 
{
e++;
continue;
}
vector<int> v;
count=1;
prev=e;
f=e+1;
while(f<=n-1)
{
if(arr[f]>arr[prev])
{
count++;
v.push_back(arr[prev]);
prev=f;
flags[prev]=1;
}
f++;
}
if(count>1) v.push_back(arr[prev]);
if(v.size()>0) 
{
ans.push_back(v);
}
e++;
}
return ans;
}
void print(vector<vector<int>> &ans)
{
for(auto &v:ans)
{
for(int x:v) cout<<x<<" ";
cout<<endl;
}
}
int main()
{
vector<int> arr1={76,12,92,-3,76,56,12,93,78,56};
vector<int> arr2={77,7,98,78,76,54,12,92,56,93};

vector<vector<int>> sub1,sub2,ans;
sub1=subSequence(arr1);
sub2=subSequence(arr2);

cout<<"---- sub sequences of arr1 ----"<<endl;
print(sub1);
cout<<"---- END ----\n"<<endl;

cout<<"---- sub sequences of arr2 ----"<<endl;
print(sub2);
cout<<"---- END ----"<<endl;

int maxi=INT_MIN;
cout<<"\n---- Longest Common sub sequences of arr1,arr2 ----"<<endl;
for(auto &s1:sub1)
{
for(auto &s2:sub2)
{
if(s1.size()!=s2.size()) continue;
bool flag=true;
for(int i=0;i<s1.size();i++)
{
if(s1[i]!=s2[i]) 
{
flag=false;
break;
}
}
if(flag)
{
if((int)s1.size() > maxi) maxi=s1.size();
ans.push_back(s1);
}
}
}

for(auto &v:ans)
{
if(v.size()==maxi)
{
for(int x:v) cout<<x<<" ";
cout<<endl;
}
}
cout<<"---- END ----"<<endl;

return 0;
}