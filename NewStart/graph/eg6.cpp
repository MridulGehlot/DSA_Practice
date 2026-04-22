#include<bits/stdc++.h>
using namespace std;
int main()
{
char vertices[6]={'A','B','C','D','E','F'};
int graph[6][6]={
{0,0,3,2,1,0},
{0,0,3,0,2,0},
{3,3,0,4,0,0},
{2,0,4,0,7,4},
{1,2,0,7,0,5},
{0,0,0,4,5,0}
};
unordered_set<string> st;
vector<pair<string,int>> arr;
for(int i=0;i<6;i++)
{
string ss=to_string(vertices[i]);
for(int j=0;j<6;j++)
{
if(i==j) continue;
string s=s+vertices[j];
sort(s.begin(),s.end());
if(st.count(s)) continue;
st.insert(s);
arr.push_back({s,graph[i][j]});
}
}
sort(arr.begin(),arr.end(),[](pair<string,int> &a,pair<string,int> &b){return a.second<b.second;});
st.clear();
cout<<"Building MST"<<endl;

for(auto &p:arr)
{
string s=p.first;
int cost=p.second;
if(st.count(s)) continue;
st.insert(s);
cout<<s<<" "<<cost<<endl;
}

return 0;
}