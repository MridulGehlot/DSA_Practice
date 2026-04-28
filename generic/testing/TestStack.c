#include<stdio.h>
#include<mg_stack.h>
#include<stdlib.h>
int main()
{
Stack *stack;
int succ;
int *x;
stack=createStack(&succ);
for(int i=101;i<=110;i++)
{
x=(int *)malloc(sizeof(int));
*x=i;
pushOnStack(stack,(void *)x,&succ);
}
while(!isStackEmpty(stack))
{
x=(int *)popFromStack(stack,&succ);
printf("%d ",*x);
free(x);
}
return 0;
}