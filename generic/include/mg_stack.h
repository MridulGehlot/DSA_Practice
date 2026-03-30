#ifndef __mg_stack
#define __mg_stack
#include "mg_linkedlist.h"
typedef struct __stack
{
SinglyLinkedList *list;
}Stack;

Stack * createStack(int *succ);
void pushOnStack(Stack *stack,void *data,int *succ);
void * popFromStack(Stack *stack,int *succ);
void * elementAtTopOfStack(Stack *stack,int *succ);
int getSizeOfStack(Stack *stack);
int isStackEmpty(Stack *stack);

#endif