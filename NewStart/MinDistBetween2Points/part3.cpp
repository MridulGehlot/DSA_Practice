#include<bits/stdc++.h>
using namespace std;
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
typedef struct _point
{
int x,y;
}Point;
bool xAxis(Point &a,Point &b)
{
return a.x<b.x;
}
bool yAxis(Point &a,Point &b)
{
return a.y<b.y;
}
double findMinDistance(vector<Point> &arr,int start,int end)
{
double ans=DBL_MAX;
int x1,x2,y1,y2;
double dist;
for(int i=start;i<=end;i++)
{
for(int j=i+1;j<=end;j++)
{
x1=arr[i].x;
y1=arr[i].y;
x2=arr[j].x;
y2=arr[j].y;
dist=distance(x1,y1,x2,y2);
if(dist<ans) 
{
/*
final1.first=x1;
final1.second=y1;
final2.first=x2;
final2.second=y2;
*/
ans=dist;
}
}
}
return ans;
}
int main()
{
vector<Point> arr;
Point p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
p1.x=1;p1.y=2;
arr.push_back(p1);
p2.x=5;p2.y=4;
arr.push_back(p2);
p3.x=7;p3.y=8;
arr.push_back(p3);
p4.x=10;p4.y=10;
arr.push_back(p4);
p5.x=8;p5.y=5;
arr.push_back(p5);
p6.x=3;p6.y=7;
arr.push_back(p6);
p7.x=2;p7.y=8;
arr.push_back(p7);
p8.x=9;p8.y=6;
arr.push_back(p8);
p9.x=7;p9.y=7;
arr.push_back(p9);
p10.x=2;p10.y=3;
arr.push_back(p10);

sort(arr.begin(),arr.end(),xAxis);

double ans=DBL_MAX;
double a1,a2;
int size=arr.size();
int pp=size/2;

a1=findMinDistance(arr,0,pp);
a2=findMinDistance(arr,pp+1,size-1);
if(a1<a2) ans=a1;
else ans=a2;

//find mid x
double xSum=0.0;
double midX;
for(Point &p:arr) xSum+=p.x;
midX=xSum/size;
cout<<"Sumx - "<<xSum<<endl;
cout<<"Mid x - "<<midX<<endl;
cout<<"left side - "<<(midX-ans)<<endl;
cout<<"right side - "<<(midX+ans)<<endl;
printf("Minimum Distance Is : %lf\n",ans);
return 0;
}