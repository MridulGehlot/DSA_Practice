#include<stdio.h>
#include<stdlib.h>
#include<mg_stack.h>
int isOperator(char c)
{
return c=='+' || c=='-' || c=='*' || c=='/';
}
int isOperand(char c)
{
return !isOperator(c);
}
int getPrecedenceLevel(char op)
{
if(op=='*' || op=='/') return 2;
if(op=='+' || op=='-') return 1;
return 0;
}
void appendToPrefix(char c,char *pf,int *idx)
{
pf[*idx]=c;
(*idx)--;
}
int main()
{
Stack *stack;
int succ;
char infix[101],prefix[101];
int endIndex;
prefix[0]='\0';
endIndex=0;
char elem;
char *m;
int i;
printf("Enter infix Expression :\n");
scanf("%s",infix);
stack=createStack(&succ);
i=0;
while(infix[i]!='\0') i++;
prefix[i]='\0';
i--;
endIndex=i;
while(i>=0)
{
elem=infix[i];
if(elem==')')
{
m=(char *)malloc(sizeof(char));
*m=elem;
pushOnStack(stack,(void *)m,&succ);
i--;
continue;
}
if(elem=='(')
{
while(1) //popping loop starts
{
m=(char *)popFromStack(stack,&succ);
if(*m==')') 
{
free(m);
break;
}
appendToPrefix(*m,prefix,&endIndex);
free(m);
} //popping loop ends here
i--;
continue;
}
if(isOperand(elem))
{
appendToPrefix(elem,prefix,&endIndex);
i--;
continue;
}
if(isOperator(elem))
{
if(isStackEmpty(stack))
{
m=(char *)malloc(sizeof(char));
*m=elem;
pushOnStack(stack,(void *)m,&succ);
i--;
continue;
}
m=(char *)elementAtTopOfStack(stack,&succ);
if(*m==')')
{
m=(char *)malloc(sizeof(char));
*m=elem;
pushOnStack(stack,(void *)m,&succ);
i--;
continue;
}
if(getPrecedenceLevel(*m)>getPrecedenceLevel(elem))
{
m=(char *)malloc(sizeof(char));
*m=elem;
pushOnStack(stack,(void *)m,&succ);
i--;
continue;
}
while(1) //popping loop start
{
if(isStackEmpty(stack)) break;
m=(char *)elementAtTopOfStack(stack,&succ);
if(*m==')') break;
if(getPrecedenceLevel(*m)>getPrecedenceLevel(elem)) break;
m=(char *)popFromStack(stack,&succ);
appendToPrefix(*m,prefix,&endIndex);
free(m);
}//popping loop ends here
m=(char *)malloc(sizeof(char));
*m=elem;
pushOnStack(stack,(void *)m,&succ);
i--;
} //if is operator
} //infix main while loop ends


while(!isStackEmpty(stack))
{
m=(char *)popFromStack(stack,&succ);
appendToPrefix(*m,prefix,&endIndex);
free(m);
}

//destroyStack(stack);

printf("Pre Fix Expression\n%s",prefix);
return 0;
}