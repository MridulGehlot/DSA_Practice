#include<stdio.h>
int gcd(int a,int b)
{
if(b==0) return a;
return gcd(b,a%b);
}
int main()
{
int x,y,g,rem;
printf("Enter a number - ");
scanf("%d",&x);
printf("Enter another number - ");
scanf("%d",&y);
int ans=gcd(x,y);
printf("GCD is %d",ans);
return 0;
}