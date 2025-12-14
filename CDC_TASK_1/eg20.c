#include<stdio.h>
int main()
{
int arr[10]={12,45,78,89,56,23,10,55,97,46};
int prev,maxi;
prev=maxi=arr[0];
int i=0;
while(i<10)
{
if(arr[i]>maxi)
{
prev=maxi;
maxi=arr[i];
}
else if(arr[i]<maxi && arr[i]>prev) prev=arr[i]; //case where 1st element (0th idx) is maximum
i++;
}
printf("Maximum Element : %d\n",maxi);
printf("Second Largest Element : %d\n",prev);
return 0;
}