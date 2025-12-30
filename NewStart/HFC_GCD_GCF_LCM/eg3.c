#include<stdio.h>
int gcd(int a,int b)
{
if(b==0) return a;
return gcd(b,a%b);
}
int lcm(int a,int b)
{
int prod=a*b;
int x=gcd(a,b);
return prod/x;
}
int main()
{
int x,y,g,rem;
printf("Enter a number - ");
scanf("%d",&x);
printf("Enter another number - ");
scanf("%d",&y);
int ans=lcm(x,y);
printf("LCM is %d",ans);
return 0;
}