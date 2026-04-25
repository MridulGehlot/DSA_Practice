#include<stdio.h>
#include<stdlib.h>

void Sort(int *arr,int size)
{
int y,ri,ci,lci,rci,si,g;
//make max heap
y=1;
while(y<size)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ri]<arr[ci])
{
g=arr[ci];
arr[ci]=arr[ri];
arr[ri]=g;
}
else break;
ci=ri;
}
y++;
}
//now remove and sort
y=size;
while(y>0)
{
y--;
g=arr[y];
arr[y]=arr[0];
arr[0]=g;
//now we have to adjust heap
ri=0;
while(ri<y)
{
lci=(ri*2)+1;
rci=lci+1;
if(lci>=y) break;
if(rci>=y) si=lci;
else 
{
if(arr[lci]>arr[rci]) si=lci;
else si=rci;
}
if(arr[ri]<arr[si])
{
g=arr[ri];
arr[ri]=arr[si];
arr[si]=g;
ri=si;
}
else break;
}
}
}

void print(int *arr,int sz)
{
for(int i=0;i<sz;i++) printf("%d ",arr[i]);
}
int main()
{
int req;
int *arr;
printf("Enter Requirement - ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement");
return 0;
}
arr=(int *)malloc(sizeof(int)*req);
if(arr==NULL)
{
printf("Unable To Allocate Memory");
return 0;
}
for(int i=0;i<req;i++)
{
printf("Enter A Number - ");
scanf("%d",&arr[i]);
}
Sort(arr,req);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}