#include <stdio.h>
#include <stdlib.h>

#ifndef stack_h
#define stack_h

typedef struct node_stack node_s;
typedef struct stack stack;

struct node_stack {
	int value;
	node_s *bellow;
};

struct stack {
	node_s *top;
	int size;
};

stack *create_stack();
node_s *create_node_s(int value);
void push(stack *s, int value);
int pop(stack *s);
int peek(stack *s);
int is_empty(stack *s);
int stack_size(stack *s);

#endif