#include<bits/stdc++.h>
using namespace std;
queue<queue<pair<int,int>>> subSequencesOfMaxLength(vector<int> &arr)
{
vector<int> flag(arr.size(),0);
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
prev=f;
flag[prev]=1;
}
f++;
}
e++;
if(count>1)
{
if(count<maxi) continue;
if(count>maxi)
{
maxi=count;
while(!ans.empty()) ans.pop();
}
q.push({prev,arr[prev]});
ans.push(q);
}
}
return ans;
}
void print(queue<queue<pair<int,int>>> ans)
{
//printing answer
while(!ans.empty())
{
queue<pair<int,int>> q=ans.front();
ans.pop();
while(!q.empty())
{
pair<int,int> p=q.front();
q.pop();
cout<<"("<<p.first<<") , "<<p.second<<"   ";
}
cout<<endl<<endl;
}
}
int main()
{
vector<int> arr1={76,12,92,-3,76,56,12,93,78,56};
vector<int> arr2={77,7,98,78,76,54,12,92,56,93};
queue<queue<pair<int,int>>> sub1,sub2,ans;

sub1=subSequencesOfMaxLength(arr1);
sub2=subSequencesOfMaxLength(arr2);

cout<<"Max Length Sub sequence of arr1 are : "<<endl;
print(sub1);
cout<<endl;
cout<<"Max Length Sub sequence of arr2 are : "<<endl;
print(sub2);
cout<<endl;


return 0;
}