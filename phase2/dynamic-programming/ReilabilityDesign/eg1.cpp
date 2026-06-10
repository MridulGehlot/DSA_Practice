#include<stdio.h>
#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
typedef struct
{
int cost;
double reliability;
}Device;
int comp(void *a,void *b)
{
Device *x,*y;
x=(Device *)a;
y=(Device *)b;
if(x->reliability==y->reliability) return x->cost<y->cost;
return x->reliability<y->reliability;
}
int main()
{
Device devices[3];
devices[0].cost=45000;
devices[0].reliability=0.6;
devices[1].cost=30000;
devices[1].reliability=0.9;
devices[2].cost=25000;
devices[2].reliability=0.7;
int budget=200000;
int required_worth=0;
double reliability=1;
for(int i=0;i<3;++i) 
{
reliability*=devices[i].reliability;
required_worth+=devices[i].cost;
}
printf("Initial Reliability : %lf\n",reliability);
printf("(If We have 1 copy of all items)\n");
int max_possibilities[3];
int x,excess_amount,cost;
excess_amount=budget-required_worth;
//step 1 
//find max possibilities
for(int i=0;i<3;i++)
{
max_possibilities[i]=excess_amount/devices[i].cost;
}
vector<pair<double,int>> arr,temp;
int qty;
double rel;
arr.push_back({1.0,0});
x=0;
for(int i=0;i<3;++i)
{
x+=devices[i].cost;
for(int j=0;j<max_possibilities[i];++j)
{
qty=j+1;
rel=devices[i].reliability;
cost=qty*devices[i].cost;
rel=1.0-pow((1.0-rel),qty);
//product of current set with existing in arr
for(auto &aa:arr)
{
if((aa.second+cost+(required_worth-x))<=budget) temp.push_back({aa.first*rel,aa.second+cost});
}
}
sort(temp.begin(),temp.end());
cout<<"Printing TEMP SET"<<endl;
for(auto p:temp) cout<<p.first<<","<<p.second<<endl;
cout<<endl;
//eliminate flaws
for(int i=1;i<temp.size();++i)
{
if(temp[i-1].second>temp[i].second && temp[i].first>temp[i-1].first)
{
temp.erase(temp.begin()+(i-1));
}
}
arr=temp;
temp.clear();
}
cout<<"Final Cost = "<<arr[arr.size()-1].second<<", Reliability = "<<arr[arr.size()-1].first<<endl;
return 0;
}