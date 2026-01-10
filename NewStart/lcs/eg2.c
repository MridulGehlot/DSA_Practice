#include<stdio.h>
#include<math.h>
int main()
{
int y[3]={65,90,68};
int tmp2[3];
int lenY,upperBoundY,tmp2i,num2,yEP,e,j;

lenY=3;
yEP=pow(2,lenY)-1;
upperBoundY=lenY-1;

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
//printf("%d\n",tmp2i);
//sub sequence is ready
for(e=0;e<tmp2i;e++) printf("%c ",tmp2[e]);
printf("\n");
num2++;
}

return 0;
}