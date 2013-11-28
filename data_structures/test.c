// Program to test all the data structures

#include <stdio.h>
#include <stdlib.h>
// #include "tree.h"
#include "ll.h"

int main(int argc, char* argv[]) {

	list_t* a = NULL; 
	add_ll(&a, 1); 
	add_ll(&a, 5); 
	add_ll(&a, 9); 

	list_t* b = NULL; 
	add_ll(&b, 1); 
	add_ll(&b, 2); 
	add_ll(&b, 6); 

	list_t* merge = merge_list(a, b); 
	print_ll(merge); 

	return 0; 

	/* Tree stuff 
	Tree t = NULL; 
	t = insert_t(t, "b", 2); 
	t = insert_t(t, "a", 1); 
	t = insert_t(t, "c", 3); 

	dump_preorder(t); 

	flip_tree(t); 

	printf("\n"); 
	dump_preorder(t); 

	return 0; 

	*/

	/* Hash table stuff
	int size = 1024; 
	hash_t h = make_table(size); 
	insert_table(&h, "a", "b"); 

	int i; 
	for (i = 0; i < size; i++) {
		if (h->entries[i] == NULL) {
			printf("%d: NULL\n", i); 
		}
		else {
			printf("%d: %s\n", i, h->entries[i]->value); 
		}

	}

	char *value = find_pair(h, "a"); 
	if (value == NULL) {
		printf("not found\n"); 
	}
	else {
		printf("value: %s\n", value); 
	}


	destroy_table(h); 

	return 0; 
	*/
}
