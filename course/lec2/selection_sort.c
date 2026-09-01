#include<stdio.h>
#include<stdlib.h>
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
int si; // smallest index
int i,g;
for(i=0;i<req-1;++i)
{
si=i;
for(int j=i+1;j<req;++j)
{
if(collection[j]<collection[si]) si=j;
}
//swap
g=collection[si];
collection[si]=collection[i];
collection[i]=g;
}

//ends here


for(int i=0;i<req;++i)
{
printf("%d ",collection[i]);
}
return 0;
}