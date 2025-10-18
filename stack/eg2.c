#include<stdio.h>
#include<stdlib.h>
typedef struct __stack_node
{
int data;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *top;
int size;
}Stack;
int isEmpty(Stack *stack)
{
return stack->size==0;
}
void push(Stack *stack,int data)
{
StackNode *tmp=(StackNode *)malloc(sizeof(StackNode));
tmp->data=data;
tmp->next=stack->top;
stack->top=tmp;
stack->size++;
}
int pop(Stack *stack)
{
if(stack->size==0)
{
printf("Stack is Empty...\n");
return -1;
}
int data;
StackNode *tmp=stack->top;
data=tmp->data;
stack->top=stack->top->next;
stack->size--;
free(tmp);
return data;
}
int main()
{
Stack stk;
stk.top=NULL;
stk.size=0;
push(&stk,10);
push(&stk,20);
push(&stk,30);
push(&stk,40);
push(&stk,50);
while(!isEmpty(&stk))
{
printf("Popped - %d\n",pop(&stk));
}
return 0;
}