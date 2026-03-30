#include<stdio.h>
#include<stdlib.h>
#include<mg_stack.h>
#include<mg_queue.h>

typedef struct __element
{
int number;
char oper;
}Element;

int isOperator(char ch)
{
return ch=='+' || ch=='-' || ch=='*' || ch=='/';
}

int getPrecedenceLevel(char op)
{
if(op=='*' || op=='/') return 2;
if(op=='-' || op=='+') return 1;
}

void appendOperatorToPostfix(Queue *queue,char op)
{
Element *e=(Element *)malloc(sizeof(Element));
e->oper=op;
e->number=0;
int succ;
addToQueue(queue,e,&succ);
}
void appendNumberToPostfix(Queue *queue,int num)
{
Element *e=(Element *)malloc(sizeof(Element));
e->oper=' ';
e->number=num;
int succ;
addToQueue(queue,e,&succ);
}

int processExpression(int leftOperand,char oper,int rightOperand)
{
if(oper=='+') return leftOperand+rightOperand;
if(oper=='*') return leftOperand*rightOperand;
if(oper=='-') return leftOperand-rightOperand;
if(oper=='/') return leftOperand/rightOperand;
}

int main()
{
char infix[101];
Element *e;
int i,succ,number,result,leftOperand,rightOperand;
char *m;
char elem;
printf("Enter Infix Expression : \n");
scanf("%s",infix);
Stack *stack=createStack(&succ);
Queue *queue=createQueue(&succ);
i=0;
while(infix[i]!='\0')
{
elem=infix[i];
i++;
if(elem=='(')
{
m=(char *)malloc(sizeof(char));
*m='(';
pushOnStack(stack,(void *)m,&succ);
continue;
}
if(elem==')')
{
while(1)
{
m=(char *)popFromStack(stack,&succ);
if(*m=='(') break;
appendOperatorToPostfix(queue,*m);
free(m);
}
continue;
}
if(isOperator(elem))
{
while(1)
{
if(isStackEmpty(stack)) break;
m=(char *)elementAtTopOfStack(stack,&succ);
if(*m=='(') break;
if(getPrecedenceLevel(*m)<getPrecedenceLevel(elem)) break;
m=(char *)popFromStack(stack,&succ);
appendOperatorToPostfix(queue,*m);
free(m);
}
m=(char *)malloc(sizeof(char));
*m=elem;
pushOnStack(stack,(void *)m,&succ);
continue;
}
//operand
number=elem-48;
while(1)
{
elem=infix[i];
if(elem>=48 && elem<=57) number=(number*10)+(elem-48);
else 
{
appendNumberToPostfix(queue,number);
break;
}
i++;
}
}

//pop remaining and add to postfix
while(!isStackEmpty(stack))
{
m=(char *)popFromStack(stack,&succ);
appendOperatorToPostfix(queue,*m);
free(m);
}

//processing the result
char oper;
while(!isQueueEmpty(queue))
{
e=(Element *)removeFromQueue(queue,&succ);
if(e->oper==' ') //the structure represents a number
{
pushOnStack(stack,(void *)e,&succ);
}
else
{
oper=e->oper;
free(e);
e=(Element *)popFromStack(stack,&succ);
rightOperand=e->number;
free(e);
e=(Element *)popFromStack(stack,&succ);
leftOperand=e->number;
free(e);
result=processExpression(leftOperand,oper,rightOperand);
e=(Element *)malloc(sizeof(Element));
e->oper=' ';
e->number=result;
pushOnStack(stack,(void *)e,&succ);
}
}
e=(Element *)popFromStack(stack,&succ);
result=e->number;
free(e);
printf("Asnwer %d \n",result);
destroyStack(stack);
destroyQueue(queue);
return 0;
}