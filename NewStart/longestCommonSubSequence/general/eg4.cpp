#include<bits/stdc++.h>
using namespace std;
int main()
{
int flag[10]={0};
int arr[10]={76,12,92,-3,76,56,12,93,78,56};
int prev,e,f,maxi,count;
vector<pair<int,int>> indexes;
e=0;
maxi=0;
while(e<=8)
{
if(flag[e]) 
{
e++;
continue;
}
count=1;
prev=e;
f=e+1;
while(f<=9)
{
if(arr[f]>arr[prev])
{
count++;
maxi=max(maxi,count);
prev=f;
flag[prev]=1;
}
f++;
}
if(count>1) indexes.push_back({e,prev});
e++;
}

//printing answer
for(auto &p:indexes)
{
cout<<"(e,f) -> ("<<p.first<<","<<p.second<<")"<<endl;
prev=-1;
for(int i=p.first;i<=p.second;i++) 
{
if(arr[i]>prev)
{
prev=arr[i];
cout<<arr[i]<<" ";
}
}
cout<<endl;
}
return 0;
}