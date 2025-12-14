#include<stdio.h>
int main()
{
int arr[10]={12,45,23,65,88,78,22,19,73,46};
int sum=0;
for(int i=0;i<10;i++) sum+=arr[i];
double avg=sum/10.0;
printf("avg = %lf\n",avg);
return 0;
}