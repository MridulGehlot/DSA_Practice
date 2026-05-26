#include<stdio.h>
#include<string.h>
#include<limits.h>

int graph[4][4]={
{0,6,5,3},
{6,0,4,2},
{5,4,0,7},
{3,2,7,0}
};
int ans;

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
//char arr[]="ABCD";
char arr[]="BCD"; //remove A from SET as we are starting with A
int len=strlen(arr);
generate_permutations(arr,len);
printf("Minimum Cost is = %d\n",ans);
return 0;
}