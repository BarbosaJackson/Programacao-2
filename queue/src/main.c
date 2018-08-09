#include "../inc/queue.h"

int main(void) {
	queue *q = create_queue();
	int i;
	printf("%s\n", is_empty(q) ? "esta vazia" : "nao estao vazia");
	for(i = 0; i < 10; i++) {
		enqueue(q, i + 1);
	}
	while(!is_empty(q)){
		printf("%d\n", dequeue(q));
	}
	return 0;
}