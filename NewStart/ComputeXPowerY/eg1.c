#include<stdio.h>
int power(int x,int y)
{
if(y==1) return x;
return x*power(x,y-1);
}
int main()
{
int x,y;
printf("Enter x - ");
scanf("%d",&x);
printf("Enter y - ");
scanf("%d",&y);
int ans=power(x,y);
printf("x^y is = %d",ans);
}