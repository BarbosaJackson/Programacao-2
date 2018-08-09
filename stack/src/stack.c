#include "../inc/stack.h"

stack *create_stack() {
	stack *s = (stack *) malloc(sizeof(stack));
	s->top = NULL;
	s->size = 0;
	return s;	
}

node_s *create_node_s(int value) {
	node_s *ns = (node_s *) malloc(sizeof(node_s));
	ns->value = value;
	ns->bellow = NULL;
	return ns;
}


int is_empty(stack *s) {
	return !s->size;	
}

void push(stack *s, int value) {
	node_s *ns = create_node_s(value);
	ns->bellow = s->top;
	s->top = ns;
	s->size++;
}

int pop(stack *s) {
	if(!is_empty(s)){
		int value = s->top->value;
		node_s *aux = s->top;
		s->top = s->top->bellow;
		s->size--;
		free(aux);
		return value;
	}
	return -1;
}

int peek(stack *s) {
	return is_empty(s) ? -1 : s->top->value;
}

int stack_size(stack *s) {
	return s->size;
}