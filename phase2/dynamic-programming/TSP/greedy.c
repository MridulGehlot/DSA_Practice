//proof why greedy fails
#include<stdio.h>
#include<string.h>
#include<limits.h>

/*
int graph[4][4]={
{0,6,5,3},
{6,0,4,2},
{5,4,0,7},
{3,2,7,0}
};
*/
int ans;

//now change the graph make C->A as 50 
//update may weeights
int graph[4][4]={
{0,6,5,3},
{2,0,4,5},
{50,10,0,7},
{1,2,3,0}
};

void solve(char *arr,int len)
{
int idx,mini,mini_idx;
char ch='A';
int vis[len];
for(int i=0;i<len;i++) vis[i]=0;
vis[ch-'A']=1;
int cost=0;
while(1)
{
mini=INT_MAX;
mini_idx=-1;
idx=ch-'A';
for(int i=0;i<len;i++)
{
if(!vis[i])
{
if(graph[idx][arr[i]-'A']<mini)
{
mini=graph[idx][arr[i]-'A'];
mini_idx=i;
}
}
}
if(mini_idx==-1) break;
vis[mini_idx]=1;
cost+=graph[idx][mini_idx];
ch=arr[mini_idx];
}
cost+=graph[idx]['A'-'A'];
ans=cost;
}


/*
brute force code
*/
void _generate_permutations(char *arr,int start,int length)
{
int e,f,g,ep;
ep=length-1;
for(e=start;e<ep;e++)
{
for(f=e+1;f<=ep;f++)
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
_generate_permutations(arr,e+1,length);
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
}
//printf("%s\n",arr);
int cost=0;
cost+=graph['A'-'A'][arr[0]-'A'];
for(int i=1;i<length;i++)
{
cost+=graph[arr[i-1]-'A'][arr[i]-'A'];
}
cost+=graph[arr[length-1]-'A']['A'-'A'];
printf("A%sA -> %d\n",arr,cost);
if(cost<ans) ans=cost;
}
void generate_permutations(char *arr,int length)
{
_generate_permutations(arr,0,length);
}




int main()
{
ans=INT_MAX;
char arr[]="ABCD";
int len=strlen(arr);
solve(arr,len);
printf("Minimum Cost via Greedy Algorithm is = %d\n",ans);
//ans should be 16 but it gave 59
generate_permutations(arr+1,len-1);
printf("Minimum Cost via Brute Force is = %d\n",ans);

return 0;
}