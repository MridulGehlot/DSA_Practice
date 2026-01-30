#include<bits/stdc++.h>
using namespace std;
int main()
{
int size,capacity,end,x,y;
capacity=25;
size=6;
vector<int> w={1,5,10,15,20,22};
vector<int> v={5,2,6,4,5,3};
vector<pair<int,int>> arr;
arr.push_back({0,0});
for(int i=0;i<size;i++)
{
end=arr.size();
for(int j=0;j<end;j++)
{
auto &p=arr[i];
x=p.first;
y=p.second;
x+=v[i];
y+=w[i];
if(y<=capacity) arr.push_back({x,y});
}
sort(arr.begin(),arr.end());
auto it=arr.begin();
auto prev=it;
++it;
while(it!=arr.end())
{
if(it->first<prev->first || it->second<prev->second)
{
arr.erase(prev);
}
prev=it;
++it;
}
}
auto it=arr.rbegin();
cout<<"Max Value - "<<it->first<<" ,Max Weight - "<<it->second;
return 0;
}