/* ll.h */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node list_t; 

// Check if a list is empty 
int is_empty_ll(list_t* list); 

void add_ll(list_t** list, int data); 

int remove_ll(list_t** list); 
void remove_duplicates(list_t** list); 
int remove_middle_ll(list_t** list, int value); 
list_t* merge_list(list_t* a, list_t* b); 

void destroy_ll(list_t** list);
void destroy_ll2(list_t* list); 

void print_ll(list_t* list); 


#endif


