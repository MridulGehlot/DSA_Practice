#include<stdio.h>
int main()
{
int n,a,b,c;
printf("Enter a number - ");
scanf("%d",&n);
if(n==1) printf("0 \n");
else if(n==2) printf("0 1\n");
else
{
printf("0 1 ");
a=0;
b=1;
for(int i=2;i<n;i++)
{
c=a+b;
printf("%d ",c);
a=b;
b=c;
}
}
return 0;
}