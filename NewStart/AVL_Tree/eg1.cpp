#include<stdio.h>
#include<stack>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef struct _Node
{
int data;
struct _Node *left,*right;
}Node;
Node *head=NULL;
stack<Node *> stk;
Node * createNode(int data)
{
Node *n=(Node *)malloc(sizeof(Node));
n->data=data;
n->left=n->right=NULL;
return n;
}
void balance(Node *root,int leftHeight,int rightHeight)
{
Node *k,*j;
Node **ptr;
if(!stk.empty())
{
if(root==stk.top()->right) ptr=&(stk.top()->right);
else ptr=&(stk.top()->left);
}
else ptr=&head;
//check which side is imbalance
if(leftHeight>rightHeight) //left side
{
if(root->left->left) //left is left Heavy
{
j=root->left;
root->left=j->right;
j->right=root;
*ptr=j;
}
else //left is right heavy
{
k=root->left;
j=root->left->right;
j->left=k;
k->right=NULL;
root->left=j;
//now we created left is left heavy so rotate
root->left=j->right;
j->right=root;
*ptr=j;
}
}
else //right side
{
if(root->right->right) //right is right heavy
{
j=root->right;
root->right=j->left;
j->left=root;
*ptr=j;
}
else //right is left heavy
{
k=root->right;
j=root->right->left;
j->right=k;
k->left=NULL;
root->right=j;
//now we created right is right heavy so rotate
root->right=j->left;
j->left=root;
*ptr=j;
}
}
}

int height(Node *root)
{
if(!root) return 0;
return max(height(root->left),height(root->right))+1;
}

void insert(int data)
{
Node *n,*t,*j;
int leftHeight,rightHeight,diff;
n=createNode(data);
if(head==NULL)
{
head=n;
return;
}
t=head;
while(t)
{
stk.push(t);
if(t->data>data) t=t->left;
else t=t->right;
}
//insert
t=stk.top();
if(t->data>data) t->left=n;
else t->right=n;

//Check Unbalanced Tree
while(!stk.empty())
{
t=stk.top();
stk.pop();
leftHeight=height(t->left);
rightHeight=height(t->right);
diff=abs(leftHeight-rightHeight);
if(diff>1) //need to balance
{
balance(t,leftHeight,rightHeight);
}
}
}

void inorder(Node *root)
{
if(!root) return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
void printTree(Node *root, int space)
{
    if(root==NULL) return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for(int i=10; i<space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}
int main()
{
insert(60);
insert(40);
insert(80);
insert(30);
insert(50);
insert(45);   // LR imbalance at 60    printf("Inorder:\n");
    inorder(head);

    printf("\n\nTree Structure:\n");
    printTree(head,0);return 0;
}