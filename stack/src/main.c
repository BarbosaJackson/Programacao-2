#include "../inc/stack.h"

int main(void) {
	stack *s = create_stack();
	int i;
	if(is_empty(s))
		printf("a pilha esta vazia\n");
	for(i = 0; i < 10; i++) {
		push(s, i+1);
	}
	printf("o elemento no topo eh %d\n", peek(s));
	printf("o tamanho da pilha eh %d\n", stack_size(s));
	while(!is_empty(s)) {
		printf("%d\n", pop(s));
	}
}