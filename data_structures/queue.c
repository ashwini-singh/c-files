/* queue.c 
 *
 * A queue is basically a wrapper around a linked list. 
 * aka a queue struct is a pointer to the head and tail of a 
 * linked list. Operations use linked list functions and modify
 * the position of the pointers. 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "ll.h"

// Linked list node 
struct node {
	int data; 
	struct node* next; 
}; 

// Head/tail pointers for queue 
struct queue {
	struct node* head; 
	struct node* tail; 
}; 

queue_t* create_queue() {

	queue_t* q = malloc(sizeof (queue_t)); 
	assert(q); 

	q->head = NULL; 
	q->tail = NULL; 

	return q; 
}

int is_empty_queue(queue_t* queue) {
	return (queue->head == NULL); 
}

void add_queue(queue_t* queue, int data) {
	if (is_empty_queue(queue)) {
		add_ll(&(queue->head), data); 
		queue->tail = queue->head; 
	}
	else {
		add_ll(&(queue->tail), data); 
		// add_ll(&(queue->tail->next), data); 
	}
}

int remove_queue(queue_t* q) {
	if (is_empty_queue(q)) {
		return -1; 
	}

	int result = remove_ll(&(q->head)); 
	if (q->head == NULL) q->tail = NULL; 

	return result; 
}

void print_queue(queue_t* queue) {

	print_ll(queue->head); 
}

