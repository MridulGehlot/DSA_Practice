#include<stdio.h>
//Binary Search
int main()
{
int arr[6]={12,23,45,56,78,89};
int lb,ub,mid,sz,foundAt;
int key;
sz=6;
printf("Enter Number to find : ");
scanf("%d",&key);


foundAt=-1;
lb=0;
ub=sz-1;
while(lb<=ub)
{
mid=(lb+ub)/2;
if(arr[mid]==key)
{
foundAt=mid;
break;
}
if(arr[mid]>key) //left part
{
ub=mid-1;
}
else //right part
{
lb=mid+1;
}
}


if(foundAt!=-1) printf("Element found at %d index\n",foundAt);
else printf("Element Not Found\n");
return 0;
}