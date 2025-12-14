#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main()
{
vector<int> arr={12,45,78,89,56,235,55,12,66,55,55,89,89};
unordered_map<int,int> mp;
for(int &x:arr) mp[x]++;
cout<<"Elem : Freq"<<endl;
for(auto &p:mp) cout<<p.first<<" : "<<p.second<<endl;
return 0;
}