#include<stdio.h>
int count=0;
//assuming max y is 32
int arr[32]={0};
int pp(int x,int y)
{
count++;
if(y==1) return x;
if(arr[y]!=0) return arr[y];
arr[y]=(y%2==0)?pp(x,y/2)*pp(x,y/2):x*pp(x,y/2)*pp(x,y/2);
return arr[y];
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