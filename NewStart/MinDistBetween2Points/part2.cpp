#include<bits/stdc++.h>
using namespace std;
pair<int,int> final1,final2;
double distance(int x1,int y1,int x2,int y2)
{
double x=x2-x1;
double y=y2-y1;
x=x*x;
y=y*y;
double ans=x+y;
ans=sqrt(ans);
return ans;
}
double solve(vector<pair<int,int>>& arr,int lb,int ub)
{
if(lb<ub)
{
int size=ub-lb+1;
if(size==2)
{
double ans=distance(arr[lb].first,arr[lb].second,arr[ub].first,arr[ub].second);
cout<<"\nCalculating Ans\n";
cout<<"lb - "<<lb<<",ub - "<<ub<<endl;
cout<<"ans = "<<ans<<endl;
return ans;
}
int mid=(lb+ub)/2;
double a1=solve(arr,lb,mid);
double a2=solve(arr,mid+1,ub);
cout<<"\n\nlb - "<<lb<<",ub - "<<ub<<endl;
cout<<"a1 - "<<a1<<" ,a2 -  "<<a2<<endl;
return a1>a2?a2:a1;
}
else return DBL_MAX;
}
int main()
{
vector<pair<int,int>> arr;
arr.push_back({1,2});
arr.push_back({5,4});
arr.push_back({7,8});
arr.push_back({10,10});
arr.push_back({8,5});
arr.push_back({3,7});
arr.push_back({2,8});
arr.push_back({9,6});
arr.push_back({7,7});
arr.push_back({2,3});
double ans=DBL_MAX;
double a1,a2;
sort(arr.begin(),arr.end());
int size=arr.size();
ans=solve(arr,0,size-1);
printf("Minimum Distance Is : %lf\n",ans);
//cout<<"\nPoints are : "<<endl;
//cout<<final1.first<<","<<final1.second<<"  ----   ";
//cout<<final2.first<<","<<final2.second<<endl;
return 0;
}