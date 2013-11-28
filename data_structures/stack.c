/* stack.c 
 *
 * NON HEADED 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct node {
	int data; 
	Tree t; 
	struct node* next; 
}; 

int is_empty(stack_t* stack) {
	return (stack == NULL); 
}

// Add value to beginning of stack 
void push(stack_t** stack, int data) {
	struct node* new = malloc (sizeof (struct node)); 
	assert(new); 

	new->data = data; 
	new->next = *stack; 

	*stack = new; 
}

// Returns -1 if stack is empty
int pop(stack_t** stack) {

	if (is_empty(*stack)) {
		return -1; 
	}

	stack_t* head = *stack; 
	int result = head->data; 

	*stack = head->next; 
	free(head); 

	return result; 
}

void print_stack(stack_t* stack) {
	if (is_empty(stack)) {
		printf("empty\n"); 
	}
	else {
		while (stack) {
			printf("%d ", stack->data); 
			stack = stack->next; 
		}
		printf("\n"); 
	}
}

