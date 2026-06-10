#include<stdio.h>
int main()
{
int graph[4][4]={
{0,1,999,2},
{999,0,1,999},
{2,3,0,3},
{2,2,2,0}
};
//999 is INFINITY
//via loop
for(int k=0;k<4;++k)
{
for(int i=0;i<4;++i)
{
for(int j=0;j<4;++j)
{
if(graph[i][k]+graph[k][j]<graph[i][j]) graph[i][j]=graph[i][k]+graph[k][j];
}
}
}
for(int i=0;i<4;++i)
{
for(int j=0;j<4;++j)
{
printf("%d ",graph[i][j]);
}
printf("\n");
}
return 0;
}