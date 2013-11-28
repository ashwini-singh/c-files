/* hash_table.h */

#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

struct element {
	char *key; 
	char *value; 
	struct element* next; 
}; 
struct table {
	int size; 
	struct element** entries; 
}; 
typedef struct table* hash_t; 

hash_t make_table(int size); 

struct element* new_pair(char *key, char *value); 

// void insert_table(hash_t h, char *key, char *value); 
void insert_table(hash_t *h, char *key, char *value); 

char *find_pair(hash_t h, char *key); 

void destroy_table(hash_t h); 

#endif
