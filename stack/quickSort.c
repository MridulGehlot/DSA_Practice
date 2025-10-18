#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
int lb,ub;
struct Node *next;
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
void quickSort(int *arr,int size)
{
int top,lb,ub,e,f,pp,tmp;
lb=0;
ub=size-1;
//push lb,ub on stack
push(lb,ub);
while(!isEmpty())
{
pop(&lb,&ub);
e=lb;
f=ub;
while(e<f)
{
while(e<ub && arr[e]<=arr[lb]) e++;
while(arr[f]>arr[lb]) f--;
if(e<f)
{
tmp=arr[e];
arr[e]=arr[f];
arr[f]=tmp;
}
else
{
tmp=arr[f];
arr[f]=arr[lb];
arr[lb]=tmp;
pp=f;
}
}
if(pp+1<ub) push(pp+1,ub);
if(lb<pp-1) push(lb,pp-1);
}
}
void show(int *arr,int size)
{
for(int i=0;i<size;i++) printf("%d\n",arr[i]);
}
int main()
{
top=NULL;
int req;
int *arr;
printf("Enter Requirement - ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement");
return 0;
}
arr=(int *)malloc(sizeof(int)*req);
if(arr==NULL)
{
printf("Unable To Allocate Memory");
return 0;
}
for(int i=0;i<req;i++)
{
printf("Enter A Number - ");
scanf("%d",&arr[i]);
}
quickSort(arr,req);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}