#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
int lb,ub;
struct Node *next;
};
struct Node *top;
void push(int lb,int ub)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
t->lb=lb;
t->ub=ub;
t->next=top;
top=t;
}
void pop(int *lb,int *ub)
{
struct Node *t;
t=top;
*lb=top->lb;
*ub=top->ub;
top=top->next;
free(t);
}
int isEmpty()
{
return top==NULL;
}
int findPartitionPoint(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
void *g;
int e,f;
g=malloc(es);
e=lb;
f=ub;
while(e<f)
{
while(e<ub && p2f(x+(e*es),x+(lb*es))<=0)e++;
while(p2f(x+(f*es),x+(lb*es))>0)f--;
if(e<f) //swap e,f
{
memcpy(g,(const void *)x+(e*es),es);
memcpy(x+(e*es),(const void *)x+(f*es),es);
memcpy(x+(f*es),(const void *)g,es);
}
else //swap f,lb
{
memcpy(g,(const void *)x+(lb*es),es);
memcpy(x+(lb*es),(const void *)x+(f*es),es);
memcpy(x+(f*es),(const void *)g,es);
}
}
free(g);
return f;
}
void _quickSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
int pp,lb,ub;
//push to stack
push(lowerBound,upperBound);
while(!isEmpty())
{
//pop from stack
pop(&lb,&ub);
pp=findPartitionPoint(x,lb,ub,es,p2f);
if(pp+1<ub) push(pp+1,ub);
if(lb<pp-1) push(lb,pp-1);
}
}
void quickSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*))
{
_quickSort(arr,0,size-1,sizeOfElement,ptr2func);
}