#include <stdio.h>
#include <stdlib.h>

#ifndef linked_list_h
#define linked_list_h
typedef struct node node;
typedef struct list list;

struct node {
	int value;
	node *next;
};

struct list {
	node *head;
};

list *create_linked_list();
node *create_node(int value);
int is_empty(list *li);
void insert_front(list *li, int value);
void insert_back(list *li, int value);
int remove_element(list *li, int element);
void print_linked_list(list *li);
void sort_list(list *li);

#endif