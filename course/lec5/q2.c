/*
Find Missing Number in an array of N Elements 
Where All Elements are Distinct

n=5 (range 0-5) [0,1,2,3,4,5] n+1 elements

Approaches : 
1. Sort
2. Sum 
3. Bitwise XOR
5^5=0
0^5=5

*/
#include<stdio.h>
int main()
{
int arr[5]={0,1,4,5,3};
int missing=0;
for(int i=0;i<5;++i)
{
missing=missing^i;
missing^=arr[i];
}
missing^=5;

printf("Missing element is %d\n",missing);

return 0;
}