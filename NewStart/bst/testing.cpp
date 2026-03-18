#include "glist.c"
#include<stdio.h>
#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;
typedef struct _BSTNode
{
int data;
struct _BSTNode *left,*right;
}BSTNode;
BSTNode *root=NULL;
BSTNode * createNode(int data)
{
BSTNode *n=(BSTNode *)malloc(sizeof(BSTNode));
n->data=data;
n->left=n->right=NULL;
return n;
}
void insert(int data)
{
BSTNode *n,*t;
n=createNode(data);
if(root==NULL)
{
root=n;
return;
}
t=root;
while(1)
{
if(t->data<data)
{
if(t->right) t=t->right;
else
{
t->right=n;
break;
}
}
else
{
if(t->left) t=t->left;
else
{
t->left=n;
break;
}
}
}
}
int height(BSTNode *root)
{
if(!root) return 0;
return min(height(root->left),height(root->right))+1;
}

int isLeafNode(BSTNode *node)
{
return node && node->left==NULL && node->right==NULL;
}


/*
int pathWithSumExists(BSTNode *root,int sum)
{
if(root==NULL) return 0;
sum=sum-root->data;
if(isLeafNode(root)) return sum==0;
if(root->left && pathWithSumExistsWithPrintOption(root->left,sum)) return 1;
if(root->right && pathWithSumExistsWithPrintOption(root->right,sum)) return 1;
return 0;
}
*/
int pathWithSumExists(BSTNode *root,int sum)
{
if(root==NULL) return 0;
sum=sum-root->data;
if(isLeafNode(root)) return sum==0;
if(root->left && pathWithSumExists(root->left,sum)) return 1;
if(root->right && pathWithSumExists(root->right,sum)) return 1;
return 0;
}


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
return node;
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
/*
pass the Linked List to left and 
create Copy and pass the copy to right
*/
}

if(root->left)
{
leftChildAnswer=_pathWithSumExistsWithPrintOption(root->left,sum,headerNode,mainListStart,mainListEnd);
return leftChildAnswer;
}
if(root->right)
{
rightChildAnswer=_pathWithSumExistsWithPrintOption(root->right,sum,headerNode,mainListStart,mainListEnd);
return rightChildAnswer;
}
return 0;
}


int pathWithSumExistsWithPrintOption(BSTNode *root,int sum)
{
GListNode *vt,*ht;
PathSumHeaderNode *headerNode;
BSTNode *bstNode;
int result;
GListNode *mainListStart,*mainListEnd;
mainListStart=mainListEnd=NULL;
result=_pathWithSumExistsWithPrintOption(root,sum,NULL,&mainListStart,&mainListEnd);
for(vt=mainListStart;vt;vt=vt->next)
{
headerNode=(PathSumHeaderNode *)vt->ptr;
printf("Size is : %d : Path is [",headerNode->size);
for(ht=headerNode->start;ht;ht=ht->next)
{
bstNode=(BSTNode *)ht->ptr;
printf("%d ",bstNode->data);
if(headerNode->end!=ht) printf("--> ");
else printf("]\n");
}
}
return result;
}


int main()
{
insert(100);
insert(50);
insert(175);
insert(75);
insert(200);
insert(10);
insert(45);
insert(170);
insert(80);
insert(20);
int x;
scanf("%d",&x);
int res=pathWithSumExists(root,x);
if(res) printf("Path With Sum (%d) Exists\n",x);
else printf("Path With Sum (%d) Does Not Exists\n",x);
res=pathWithSumExistsWithPrintOption(root,x);
if(res) printf("Path With Sum (%d) Exists\n",x);
else printf("Path With Sum (%d) Does Not Exists\n",x);

return 0;
}
