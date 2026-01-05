#include<bits/stdc++.h>
using namespace std;
int main()
{
int flag[20]={0};
int arr[20]={12,3,92,-3,76,54,12,93,78,45,56,23,89,51,20,88,30,44,62,10};
int prev,e,f,maxi,count;
vector<vector<int>> ans;
e=0;
maxi=0;
while(e<=18)
{
if(flag[e]) 
{
e++;
continue;
}
vector<int> v;
count=1;
prev=e;
f=e+1;
while(f<=19)
{
if(arr[f]>arr[prev])
{
count++;
maxi=max(maxi,count);
v.push_back(arr[prev]);
prev=f;
flag[prev]=1;
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
//print ans
cout<<"maxi - "<<maxi<<endl;
cout<<"size - "<<ans.size()<<endl;
/*
for(auto &v:ans)
{
//cout<<"v - "<<v.size()<<endl;
if(v.size()==maxi)
{
for(int x:v) cout<<x<<" ";
cout<<endl;
}
}
*/
return 0;
}