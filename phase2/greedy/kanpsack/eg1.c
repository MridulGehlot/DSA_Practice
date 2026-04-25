#include<stdio.h>
int main()
{
int numberOfItems,capacity,profit;
capacity=4;
struct item
{
int weight;
int value;
};
struct item items[3]={
{2,100},
{2,10},
{3,120}
};
numberOfItems=3;
struct item g;
//sort
for(int e=0;e<numberOfItems-1;e++)
{
for(int f=1;f<numberOfItems;f++)
{
if((items[f].value/items[f].weight)>(items[e].value/items[e].weight))
{
g=items[e];
items[e]=items[f];
items[f]=g;
}
}
}
//now start picking
profit=0;
for(int i=0;i<numberOfItems && capacity>0;i++)
{
if(items[i].weight<=capacity)
{
profit+=items[i].value;
capacity-=items[i].weight;
}
else
{
profit+=(items[i].value/items[i].weight)*capacity;
capacity=0;
}
}
printf("Total Profit %d",profit);
return 0;
}