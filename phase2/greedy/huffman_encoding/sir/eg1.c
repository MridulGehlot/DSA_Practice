#include<stdio.h>
#include<stdlib.h>
int main()
{
struct cbt_node
{
char c;
unsigned int frequency,depth;
struct cbt_node *left,*right,*parent;
};
struct cbt_node **heap,*cbt_node_tmp;
int ci,ri,swi,lci,rci,heap_size;
struct bst_node
{
char c;
unsigned int frequency;
struct cbt_node *leaf;
struct bst_node *left,*right;
};
struct stack_node
{
void *address;
struct stack_node *next;
};
struct stack_node *top,*stack_node_tmp;
char data[]={"ccabbcaadcijkkaccbakkij"};
int e;
struct bst_node *bst_root,*bst_node,*bst_node_trailer;
unsigned int bst_node_count;
//create bst
bst_root=NULL;
bst_node_count=0;
for(e=0;data[e]!='\0';e++)
{
//search data[e]
bst_node=bst_root;
while(bst_node!=NULL)
{
if(bst_node->c==data[e]) break;
bst_node_trailer=bst_node;
if(data[e]<bst_node->c) bst_node=bst_node->left;
else bst_node=bst_node->right;
}//loop to search ends
if(bst_node==NULL)
{
bst_node_count++;
bst_node=(struct bst_node *)malloc(sizeof(struct bst_node));
bst_node->c=data[e];
bst_node->frequency=1;
bst_node->left=bst_node->right=NULL;
bst_node->leaf=NULL;
if(bst_root==NULL) bst_root=bst_node;
else
{
if(bst_node->c<bst_node_trailer->c) bst_node_trailer->left=bst_node;
else bst_node_trailer->right=bst_node;
}
}
else bst_node->frequency++;
}//loop to create BST ends here
//for testing the contenst of BST are
top=(struct stack_node *)malloc(sizeof(struct stack_node));
top->address=bst_root;
top->next=NULL;
while(top!=NULL)
{
bst_node=top->address;
stack_node_tmp=top;
top=top->next;
free(stack_node_tmp);
if(bst_node->right)
{
stack_node_tmp=(struct stack_node *)malloc(sizeof(struct stack_node));
stack_node_tmp->address=bst_node->right;
stack_node_tmp->next=top;
top=stack_node_tmp;
}
if(bst_node->left)
{
stack_node_tmp=(struct stack_node *)malloc(sizeof(struct stack_node));
stack_node_tmp->address=bst_node->left;
stack_node_tmp->next=top;
top=stack_node_tmp;
}
printf("Character : %c Frequency : %u\n",bst_node->c,bst_node->frequency);
} //pre order traversal ends (For testing only)
//create heap array
heap=(struct cbt_node **)malloc(sizeof(struct cbt_node)*bst_node_count);
//create min heap by traversing BST
//create complete binary tree
//create char array for encoding
//print encoding
//decode and print encoded material
//free heap array
//free complete binary tree
//free bst

return 0;
}