#include<stdio.h>
int x[6]={65,66,67,68,80,90};
int y[4]={66,90,68,90};
int lenX=6;
int lenY=4;
int copies=0;
int store[6][4];
int getLenOfLCS(int e,int f)
{
copies++;
if(e==lenX || f==lenY) return 0;
if(store[e][f]!=-1) return store[e][f];
if(x[e]==y[f]) return store[e][f]=1+getLenOfLCS(e+1,f+1);
int left=getLenOfLCS(e+1,f);
int right=getLenOfLCS(e,f+1);
return store[e][f]=left>right?left:right;
}
int getLengthOfLCS()
{
for(int i=0;i<=5;i++) for(int j=0;j<=3;j++) store[i][j]=-1;
return getLenOfLCS(0,0);
}
int main()
{
printf("Length of LCS is %d\n",getLengthOfLCS());
printf("Number of copies opened %d\n",copies);
return 0;
}