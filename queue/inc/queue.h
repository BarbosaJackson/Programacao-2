#include <stdio.h>
#include <stdlib.h>

#ifndef queue_h
#define queue_h

typedef struct node_queue node_queue;
typedef struct queue queue;

struct node_queue {
	int value;
	node_queue *next;
};

struct queue {
	node_queue *start;
	node_queue *end;
};

node_queue *create_node_queue(int value);
queue *create_queue();
void enqueue(queue *q, int value);
int dequeue(queue *q);
int is_empty(queue *q);

#endif