#include<mg_sort.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUCCESSFUL 1
#define FAILED 0
#define NO_ERROR 0
#define NULL_VALUE 1
#define ELEM_SIZE_ZERO 2
#define MEM_ALLOC_ERROR 3
#define STACK_EMPTY 4

typedef struct __stack_node
{
void *ptr;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *top;
int size;
int elementSize;
}Stack;
void initStack(Stack *stack,int size,int *success,int *error)
{
if(success) *success=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL)
{
if(error) *error=NULL_VALUE;
return;
}
if(size<=0)
{
if(error) *error=ELEM_SIZE_ZERO;
return;
}
stack->top=NULL;
stack->size=0;
stack->elementSize=size;
if(success) *success=SUCCESSFUL;
}
int isEmpty(Stack *stack,int *success,int *error)
{
if(success) *success=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL) 
{
if(error) *error=NULL_VALUE;
return 1;
}
if(success) *success=SUCCESSFUL;
if(stack->top==NULL) return 1;
if(stack->size==0) return 1;
return 0;
}
void push(Stack *stack,void *ptr,int *success,int *error)
{
if(success) *success=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL) 
{
if(error) *error=NULL_VALUE;
return;
}
StackNode *node;
node=(StackNode *)malloc(sizeof(StackNode));
if(node==NULL) 
{
if(error) *error=MEM_ALLOC_ERROR;
return;
}
if(ptr!=NULL)
{
node->ptr=malloc(stack->elementSize);
if(node->ptr==NULL)
{
free(node);
if(error) *error=MEM_ALLOC_ERROR;
return;
}
memcpy(node->ptr,(const void *)ptr,stack->elementSize);
}
else
{
node->ptr=ptr;
}
node->next=stack->top;
stack->top=node;
stack->size++;
if(success) *success=SUCCESSFUL;
}
void pop(Stack *stack,void *ptr,int *success,int *error)
{
if(success) *success=FAILED;
if(error) *error=NO_ERROR;
int j=0;
if(stack==NULL || ptr==NULL) 
{
if(error) *error=NULL_VALUE;
return;
}
if(stack->top==NULL) 
{
if(error) *error=STACK_EMPTY;
return;
}
if(stack->top->ptr==NULL)
{
for(j=0;j<stack->elementSize;j++) *(char *)(ptr+j)=(char)0;
}
else
{
memcpy(ptr,stack->top->ptr,stack->elementSize);
}
StackNode *node;
node=stack->top;
stack->top=stack->top->next;
stack->size--;
if(node->ptr!=NULL)free(node->ptr);
free(node);
if(success) *success=SUCCESSFUL;
}
void clearStack(Stack *stack,int *success,int *error)
{
if(success) *success=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL || stack->top==NULL)
{
if(error) *error=NULL_VALUE;
return;
}
StackNode *t;
while(stack->top!=NULL)
{
t=stack->top;
stack->top=stack->top->next;
if(t->ptr!=NULL) free(t->ptr);
free(t);
}
stack->size=0;
if(success) *success=SUCCESSFUL;
}
void merge(void *x,int lb1,int ub1,int lb2,int ub2,int es,int (*p2f)(void *,void *),int *success,int *error)
{
if(success) *success=FAILED;
if(error) *error=NO_ERROR;
int lb3,ub3,i1,i2,i3;
void *tmp;
int size;
size=(ub1-lb1)+(ub2-lb2)+2;
tmp=malloc(size*es);
if(tmp==NULL)
{
if(error) *error=MEM_ALLOC_ERROR;
return;
}
lb3=lb1;
ub3=ub2;
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
//if(x[i1]<x[i2])
if(p2f(x+(i1*es),x+(i2*es))<0)
{
//tmp[i3]=x[i1];
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
}
else
{
//tmp[i3]=x[i2];
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
}
i3++;
}
while(i1<=ub1)
{
//tmp[i3]=x[i1];
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
i3++;
}
while(i2<=ub2)
{
//tmp[i3]=x[i2];
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
i3++;
}
/*
i3=0;
while(i3<=ub3)
{
x[i3]=tmp[i3];
i3++;
}
*/
i3=0;
i1=lb1;
while(i1<=ub1)
{
//x[i1]=tmp[i3];
memcpy(x+(i1*es),(const void *)(tmp+(i3*es)),es);
i3++;
i1++;
}
i2=lb2;
while(i2<=ub2)
{
//x[i2]=tmp[i3];
memcpy(x+(i2*es),(const void *)(tmp+(i3*es)),es);
i2++;
i3++;
}
free(tmp);
if(success) *success=SUCCESSFUL;
}
void _mergeSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *),int *success,int *error)
{
if(success) *success=FAILED;
if(error) *error=NO_ERROR;
int succ,err;
int a,b,mid;
struct LBUB
{
int lb,ub;
};
Stack stack1,stack2;
initStack(&stack1,sizeof(struct LBUB),&succ,&err);
initStack(&stack2,sizeof(struct LBUB),&succ,&err);
struct LBUB lbub;
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack1,&lbub,&succ,&err);
if(!succ) 
{
if(error) *error=err;
return;
}
while(!isEmpty(&stack1,&succ,&err))
{
pop(&stack1,&lbub,&succ,&err);
push(&stack2,&lbub,&succ,&err);
if(!succ) 
{
clearStack(&stack1,&succ,&err);
clearStack(&stack2,&succ,&err);
if(error) *error=err;
return;
}
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,&lbub,&succ,&err);
if(!succ) 
{
clearStack(&stack1,&succ,&err);
clearStack(&stack2,&succ,&err);
if(error) *error=err;
return;
}
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,&lbub,&succ,&err);
if(!succ) 
{
clearStack(&stack1,&succ,&err);
clearStack(&stack2,&succ,&err);
if(error) *error=err;
return;
}
}
}
while(!isEmpty(&stack2,&succ,&err))
{
pop(&stack2,&lbub,&succ,&err);
if(!succ) 
{
clearStack(&stack1,&succ,&err);
clearStack(&stack2,&succ,&err);
if(error) *error=err;
return;
}
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,a,mid,mid+1,b,es,p2f,&succ,&err);
if(!succ) 
{
printf("6\n");
clearStack(&stack1,&succ,&err);
clearStack(&stack2,&succ,&err);
if(error) *error=err;
return;
}
}
if(success) *success=SUCCESSFUL;
}
void mergeSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*))
{
int succ,err;
_mergeSort(arr,0,size-1,sizeOfElement,ptr2func,&succ,&err);
if(!succ)
{
if(err==NULL_VALUE) printf("NULL value Error\n");
if(err==ELEM_SIZE_ZERO) printf("Element Size is 0\n");
else printf("Not Enough Memory\n");
}
}