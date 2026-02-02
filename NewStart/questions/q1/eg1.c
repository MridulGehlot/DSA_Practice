#include<stdio.h>
int check(int *arr,int size)
{
int e,f;
for(e=1;e<size;e++)
{
for(f=0;f<e;f++)
{
if(arr[e]==arr[f]) return 1;
}
}
return 0;
}
int main()
{
int arr[5]={1,2,3,4,5};
int arr2[5]={1,2,3,1,5};
printf("Contains Duplicates : %s\n",(check(arr,5)==1?"True":"False"));
printf("Contains Duplicates : %s\n",(check(arr2,5)==1?"True":"False"));
return 0;
}