#include<stdio.h>
#include<math.h>
int main()
{
int x[4]={65,66,67,68};
int tmp1[4];
int lenX,upperBoundX,tmp1i,num1,xEP,e,j;

lenX=4;
xEP=pow(2,lenX)-1;
upperBoundX=lenX-1;

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
for(e=0;e<tmp1i;e++) printf("%c ",tmp1[e]);
printf("\n");
num1++;
}

return 0;
}