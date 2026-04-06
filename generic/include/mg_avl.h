#ifndef __mg_avl
#define __mg_avl
typedef struct __node
{
void *ptr;
struct __node *left,*right;
}Node;
typedef struct AVLTree
{
Node *root;
int size;
}AVLTree;
#endif