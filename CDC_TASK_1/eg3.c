#include<stdio.h>
int main()
{
int x,y,z;
printf("Enter 3 Numbers : ");
scanf("%d",&x);
scanf("%d",&y);
scanf("%d",&z);
if(x>y && x>z) printf("Largest = %d",x);
else if(y>x && y>z) printf("Largest = %d",y);
else printf("Largest = %d",z);
return 0;
}