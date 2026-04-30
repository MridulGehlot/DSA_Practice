#include<stdio.h>
int main()
{
int graph[4][4]={
{0,1,4,0},
{1,0,2,2},
{4,2,0,3},
{0,2,3,0}
};
int partOfMST[4]={0,0,0,0};
//initially make 1st node as part of MST
partOfMST[0]=1;
int mst[4][4]={
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0}
};
int edgeCount=0;
int v1,v2,wt;
while(edgeCount<3)
{
wt=99999;
for(int e=0;e<4;e++)
{
if(partOfMST[e])
{
for(int f=0;f<4;f++)
{
if(graph[e][f]!=0 && partOfMST[f]!=1 && graph[e][f]<wt)
{
wt=graph[e][f];
v1=e;
v2=f;
}
}
}//if part of MST then on add Check Others
} //v1 loop
partOfMST[v2]=1;
mst[v1][v2]=wt;
edgeCount++;
//printf("v1 = %d , v2 = %d, wt = %d\n",v1,v2,wt);
//printf("EdgeCount %d \n",edgeCount);
}
printf("The Required Minimum Spanning Tree is\n");
for(int e=0;e<4;e++)
{
for(int f=0;f<4;f++)
{
printf("%4d",mst[e][f]);
}
printf("\n");
}
return 0;
}