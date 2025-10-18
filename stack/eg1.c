#include<stdio.h>
#include<stdlib.h>
struct Node
{
int lb,ub;
Node *next;
};
struct Node *top;
int isEmpty()
{
return top==NULL;
}
void push(int lb,int ub)
{
struct Node *tmp=(struct Node *)malloc(sizeof(struct Node));
tmp->lb=lb;
tmp->ub=ub;
tmp->next=top;
top=tmp;
}
void pop(int *lb,int *ub)
{
struct Node *tmp=top;
*lb=tmp->lb;
*ub=tmp->ub;
top=top->next;
free(tmp);
}
int main()
{
top=NULL;
return 0;
}