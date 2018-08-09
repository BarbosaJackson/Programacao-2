#include "../inc/queue.h"

queue *create_queue() {
	queue *q = (queue *) malloc(sizeof(queue));
	q->start = q->end = NULL;
	return q;
}

node_queue *create_node_queue(int value) {
	node_queue *q = (node_queue *) malloc(sizeof(node_queue));
	q->value = value;
	q->next = NULL;
	return q;
}


int is_empty(queue *q) {
	return q->start == NULL;
}

void enqueue(queue *q, int value) {
	node_queue *new_node = create_node_queue(value);
	if(is_empty(q)) {
		q->start = q->end = new_node;
		return;
	}
	q->end->next = new_node;
	q->end = new_node;
}

int dequeue(queue *q) {
	if(is_empty(q)) {
		return -1;
	}
	node_queue *new_node = q->start;
	int dequeued = new_node->value;
	q->start = q->start->next;
	free(new_node);
	return dequeued;
}