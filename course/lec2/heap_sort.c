#include<stdio.h>
#include<stdlib.h>

void heap_sort(int *arr,int sz)
{
int y,ri,ci,lci,rci,i,g,maxi;
//max heap
i=0;
while(i<sz)
{
ci=i;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ci]>arr[ri])
{
g=arr[ci];
arr[ci]=arr[ri];
arr[ri]=g;
ci=ri;
}
else break;
}//inner
++i;
}//while outer

//sort
y=sz-1;
while(y>0)
{
g=arr[0];
arr[0]=arr[y];
arr[y]=g;
--y;
ri=0;
while(ri<=y)
{
lci=ri*2+1;
rci=lci+1;
if(lci>y) break;
if(rci>y) maxi=lci;
else
{
if(arr[lci]>arr[rci]) maxi=lci;
else maxi=rci;
}
if(arr[maxi]>arr[ri])
{
g=arr[maxi];
arr[maxi]=arr[ri];
arr[ri]=g;
ri=maxi;
}
else break;
}

}

}

int main()
{
int req;
int *collection;
printf("Enter How many Numbers : ");
scanf("%d",&req);

if(req<=0)
{
printf("Invalid Requirement");
return 0;
}

collection=(int *)malloc(sizeof(int)*req);
if(collection==NULL)
{
printf("Not Enough Memory\n");
return 1;
}

for(int i=0;i<req;++i)
{
scanf("%d",&collection[i]);
}


//sorting logic
heap_sort(collection,req);
//ends here


for(int i=0;i<req;++i)
{
printf("%d ",collection[i]);
}

free(collection);

return 0;
}