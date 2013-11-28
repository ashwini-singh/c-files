/* tree.h */

#ifndef __TREE_H__
#define __TREE_H__

typedef struct node* Tree; 
typedef struct s_node* stack_t; 

Tree insert_t(Tree t, char *s, int data); 
Tree destroy_t(Tree t); 

// LOOKUP: 
// O(log n) time because you eliminate half the nodes
// from your search each iteration. 
char *find_node(Tree t, char *str); 
Tree find_node_r(Tree t, char *str); 

int get_height(Tree t); 
int lowest_common_ancestor(Tree t, int val1, int val2); 

void flip_tree(Tree t); 

// PRINT 
void dump_preorder(Tree t); 
void dump_inorder(Tree t); 
void dump_postorder(Tree t); 

// PREORDER ITERATIVE TRAVERSAL
// 1. Push root to an empty stack
// 2. While the stack isn't empty
//  a. Pop item from stack and print
//  b. Push right child of popped item onto stack
//  c. Push left child of popped item onto stack 
void dump_preorder_iterative(Tree t); 

// INORDER ITERATIVE TRAVERSAL 
// 1. Create a stack
// 2. Initialize current node as root
// 3. Push current node to stack and set current = current->next until NULL
// 4. If NULL and stack not empty
//	a. Pop top item from stack
//	b. Print and set current = current->right
//	c. Go to step 3. 
// 5. if NULL and stack is empty then exit 
void dump_inorder_iterative(Tree t); 

// POSTORDER ITERATIVE TRAVERSAL 
// 1. Create an empty stack
// 2.1 Do while root is not NULL
//	a. Push root's right child, then root to stack
//	b. Set root as root's left child 
// 2.2 Pop item and set it as root
//  a. If popped item has a right child AND right child
//		is at the top of the stack, remove the right child
//		from the stack, push root back into stack, and set
//		root as the right child. 
//  b. Else print the data and set root as NULL
// 2.3 Repeat 2.1/2.2 while stack not empty 
void dump_postorder_iterative(Tree t); 


void breath_first(Tree t); 

// Functions for stack 
int is_empty(stack_t stack); 
char* peek(stack_t stack); 
void push_tree(stack_t* stack, Tree t); 
Tree pop_tree(stack_t* stack); 

#endif
