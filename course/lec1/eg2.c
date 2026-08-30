#include<stdio.h>
#include<math.h>
//Jump Search
int main()
{
int arr[10]={12 ,20 ,23 ,25 ,45 ,47 ,56 ,78 ,89 ,99};
int idx,sz,foundAt,jump,ep;
int key;
sz=10;
printf("Enter Number to find : ");
scanf("%d",&key);
foundAt=-1;

//searching logic
jump = sqrt(sz); //ex 10 -> 3... 
idx=0;
while(idx<sz)
{
if(arr[idx]>=key) break;
idx+=jump;
}
if(idx>=sz) idx=sz-1;
//reverse linear search
ep=idx-jump;
while(idx>=0 && idx>=ep)
{
if(arr[idx]==key)
{
foundAt=idx;
break;
}
--idx;
}

//ends here

if(foundAt!=-1) printf("Element found at %d index\n",foundAt);
else printf("Element Not Found\n");
return 0;
}