#include<stdio.h>
int main()
{
int n;
printf("Enter n -> ");
scanf("%d",&n);
int a,b,next;
a=0;
b=1;
for(int i=0;i<n;i++)
{
printf("%d ",a);
next=a+b;
a=b;
b=next;
}
return 0;
}