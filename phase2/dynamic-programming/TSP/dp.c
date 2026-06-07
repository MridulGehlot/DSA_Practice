#include<stdio.h>
int graph[6][6]={
{0,6,5,3,3,1},
{2,0,4,5,5,5},
{50,10,0,7,6,7},
{1,2,3,0,9,9},
{2,2,4,6,1,5},
{1,2,4,0,8,7}
};
int store[6][6]={
{-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1}
};

int copies;

int solve(char curr,char set[],int idx,int len)
{
copies++;
if(idx>=len) return graph[curr-'A']['A'-'A'];
char ch;
int val,x;
x=-1;
for(int i=idx;i<len;i++)
{
ch=set[i];
set[i]=set[idx];
set[idx]=ch;
val=graph[curr-'A'][set[idx]-'A']+solve(set[idx],set,idx+1,len);
//printf("Cost from %c to %c -> %d\n",curr,set[i],val);
if(x==-1 || val<x) x=val;
ch=set[i];
set[i]=set[idx];
set[idx]=ch;
}
return x;
}


int solve_dp(char prev,char curr,char set[],int idx,int len)
{
if(idx>=len) return graph[curr-'A']['A'-'A'];
if(prev!='\0' && store[prev-'A'][curr-'A']!=-1) return store[prev-'A'][curr-'A'];
copies++;
char ch;
int val,x;
x=-1;
for(int i=idx;i<len;i++)
{
ch=set[i];
set[i]=set[idx];
set[idx]=ch;
val=graph[curr-'A'][set[idx]-'A']+solve_dp(curr,set[idx],set,idx+1,len);
//printf("Cost from %c to %c -> %d\n",curr,set[i],val);
if(x==-1 || val<x) x=val;
ch=set[i];
set[i]=set[idx];
set[idx]=ch;
}
if(prev=='\0') return x;
return store[prev-'A'][curr-'A']=x;
}

int main()
{
char set[]="ABCDEF";
copies=0;
int val=solve('A',set,1,6);
printf("Trying Recurrsion = %d Number of Copies\n",copies);
printf("Min Value For TSP = %d",val);
copies=0;
val=solve_dp('\0','A',set,1,6);
printf("\nTrying dp = %d Number of Copies\n",copies);
printf("Min Value For TSP = %d",val);
return 0;
}