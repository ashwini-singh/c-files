// ll.c 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ll.h"

int contains(int a[], int value); 

struct node {
	int data; 
	struct node* next; 
}; 

int is_empty_ll(list_t* list) {
	return (list == NULL); 
}

// Add a node to beginning of linked list
void add_ll(list_t** list, int data) {

	list_t* new = malloc(sizeof (struct node)); 
	new->data = data; 
	new->next = *list; 

	*list = new; 
}

// Remove node from beginning of list 
int remove_ll(list_t** list) {

	if (is_empty_ll(*list)) {
		return -1; 
	}

	list_t* head = *list; 
	int result = head->data; 

	*list = head->next; 
	free(head); 
	return result; 
}

// Removes a node from the middle if it exists
int remove_middle_ll(list_t** list, int value) {

	list_t* traverse = *list;
	list_t* prev = NULL; 

	// Traverse through the list 
	while (!is_empty_ll(traverse)) {

		// Remove the node 
		if (traverse->data == value) {

			// Beginning of list 
			if (prev == NULL) {	
				*list = traverse->next; 
			}
			else {
				prev->next = traverse->next; 
			}

			free(traverse); 
			break; 
		}
		prev = traverse; 
		traverse = traverse->next; 
	}

	return 0; 
}

void remove_duplicates(list_t** list) {
		
	int len = 10; 
	int seen[len]; 
	int i;
	for (i = 0; i < len; i++) {
		seen[i] = -1; 
	}
	int index = 0; 

	list_t* traverse = *list; 
	while (!is_empty_ll(traverse)) {

		if (contains(seen, traverse->data)) {
			remove_middle_ll(list, traverse->data); 
		}
		else {
			seen[index++] = traverse->data;
		}
		traverse = traverse->next; 
	}

}

// Merge two sorted linked lists
list_t* merge_list(list_t* a, list_t* b) {

	// Do error checks here
	if (a == NULL) return b; 
	if (b == NULL) return a; 

	list_t* head; 
	if (a->data < b->data) {
		head = a;	// Set the head 
	}
	else {
		head = b;	// Swap the two so the smallest data is at the head 
		b = a; 
		a = head; 
	}

	// Traverse through 
	while (a->next != NULL && b != NULL) {
		
		// If current ll data is less, increment 
		if (a->next->data <= b->data) {
			a = a->next; 
		}
		else {			// If not switch the two 
			list_t* temp = a->next; 
			a->next = b; 
			b = temp; 
		}
	}

	if (a->next == NULL) {
		a->next = b; 
	}

	return head; 
}


// Returns 1 if value is in array 
int contains(int a[], int value) {
	
	int len = sizeof(a)/sizeof(int);
	int i; 
	for (i = 0; i < len; i++) {
		if (value == a[i]) {
			return 1; 
		}
	}
	return 0; 
}

// Print the list
void print_ll(list_t* list) {

	list_t* traverse = list; 
	while (!is_empty_ll(traverse)) {
		printf("%d ", traverse->data); 
		traverse = traverse->next; 
	}
	printf("\n"); 
}

// Destroy the list
void destroy_ll(list_t** list) {
	list_t* head = *list; 
	while (head) {
		*list = head->next; 
		free(head); 
		head = *list; 
	}
}

// Simpler version of destroy 
void destroy_ll2(list_t* list) {
	while (list) remove_ll(&list); 
}


