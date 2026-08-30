#include<stdio.h>
//Linear Search
int main()
{
int arr[6]={12,23,45,56,78,89};
int idx,sz,foundAt;
int key;
sz=6;
printf("Enter Number to find : ");
scanf("%d",&key);
foundAt=-1;
for(idx=0;idx<sz;++idx) 
{
if(arr[idx]==key) 
{
foundAt=idx;
break;
}
}
if(foundAt!=-1) printf("Element found at %d index\n",foundAt);
else printf("Element Not Found\n");
return 0;
}