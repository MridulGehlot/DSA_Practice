//Determine Duplicate Numbers return (True/False)
#include<stdio.h>
int main()
{
int arr[10]={12,45,78,56,89,23,50,60,40,50};
int duplicate=0;
for(int e=0;e<9;++e)
{
for(int f=e+1;f<10;++f)
{
if(arr[e]==arr[f])
{
duplicate=1;
break;
}
}
if(duplicate) break;
}
if(duplicate) printf("Duplicates Elements Exists");
else printf("All elements in array are unique\n");
return 0;
}