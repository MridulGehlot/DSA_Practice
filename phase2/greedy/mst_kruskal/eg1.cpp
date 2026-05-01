#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<pair<string,int>> edges={
{"AB",1},
{"BC",2},
{"BD",2},
{"CD",3},
{"AC",4}
};
int mst[4][4]={
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0}
};

//sort the edges i have feeded already in sorted order
vector<char> vertices={'A','B','C','D'};
vector<int> ranks={1,2,3,4};
int v1,v2,wt,oldRank;
for(int i=0;i<edges.size();i++)
{
pair<string,int> p=edges[i];
v1=p.first[0]-'A';
v2=p.first[1]-'A';
wt=p.second;
if(ranks[v1]!=ranks[v2]) // does not form a cycle we can add this edge
{
//cout<<"v1 - "<<v1<<" , v2 - "<<v2<<" wt - "<<wt<<endl;
//cout<<"rank of v1 - "<<ranks[v1]<<" ,Ranks of v2 - "<<ranks[v2]<<endl;
oldRank=ranks[v1];
for(int j=0;j<ranks.size();j++) if(ranks[j]==oldRank) ranks[j]=ranks[v2];
//for(int j=0;j<ranks.size();j++) cout<<ranks[j]<<" ";
//cout<<endl;
mst[v1][v2]=wt;
}
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