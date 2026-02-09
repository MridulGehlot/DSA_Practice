#include<stdio.h>
int getNumberOfWaysToClimbStairs(int stairs)
{
int e,f,g,k;
if(stairs<=2) return stairs;
e=1;
f=2;
k=3;
while(k<=stairs)
{
g=e+f;
e=f;
f=g;
k++;
}
return g;
}
int main()
{
for(int i=0;i<=10;i++)
printf("Number Of Ways To Climb %d stairs is %d\n",i,getNumberOfWaysToClimbStairs(i));
return 0;
}