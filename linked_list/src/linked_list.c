#include "../inc/linked_list.h"
#include "../../utils/inc/utils.h"

list *create_linked_list() {
	list *new_list = (list *) malloc(sizeof(list));
	new_list->head = NULL;
	return new_list;
}

node *create_node(int value) {
	node *new_node = (node *)malloc(sizeof(node));
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}

int is_empty(list *li) {
	return li->head == NULL;
}

void insert_front(list *li, int value) {
	node *insert_node = create_node(value);
	insert_node->next = li->head;
	li->head = insert_node;
}

void insert_back(list *li, int value) {
	node *current = li->head;
	if(is_empty(li)){
		li->head = create_node(value);
		return;
	}
	while(current->next != NULL) 
		current = current->next;
	current->next = create_node(value);
}

int remove_element(list *li, int element) {
	node *current = li->head->next;
	node *prev = NULL;
	if(li->head == NULL)
		return 0;
	if(li->head != NULL && element == li->head->value) {
		current = li->head;
		li->head = li->head->next;
		free(current);
		return 1;
	}
	while(current != NULL && current->value != element) {
		prev = current;
		current = current->next;
	}
	if(prev != NULL) {
		prev->next = current->next;
		free(current);
		return 1;
	}
	return 0;
}

void print_linked_list(list *li) {
	node *current = li->head;
	while(current->next != NULL) {
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("%d\n", current->value);
}

void sort_list(list *li) {
	node *i, *j;
	for(i = li->head; i->next != NULL; i = i->next){
		for(j = i->next; j != NULL; j = j->next) {
			if(i->value > j->value)
				swap(&i->value, &j->value);
		}
	}
}