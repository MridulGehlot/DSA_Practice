#include<stdio.h>
#include<stdlib.h>

int maxProfit;
typedef struct
{
int price;
int weight;
}item;

void solve(char *array,int index,int bits_count,item *items,int *answer,int capacity)
{
if(index==bits_count)
{
int profit,weight;
weight=0;
profit=0;
for(int i=0;i<bits_count;i++) 
{
if(array[i]=='1') 
{
weight+=items[i].weight;
profit+=items[i].price;
}
}
if(weight<=capacity && profit>maxProfit)
{
maxProfit=profit;
for(int i=0;i<bits_count;i++) 
{
if(array[i]=='1') answer[i]=1;
else answer[i]=0;
}
}
return;
}
array[index]='0';
solve(array,index+1,bits_count,items,answer,capacity);
array[index]='1';
solve(array,index+1,bits_count,items,answer,capacity);
}

void allCombinations(int numberOfItems,item *collection,int *answer,int capacity)
{
char *array=(char *)malloc(sizeof(char)*numberOfItems);
solve(array,0,numberOfItems,collection,answer,capacity);
free(array);
}

int main()
{
int numberOfItems;
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
int capacity=9;
//generate all possible combinations
allCombinations(numberOfItems,items,finalAnswer,capacity);
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