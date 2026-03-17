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
if(*start==NULL)
{
*start=*end=ptr;
}
else
{
(*end)->next=node;
node->prev=*end;
*end=node;
}
}
void createCopyOfGlist(GListNode *start,GListNode **targetStart,GListNode **targetEnd)
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
16/3/26

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
if(isLeafNode(root)) return sum==0;
if(root->left && pathWithSumExistsWithPrintOption(root->left,sum)) return 1;
if(root->right && pathWithSumExistsWithPrintOption(root->right,sum)) return 1;
return 0;
}


17/3/26

typedef struct _PathSumHeaderNode
{
GListNode *start;
GListNode *end;
int size;
}PathSumHeaderNode;

PathSumHeaderNode * createPathSumHeaderNode()
{
PathSumHeaderNode *node=(PathSumHeaderNode *)malloc(sizeof(PathSumHeaderNode));
node->start=node->end=NULL;
node->size=0;
}

int pathWithSumExistsWithPrintOption(BSTNode *root,int sum)
{
GListNode *vt,*ht;
PathSumHeaderNode *headerNode;
BSTNode *bstNode;
int result;
GlistNode *mainListStart,*mainListEnd;
result=_pathWithSumExistsWithPrintOption(root,sum,NULL,&mainListStart,&mainListEnd);
for(vt=mainListStart;vt;vt=vt->next)
{
headerNode=(PathSumHeaderNode *)vt->ptr;
printf("Size is : %d : Path is [",headerNode->size);
for(ht=headerNode->start;ht;ht=ht->next)
{
bstNode=(BSTNode *)ht->ptr;
pritnf("%d ",bstNode->data);
if(headerNode!=ht) printf("--> ");
else pritnf("]\n");
}
}
return result;
}


int _pathWithSumExistsWithPrintOption(BSTNode *root,int sum,PathSumHeaderNode *headerNode,GListNode **mainListStart,GListNode **mainListEnd)
{
PathSumHeaderNode *headerNodeForCopy;
int leftChildAnswer,rightChildAnswer;
if(root==NULL) return 0;
sum=sum-root->data;

if(headerNode==NULL) headerNode=createPathSumHeaderNode();
addToGList(root,&(headerNode->start),&(headerNode->end));
headerNode->size++;

if(isLeafNode(root))
{
if(sum==0)
{
addToGList(headerNode,mainListStart,mainListEnd);
return 1;
}
else
{
if(headerNode) 
{
clearGList(&(headerNode->start),&(headerNode->end));
free(headerNode);
}
return 0;
}
}

if(root->left && root->right)
{
headerNodeForCopy=createPathSumHeaderNode();
createCopyOfGList(headerNode->start,&(headerNodeForCopy->start),&(headerNodeForCopy->end));
headerNodeForCopy->size=headerNode->size;
leftChildAnswer=_pathWithSumExistsWithPrintOption(root->left,sum,headerNode,mainListStart,mainListEnd);
rightChildAnswer=_pathWithSumExistsWithPrintOption(root->right,sum,headerNodeForCopy,mainListStart,mainListEnd);
return leftChildAnswer==1 || rightChildAnswer==1;

pass the Linked List to left and 
create Copy and pass the copy to right
}

if(root->left)
{
leftChildAnswer=_pathWithSumExistsWithPrintOption(root->left,sum,headerNode,mainListStart,mainListEnd);
return leftChildAnswer;
}
if(root->right)
{
rightChildAnswer=_pathWithSumExistsWithPrintOption(root->right,sum,headerNodeForCopy,mainListStart,mainListEnd);
return rightChildAnswer;
}
return 0;
}

*/