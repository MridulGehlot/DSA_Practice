#include<stdio.h>
#include<mg_linkedlist.h>
#include<stdlib.h>
int main()
{
SinglyLinkedList *list;
int succ;
int *x;
list=createSinglyLinkedList(&succ);
for(int i=101;i<=110;i++)
{
x=(int *)malloc(sizeof(int));
*x=i;
addToList(list,(void *)x,&succ);
}
while(!isListEmpty(list))
{
printf("size = %d\n",list->size);
x=(int *)removeFromList(list,&succ);
printf("%d ",*x);
free(x);
}
destroyList(list,&succ);
return 0;
}