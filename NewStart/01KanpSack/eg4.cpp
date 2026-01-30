#include<bits/stdc++.h>
using namespace std;
int main()
{
int size,capacity,end,x,y;
capacity=25;
size=6;
vector<int> w={1,5,10,15,20,22};
vector<int> v={5,2,6,4,5,3};
vector<vector<pair<int,int>>> ans;
ans.push_back({make_pair(0,0)});
for(int i=0;i<size;i++)
{
auto &prev_arr=ans[ans.size()-1];
vector<pair<int,int>> arr=prev_arr;
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
vector<pair<int,int>> unique_arr;
for(auto &p:arr)
{
if(unique_arr.empty() || (unique_arr.back().first<p.first && unique_arr.back().second<p.second))
{
unique_arr.push_back(p);
}
else
{
unique_arr.pop_back();
unique_arr.push_back(p);
}
}
ans.push_back(unique_arr);
}
pair<int,int> result=ans[size-1][size-1];
x=result.first;
y=result.second;
cout<<"Max Value - "<<x<<" ,Max Weight - "<<y<<endl;
/*
int idx=size-2;
while(idx>0)
{
vector<pair<int,int>> &arr=ans[idx];
bool found=false;
for(int i=0;i<arr.size();i++)
{
if(arr[i].first==result.first && arr[i].second==result.second)
{
found=true;
break;
}
}
if(!found)
{
cout<<"Choosen idx = "<<idx<<" ,wt = "<<w[idx]<<" ,val = "<<v[idx]<<endl;
result.first-=v[idx];
result.second-=w[idx];
}
idx--;
}
cout<<"Choosen idx = "<<(0)<<" ,wt = "<<result.second<<" ,val = "<<result.first<<endl;
*/
return 0;
}