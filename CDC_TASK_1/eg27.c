#include<stdio.h>
int main()
{
int arr[10]={12,45,23,65,88,78,22,19,73,46};
int oddCount,evenCount;
oddCount=evenCount=0;
for(int i=0;i<10;i++) 
{
if(arr[i]%2) oddCount++;
else evenCount++;
}
printf("Odd Count = %d\n",oddCount);
printf("Even Count = %d\n",evenCount);
return 0;
}