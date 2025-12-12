#include<stdio.h>
int main()
{
int x;
printf("Enter a Number : ");
scanf("%d",&x);
int ans=1;
for(int i=1;i<=x;i++) ans*=i;
printf("Factorial of %d = %d",x,ans);
return 0;
}