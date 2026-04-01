#include<stdio.h>
int main()
{
int graph[8][8]={
{4,7,-1,-1,-1,-1,-1,-1},
{3,5,6,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1},
{2,-1,-1,-1,-1,-1,-1,-1},
{1,-1,-1,-1,-1,-1,-1,-1},
{2,-1,-1,-1,-1,-1,-1,-1},
{3,-1,-1,-1,-1,-1,-1,-1},
{4,-1,-1,-1,-1,-1,-1,-1},
};
int vis[8]={0,0,0,0,0,0,0,0};
int path[8]={0,1,2,3,4,5,6,7};
char nodes[8]={'A','B','C','D','E','F','G','H'};
char src,dst;
int srcIndex,dstIndex;
printf("Enter The Source Node (A,B,C,D,E,F,G,H) : ");
src=getchar();
fflush(stdin);
printf("Enter The Destination Node (A,B,C,D,E,F,G,H) : ");
dst=getchar();
fflush(stdin);
srcIndex=dstIndex=-1;
for(int i=0;i<=7;i++)
{
if(nodes[i]==src) srcIndex=i;
if(nodes[i]==dst) dstIndex=i;
}
if(srcIndex==-1) printf("Invalid Source %c\n",src);
if(dstIndex==-1) printf("Invalid Destination %c\n",dst);
if(srcIndex==-1 || dstIndex==-1) return 0;
int queue[100];
int front,rear,n,adj;
front=rear=0;
queue[rear]=srcIndex;
rear++;
vis[srcIndex]=1;
while(rear!=0)
{
n=queue[front++];
if(front==rear) front=rear=0;
for(int i=0;i<=7 && graph[n][i]!=-1;i++)
{
adj=graph[n][i];
if(vis[adj]) continue;
vis[adj]=1;
path[adj]=n;
if(adj==dstIndex) break;
queue[rear++]=adj;
}
if(vis[dstIndex]) break;
}
if(!vis[dstIndex])
{
printf("No Valid Path Exists from %c to %c\n",src,dst);
return 0;
}
int stack[8];
int top=0;
int idx;
idx=dstIndex;
while(path[idx]!=idx)
{
stack[top++]=idx;
idx=path[idx];
}
stack[top]=idx;
printf("Printing Path\n");
while(top>=0)
{
printf("%c ",nodes[stack[top]]);
if(top>0) printf(" --> ");
top--;
}
return 0;
}