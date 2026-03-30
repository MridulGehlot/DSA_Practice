#include<mg_stack.h>
#include<mg_linkedlist.h>
#include<mg_error.h>
#include<stdlib.h>

Stack * createStack(int *succ)
{
*succ=FAILURE;
Stack *stack=(Stack *)malloc(sizeof(Stack));
if(stack==NULL)
{
*succ=MEM_ALLOC_ERROR;
return NULL;
}
int x;
stack->list=createSinglyLinkedList(&x);
if(x==FAILURE || x==MEM_ALLOC_ERROR || stack->list==NULL)
{
return NULL;
}
return stack;
}

void pushOnStack(Stack *stack,void *data,int *succ)
{
insertAtTopOfList(stack->list,data,succ);
}
void * popFromStack(Stack *stack,int *succ)
{
return removeFromList(stack->list,succ);
}
void * elementAtTopOfStack(Stack *stack,int *succ)
{
return stack->list->start->ptr;
}

int getSizeOfStack(Stack *stack)
{
if(stack==NULL) return 0;
return getSizeOfList(stack->list);
}
int isStackEmpty(Stack *stack)
{
if(stack==NULL) return 1;
return isListEmpty(stack->list);
}

void destroyStack(Stack *stack)
{
if(stack==NULL || stack->list==NULL) return;
destroyList(stack->list);
free(stack);
}