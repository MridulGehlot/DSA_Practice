#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
int data;
struct _Node *left,*right;
}Node;

Node *root=NULL;

Node * createNode(int data)
{
Node *n=(Node *)malloc(sizeof(Node));
n->data=data;
n->left=n->right=NULL;
return n;
}

void addToAVLTree(Node *root,Node *n)
{
if(!root) 
{
root=n;
return;
}
if(root->left==NULL && root)
}

void insert(Node *root,int data)
{
Node *n=createNode(data);
addToAVLTree(root,n);
}

void inorder(Node *root)
{
if(!root) return;
inorder(root->left);
printf("%d"root->data);
inorder(root->right);
}

int main()
{
insert(root,10);
inorder(root);
return 0;
}