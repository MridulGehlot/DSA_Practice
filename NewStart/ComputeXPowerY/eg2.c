#include<stdio.h>
int count=0;
int pp(int x,int y)
{
count++;
if(y==1) return x;
return x*pp(x,y-1);
}
int power(int a,int b)
{
if(b==1) return a;
return pp(a,b);
}
int main()
{
int x,y;
printf("Enter x - ");
scanf("%d",&x);
printf("Enter y - ");
scanf("%d",&y);
int ans=power(x,y);
printf("Count - %d\n",count);
printf("x^y is = %d",ans);
}