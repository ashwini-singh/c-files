/* hash_table.c 
 *
 * A hash table is a data structure that supports insert/delete/
 * find in O(1) time. Uses a hash function to map a large number
 * of elements into a smaller number of array indices. Uses
 * constant time operations to store/retrieve the data. 
 *
 * This hash table uses CHAINING for collision resolution. 
 */ 

#define _GNU_SOURCE_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "hash_table.h"

// Get rid of compiler warnings 
char *strdup(char *s); 



hash_t make_table(int size) {

	int i; 

	// Allocate space for the table. 
	hash_t h = malloc(sizeof(struct table)); 
	assert(h); 

	h->size = size; 

	// Allocate space for pointers to head nodes 
	h->entries = malloc(size * sizeof(struct element *)); 
	assert(h->entries); 

	for (i = 0; i < size; i++) {
		h->entries[i] = NULL; 
	}
	
	return h; 
}

static int hash_f(char *key, long size) {

	unsigned long sum; 
	const long prime = 3141592661; 

	for (sum = 0; *key; key++) {
		sum = (sum << 4) ^ *key; 
	}

	return ((prime * sum) % size); 
}

struct element* new_pair(char *key, char *value) {

	struct element* new_node = malloc(sizeof (struct element )); 
	assert(new_node); 

	new_node->key = strdup(key); 
	new_node->value = strdup(value); 
	new_node->next = NULL; 

	return new_node; 
}

void insert_table(hash_t *h, char *key, char *value) {

	// Compute hash value of key. 
	long hash_val = hash_f(key, (*h)->size); 

	// Create the new pair
	struct element* new_node = new_pair(key, value); 

	// Create pointer to traverse the linked list 
	struct element* temp = (*h)->entries[hash_val]; 

	// If there's no entry already 
	if (temp == NULL) {
		new_node->next = temp; 
		(*h)->entries[hash_val] = new_node; 
		printf("1\n"); 
	}
	/*
	else {
		while (temp != NULL) {
			temp = temp->next; 
		}
		temp->next = new_node; 
		h->entries[hash_val] = temp;
	}
	*/
}

char *find_pair(hash_t h, char *key) {

	long hash_val = hash_f(key, h->size); 
	struct element* pair = h->entries[hash_val]; 

	while (pair != NULL && !strcmp(pair->key, key)) {
		pair = pair->next; 
	}

	if (pair == NULL) {
		return NULL; 
	}
	else {
		return pair->value; 
	}
}

void destroy_table(hash_t h) {

	int size = h->size; 
	int i; 

	for (i = 0; i < size; i++) {
		free(h->entries[i]); 
	}
	free(h->entries); 
	free(h); 
}
