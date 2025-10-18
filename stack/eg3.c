#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct __stack_node
{
void *data;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *top;
int size;
int elementSize;
}Stack;
void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}
int isEmpty(Stack *stack)
{
return stack->size==0;
}
void push(Stack *stack,const void *data)
{
StackNode *tmp=(StackNode *)malloc(sizeof(StackNode));
tmp->data=(void *)malloc(stack->elementSize);
memcpy(tmp->data,data,stack->elementSize);
tmp->next=stack->top;
stack->top=tmp;
stack->size++;
}
void pop(Stack *stack,void *data)
{
StackNode *tmp=stack->top;
memcpy(data,tmp->data,stack->elementSize);
stack->top=stack->top->next;
stack->size--;
free(tmp->data);
free(tmp);
}
int main()
{
Stack stk;
initStack(&stk,sizeof(char));
char xx;
xx='L';
push(&stk,(const void *)&xx);
xx='U';
push(&stk,(const void *)&xx);
xx='D';
push(&stk,(const void *)&xx);
xx='I';
push(&stk,(const void *)&xx);
xx='R';
push(&stk,(const void *)&xx);
xx='M';
push(&stk,(const void *)&xx);
while(!isEmpty(&stk))
{
pop(&stk,&xx);
printf("%c",xx);
}
return 0;
}