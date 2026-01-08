#include<bits/stdc++.h>
using namespace std;
int main()
{
int flag[10]={0};
int arr[10]={76,12,92,-3,76,56,12,93,78,56};
int prev,e,f,maxi,count;
queue<queue<pair<int,int>>> ans;
e=0;
maxi=0;
while(e<=8)
{
if(flag[e]) 
{
e++;
continue;
}
queue<pair<int,int>> q;
count=1;
prev=e;
f=e+1;
while(f<=9)
{
if(arr[f]>arr[prev])
{
count++;
q.push({prev,arr[prev]});
maxi=max(maxi,count);
prev=f;
flag[prev]=1;
}
f++;
}
if(count>1)
{
q.push({prev,arr[prev]});
ans.push(q);
}
e++;
}

//printing answer
while(!ans.empty())
{
queue<pair<int,int>> q=ans.front();
ans.pop();
while(!q.empty())
{
pair<int,int> p=q.front();
q.pop();
cout<<p.first<<" , "<<p.second<<endl;
}
cout<<endl<<endl;
}

return 0;
}