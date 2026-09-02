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
int y,num,z;
y=1;
while(y<req)
{
num=collection[y];
z=y-1;
while(z>=0 && collection[z]>num)
{
collection[z+1]=collection[z];
z--;
}
collection[z+1]=num;
++y;
}
//ends here


for(int i=0;i<req;++i)
{
printf("%d ",collection[i]);
}

free(collection);

return 0;
}