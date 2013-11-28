/* stack.h */

#ifndef _STACK_H_
#define _STACK_H_

// typedef struct stack stack_t; 
typedef struct node stack_t; 

// Initialize and return pointer to stack. 
// stack_t* create_stack(); 

// Returns 1 if stack is empty. 0 otherwise. 
int is_empty(stack_t* stack); 

// Adds a value to the top of the stack. 
void push(stack_t** stack, int data); 

// Removes and returns the value at top of stac. 
// Returns -1 if empty stack 
int pop(stack_t** stack); 

// Print the contents of the stack 
void print_stack(stack_t* stack); 

#endif
