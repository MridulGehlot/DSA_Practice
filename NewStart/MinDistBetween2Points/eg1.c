#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>
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
int main()
{
int arr[10][10]={{1,2},{5,4},{7,8},{10,10},{8,5},{3,7},{2,8},{9,6},{7,7},{2,3}};
double ans=DBL_MAX;
int x1,x2,y1,y2;
double dist;
for(int i=0;i<10;i++)
{
for(int j=i+1;j<10;j++)
{
x1=arr[i][0];
y1=arr[i][1];
x2=arr[j][0];
y2=arr[j][1];
dist=distance(x1,y1,x2,y2);
//printf("Dist - %lf\n",dist);
//printf("Ans - %lf\n",ans);
if(dist<ans) ans=dist;
}
}
printf("Minimum Distance Is : %lf",ans);
return 0;
}