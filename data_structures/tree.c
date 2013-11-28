/* tree.c 
 *
 * Implementation of a binary search tree 
 */

#define _GNU_SOURCE_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
#define MAX(X, Y)	((X) > (Y) ? (X) : (Y))

char *strdup (const char *); 

// A tree has data and left/right child 
struct node {
	char *s; 
	int data; 
	Tree left; 
	Tree right; 
}; 

// Stack for iterative traversal 
struct s_node {
	Tree t; 
	struct s_node* next; 
}; 

// Helper function to make a new node 
Tree make_node(char *s, int data) {
	Tree t = malloc( sizeof(struct node)); 
	t->left = t->right = NULL; 
	t->data = data; 
	t->s = strdup(s); 

	return t; 
}

// Add a node to a tree 
Tree insert_t(Tree t, char *s, int data) {

	// Normal BST insertion
	if (t == NULL) return make_node(s, data); 

	if (strcmp(s, t->s) < 0) {
		t->left = insert_t(t->left, s, data); 
	}
	else if (strcmp(s, t->s) > 0) {
		t->right = insert_t(t->right, s, data); 
	}

	// Don't insert duplicates 
	return t; 
}

// TRAVERSALS
//
// Depth First 
void dump_preorder(Tree t) {

	if (t == NULL) 
		return;

	printf("%s\n", t->s); 
	dump_preorder(t->left); 
	dump_preorder(t->right); 
}
void dump_inorder(Tree t) {
	if (t == NULL)
		return; 

	dump_inorder(t->left); 
	printf("%s\n", t->s);		// Visit the node
	dump_inorder(t->right); 
}

void dump_postorder(Tree t) {
	if (t == NULL) 
		return; 

	dump_postorder(t->left); 
	dump_postorder(t->right); 
	printf("%s\n", t->s); 
}


// INORDER ITERATIVE TRAVERSAL 
// 1. Create a stack
// 2. Initialize current node as root
// 3. Push current node to stack and set current = current->next until NULL
// 4. If NULL and stack not empty
//	a. Pop top item from stack
//	b. Print and set current = current->right
//	c. Go to step 3. 
// 5. if NULL and stack is empty then exit 
void dump_inorder_iterative(Tree t) {
	// Set variables to mark current root 
	Tree current = t; 
	stack_t stack = NULL; 
	int exit = 0; 

	// push_tree(&stack, current); 
	while (!exit) {
		
		// Check left child of current node 
		if (current != NULL) {
			push_tree(&stack, current); 
			current = current->left; 
		}
		else {
			if (!is_empty(stack)) {
				current = pop_tree(&stack); 
				printf("%s ", current->s); 
				current = current->right; 
			}
			else {
				exit = 1; 
			}
		}
	}
}

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
void dump_postorder_iterative(Tree t) {
	Tree current = t; 
	stack_t stack = NULL; 

	do {

		// Move to leftmost node 
		while (current) {

			// Push right child and root to stack 
			if (current->right) {
		 		push_tree(&stack, current->right); 
		 	}
			push_tree(&stack, current); 

			// Set root as child's left root
			current = current->left; 
		}
	
		current = pop_tree(&stack); 

		// If popped has right child 
		if (!is_empty(stack) && current->right 
				&& (strcmp(peek(stack), current->right->s) == 0)) {

			pop_tree(&stack); 
			push_tree(&stack, current); 
			current = current->right; 
		}
		else {
			printf("%s ", current->s); 
			current = NULL; 
		}
	}
	while (!is_empty(stack)); 
}

// PREORDER ITERATIVE TRAVERSAL
// 1. Push root to an empty stack
// 2. While the stack isn't empty
//  a. Pop item from stack and print
//  b. Push right child of popped item onto stack
//  c. Push left child of popped item onto stack 
void dump_preorder_iterative(Tree t) {

	Tree current = t; 
	stack_t stack = NULL; 

	push_tree(&stack, current);		// 1. Push root to stack 
	while (!is_empty(stack)) {

		Tree current = pop_tree(&stack); 
		printf("%s ", current->s); 

		if (current->right) {
			push_tree(&stack, current->right); 
		}
		if (current->left) {
			push_tree(&stack, current->left); 
		}
	}
}
 
// BREATH FIRST TRAVERSAL 
// 1. Create an empty queue and add root to queue
// 2. While queue is not empty
//	a. Add the left child
//	b. Add the right child
/*
void breath_first(Tree t) {

	Tree current = t; 
	Tree traverse; 
	// Doesn't work
	queue_t* queue = create_queue(); 

	if (t == NULL) return; 

	add_queue(&queue, current); 

	while (!is_empty_queue(queue)) {
		traverse = remove_queue(&queue); 

		if (traverse->left) {
			add_queue(&queue, traverse->left); 
		}

		if (traverse->right) {
			add_queue(&queue, traverse->right); 
		}
	}
}
*/

Tree destroy_t(Tree t) {
	if (t == NULL) 
		return NULL; 

	t->left = destroy_t(t->left); 
	t->right = destroy_t(t->right); 

	free(t->s); 
	free(t); 
	return NULL; 
}

// ALG TO FIND A NODE
char *find_node(Tree t, char *str) {

	Tree traverse = t; 
	while (traverse != NULL) {

		// Compare current node 
		if (strcmp(traverse->s, str) == 0) {
			return traverse->s; 
		}
		else if (strcmp(traverse->s, str) > 0) {
			traverse = traverse->left; 
		}
		else if (strcmp(traverse->s, str) < 0) {
			traverse = traverse->right; 
		}
	}

	return NULL; 
}
Tree find_node_r(Tree t, char *str) {

	if (t == NULL) return NULL; 

	if (strcmp(t->s, str) == 0) {
		return t; 
	}
	else if (strcmp(t->s, str) > 0) {
		return find_node_r(t->left, str); 
	}
	else {
		return find_node_r(t->right, str); 
	}
}

int get_height(Tree t) {

	if (t == NULL) return 0; 

	return MAX(get_height(t->left), get_height(t->right)) + 1; 
}

// To find the lowest common ancestor of two nodes, 
// Start from the root, and traverse down. If both values
// are less than the value of current node, go left and 
// vice versa. If the value is between then, you found it; 
int lowest_common_ancestor(Tree t, int val1, int val2) {

	Tree traverse = t; 
	while (traverse != NULL) {

		int value = traverse->data; 
		if (val1 > value && val2 > value) {
			traverse = traverse->right; 
		}
		else if (val1 < value && val2 < value) {
			traverse = traverse->left; 
		}
		else {
			return value; 
		}
	}

	return -1; 
}

void flip_tree(Tree t) {

	if (t != NULL) {

		// Swap sides 
		Tree temp = t->left; 
		t->left = t->right; 
		t->right = temp; 

		flip_tree(t->right); 
		flip_tree(t->left); 
	}
}


// HELPER FUNCTIONS FOR THE STACK 
int is_empty(stack_t stack) {
	return (stack == NULL); 
}
char* peek(stack_t stack) {
	if (is_empty(stack)) {
		return NULL; 
	}
	stack_t head = stack; 
	Tree t = head->t; 
	return t->s; 
}

void push_tree(stack_t* stack, Tree t) {
	stack_t new = malloc (sizeof (stack_t)); 
	assert(new); 

	new->t = t; 
	new->next = *stack; 

	*stack = new; 
}
// HAS FREEING ISSUES 
Tree pop_tree(stack_t* stack) {

	if (is_empty(*stack)) {
		exit(0); 
		// return NULL; 
	}

	stack_t head = *stack; 
	Tree t = head->t; 

	*stack = head->next; 
	// free(head); 

	return t; 
}


