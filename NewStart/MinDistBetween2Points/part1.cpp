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
double findMinDistance(vector<pair<int,int>> &arr,int start,int end)
{
double ans=DBL_MAX;
int x1,x2,y1,y2;
double dist;
for(int i=start;i<=end;i++)
{
for(int j=i+1;j<=end;j++)
{
x1=arr[i].first;
y1=arr[i].second;
x2=arr[j].first;
y2=arr[j].second;
dist=distance(x1,y1,x2,y2);
if(dist<ans) 
{
final1.first=x1;
final1.second=y1;
final2.first=x2;
final2.second=y2;
ans=dist;
}
}
}
return ans;
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
int pp=size/2;
//left side
//printf("\nGoing for left side\n\n");
a1=findMinDistance(arr,0,pp-1);
//right side
//printf("\nGoing for Right side\n\n");
a2=findMinDistance(arr,pp,size-1);
if(a1<a2) ans=a1;
else ans=a2;
printf("Minimum Distance Is : %lf\n",ans);
cout<<"\nPoints are : "<<endl;
cout<<final1.first<<","<<final1.second<<"  ----   ";
cout<<final2.first<<","<<final2.second<<endl;
return 0;
}