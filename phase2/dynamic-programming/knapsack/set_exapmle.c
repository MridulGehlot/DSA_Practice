#include<stdio.h>
#include<stdlib.h>

typedef struct
{
int price;
int weight;
}item;
typedef struct
{
int size;
item *list;
}MasterSet;

int main()
{
int numberOfItems,profit,weight,count;
int maxProfit,x,size,found;
item *set,*tmp,element;
MasterSet *masterSet;
item items[5]={
{10,3},
{11,2},
{12,5},
{60,1},
{40,4}
};
numberOfItems=5;
maxProfit=0;
int capacity=9;
masterSet=(MasterSet *)malloc(sizeof(MasterSet)*(numberOfItems+1));
//prepare set
size=1;
set=(item *)malloc(sizeof(item)*size);
set[0].price=0;
set[0].weight=0;
for(int i=0;i<numberOfItems;i++)
{
tmp=(item *)malloc(sizeof(item)*(size*2));
for(int j=0;j<size;j++) tmp[j]=set[j];
for(int j=size;j<2*size;j++)
{
tmp[j].weight=tmp[j-size].weight+items[i].weight;
tmp[j].price=tmp[j-size].price+items[i].price;
}
//now adjust tmp
count=0;
if(i==0) free(set);
size*=2;
set=(item *)malloc(sizeof(item)*size);
set[0]=tmp[0];
count++;
for(int j=1;j<size;j++)
{
if(tmp[j].weight>capacity) continue;
if(tmp[j].weight<set[count-1].weight && tmp[j].price>set[count-1].price) //weight is decreasing & profit increasing override
{
set[count-1].weight=tmp[j].weight;
set[count-1].price=tmp[j].price;
}
if(tmp[j].weight<set[count-1].weight && tmp[j].price>set[count-1].price) //weight is increasing & profit decreasing ignore
{
continue;
}
else set[count++]=tmp[j];
}
size=count;
free(tmp);
masterSet[i].size=size;
masterSet[i].list=set;
}

maxProfit=set[size-1].price;

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

//All Data is in Master Set Backtrack to check which items were picked

element=masterSet[numberOfItems-1].list[masterSet[numberOfItems-1].size-1];
printf("Picked Items are : \n");
for(int i=numberOfItems-1;i>0;i--)
{
//find the element in the above set
found=0;
for(int j=0;j<masterSet[i-1].size;j++)
{
if(masterSet[i-1].list[j].weight==element.weight && masterSet[i-1].list[j].price==element.price)
{
found=1;
break;
}
}//searching loop
if(!found) //pick this element
{
printf("Price : %d , Weight : %d \n",items[i].price,items[i].weight);
element.price-=items[i].price;
element.weight-=items[i].weight;
}
} //main back track loop
if(element.price!=0 || element.weight!=0) printf("Price : %d , Weight : %d \n",items[0].price,items[0].weight);

return 0;
}