#include<stdlib.h>
typedef struct _GListNode
{
void *ptr;
struct _GListNode *next,*prev;
}GListNode;
GListNode * createGListNode()
{
GListNode *node=(GListNode *)malloc(sizeof(GListNode));
node->prev=node->next=NULL;
node->ptr=NULL;
return node;
}
void addToGList(void *ptr,GListNode **start,GListNode **end)
{
GListNode *node=createGListNode();
node->ptr=ptr;
if(*start==NULL)
{
*start=*end=node;
}
else
{
(*end)->next=node;
node->prev=*end;
*end=node;
}
}
void createCopyOfGList(GListNode *start,GListNode **targetStart,GListNode **targetEnd)
{
GListNode *t;
*targetStart=*targetEnd=NULL;
for(t=start;t;t=t->next) addToGList(t->ptr,targetStart,targetEnd);
}
void clearGList(GListNode **start,GListNode **end)
{
GListNode *t;
while(*start)
{
t=*start;
*start=(*start)->next;
free(t);
}
*end=NULL;
}

/*
int main()
{
return 0;
}
in main file you can include this
#include "glist.c"

int pathWithSumExists(BSTNode *root,int sum)
{
if(root==NULL) return 0;
sum=sum-root->data;
if(isLeadNode(root)) return sum==0;
if(root->left && pathWithSumExists(root->left,sum)) return 1;
if(root->right && pathWithSumExists(root->right,sum)) return 1;
return 0;
}

*/