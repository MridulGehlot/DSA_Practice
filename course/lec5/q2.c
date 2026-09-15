/*
Find Missing NUmber in a list
n = 5 (0-5)
total = n+1 (0,1,2,4,3,5)

Approaches ->
1. Sort & Compare Index
2. Sum 
n range = (0-n)
0 1 2   n*(n+1)/2;

3. XOR
both same -> 0
else -> 1

5^5 = 0
0^5 = 5
1^2 = 3
*/
#include<stdio.h>
int main()
{
int arr[5]={1,2,3,4,5};

/*
int sum=0;
for(int i=0;i<5;++i) sum+=arr[i];
int totalSum = 5*(5+1)/2;
printf("Missing Element is %d\n",totalSum-sum);
*/

int val=0;
for(int i=0;i<5;++i)
{
val^=i;
val^=arr[i];
}
val^=5;

printf("Missing Element is %d\n",val);

return 0;
}