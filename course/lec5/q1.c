// Find if any element is repeated in array 
//or find existance duplicate element (T/F)
#include<stdio.h>
int main()
{
int arr[5]={12,45,78,56,12};

int found=0;
for(int i=0;i<5-1;++i)
{
for(int j=i+1;j<5;++j)
{
if(arr[i]==arr[j])
{
found=1;
break;
}
}
if(found) break;
}

if(found) printf("Duplicate Elements Exsits\n");
else printf("All Elements in array are unique\n");

return 0;
}