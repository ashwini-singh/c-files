/* queue.h */

#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct queue queue_t; 

queue_t* create_queue(); 

int is_empty_queue(queue_t* queue); 

void add_queue(queue_t* queue, int data); 
void print_queue(queue_t* queue); 

int remove_queue(queue_t* queue); 

#endif
