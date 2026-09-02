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
int e,f,m,g;
m=req-2;
while(m>=0)
{
e=0;
f=e+1;
while(e<=m)
{
if(collection[f]<collection[e])
{
g=collection[f];
collection[f]=collection[e];
collection[e]=g;
}
++e;
++f;
}
--m;
}
//ends here


for(int i=0;i<req;++i)
{
printf("%d ",collection[i]);
}

free(collection);

return 0;
}