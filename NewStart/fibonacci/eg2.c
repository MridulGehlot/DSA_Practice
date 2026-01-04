#include<stdio.h>
int arr[200]={0};
int fibo(int n)
{
if(arr[n]==0)
{
if(n<=1) return 0;
else return arr[n]=fibo(n-1)+fibo(n-2);
}
else return arr[n];
}
int main()
{
int n;
arr[0]=0;
arr[1]=0;
arr[2]=1;
printf("Enter n -> ");
scanf("%d",&n);
int ans=fibo(n);
printf("nth fibonacci number is %d\n",ans);
return 0;
}