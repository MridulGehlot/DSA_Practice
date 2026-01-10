#include<stdio.h>
#include<math.h>
int main()
{
int maxSS=0;
int x[4]={65,66,67,68};
int tmp1[4];
int lenX,upperBoundX,tmp1i,num1,xEP,e,j;
int y[3]={65,90,68};
int tmp2[3];
int lenY,upperBoundY,tmp2i,num2,yEP;

lenX=4;
xEP=pow(2,lenX)-1;
upperBoundX=lenX-1;
lenY=3;
yEP=pow(2,lenY)-1;
upperBoundY=lenY-1;

num1=0;
while(num1<=xEP)
{
tmp1i=0;
for(e=0;e<=upperBoundX;e++)
{
j=num1>>e;
if(j&1)
{
tmp1[tmp1i++]=x[e];
}
}
//printf("%d\n",tmp1i);
//sub sequence is ready
num2=0;
while(num2<=yEP)
{
tmp2i=0;
for(e=0;e<=upperBoundY;e++)
{
j=num2>>e;
if(j&1)
{
tmp2[tmp2i++]=y[e];
}
}
//sub sequence is ready comare it with of tmp1
if(tmp2i==tmp1i)
{
for(e=0;e<tmp1i;e++)
{
if(tmp1[e]!=tmp2[e]) break;
}
if(e==tmp1i) //found common
{
maxSS=e;
for(e=0;e<tmp1i;e++) printf("%c ",tmp1[e]);
printf("\n");
}
}
num2++;
}
//ends here
num1++;
}
printf("Length of LCS %d\n",maxSS);
return 0;
}