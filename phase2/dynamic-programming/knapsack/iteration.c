#include<stdio.h>
#include<math.h>

typedef struct
{
int price;
int weight;
}item;

int main()
{
int numberOfItems,profit,weight,end;
int maxProfit,x;
maxProfit=0;
item items[5]={
{10,3},
{11,2},
{12,5},
{60,1},
{40,4}
};
numberOfItems=5;
int finalAnswer[numberOfItems];
int localAnswer[numberOfItems];
int capacity=9;
//generate all possible combinations
end=pow(2,numberOfItems);
for(int i=0;i<end;i++)
{
x=i;
for(int j=numberOfItems-1;j>=0;j--)
{
if(x%2) localAnswer[j]=1;
else localAnswer[j]=0;
x/=2;
}
profit=0;
weight=0;
for(int j=0;j<numberOfItems;j++)
{
if(localAnswer[j])
{
profit+=items[j].price;
weight+=items[j].weight;
}
}
if(weight<=capacity && profit>maxProfit)
{
maxProfit=profit;
for(int j=0;j<numberOfItems;j++) finalAnswer[j]=localAnswer[j];
}
}

printf("Maximum Profit = %d\n",maxProfit);
printf("------ITEMS------\n");
printf("Pirce : ");
for(int i=0;i<numberOfItems;i++)
{
printf("%d ",items[i].price);
}
printf("\n");
printf("Weights : ");
for(int i=0;i<numberOfItems;i++)
{
printf("%d ",items[i].weight);
}
printf("\n");
printf("Picked : ");
for(int i=0;i<numberOfItems;i++)
{
printf("%d ",finalAnswer[i]);
}

return 0;
}