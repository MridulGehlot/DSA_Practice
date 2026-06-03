#include<stdio.h>
int main()
{
char vertices[]="ABCDEFGHIJK";
int graph[2][11][5]={
{
{1,2,3,-1,-1},
{4,5,-1,-1,-1},
{4,-1,-1,-1,-1},
{4,5,-1,-1,-1},
{7,8,9,-1,-1},
{6,7,9,-1,-1},
{10,-1,-1,-1,-1},
{10,-1,-1,-1,-1},
{10,-1,-1,-1,-1},
{10,-1,-1,-1,-1},
{-1,-1,-1,-1,-1}
}
,
{
{5,4,7,-1,-1},
{2,1,-1,-1,-1},
{3,-1,-1,-1,-1},
{1,6,-1,-1,-1},
{7,2,1,-1,-1},
{1,3,2,-1,-1},
{4,-1,-1,-1,-1},
{3,-1,-1,-1,-1},
{2,-1,-1,-1,-1},
{1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1}
}
};
char stages[][5]={
"A",
"BCD",
"EF",
"GHIJ",
"K"
};
int dp[2][11]={
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};
char s,t;
int number_of_stages,i,cost;
number_of_stages=5;
i=number_of_stages-2;
while(i>=0)
{
for(int j=0;stages[i][j]!='\0';j++) //current stage
{
s=stages[i][j];
for(int k=0;stages[i+1][k]!='\0';k++) //+1 (next) stage
{
t=stages[i+1][k];
for(int m=0;m<5 && graph[0][s-'A'][m]!=-1;m++)
{
if(graph[0][s-'A'][m]==(t-'A'))// there is a path
{
//printf("%c %c\n",s,t);
cost=graph[1][s-'A'][m];
if(dp[1][s-'A']==-1)
{
dp[0][s-'A']=cost+dp[0][t-'A'];
dp[1][s-'A']=t-'A';
}
else
{
if(cost+dp[0][t-'A']<dp[0][s-'A'])
{
dp[0][s-'A']=cost+dp[0][t-'A'];
dp[1][s-'A']=t-'A';
}
}
}
}//inner loop
} //t loop
} //s loop
i--;
}
printf("---------------------\n");
for(i=0;i<2;i++)
{
for(int j=0;j<11;j++)
{
printf("%d ",dp[i][j]);
}
printf("\n");
}
return 0;
}