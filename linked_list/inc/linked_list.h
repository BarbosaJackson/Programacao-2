#include <stdio.h>
#include <stdlib.h>

#ifndef linked_list_h
#define linked_list_h

typedef struct node NODE;

struct node {
	void *item;
	NODE *next;
};

typedef struct list {
	NODE *head;
} LIST;

LIST *create_linked_list();
void add_front(LIST *list, void *item);
void add_back(LIST *list, void *item);
void remove_node(LIST *list, void *item, int (*equals)(void *, void *));
int is_empty(LIST *list);
void print_linked_list(LIST *list, void (*print)(void *));

#endif