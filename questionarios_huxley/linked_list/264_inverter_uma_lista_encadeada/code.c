#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct list list;

struct node {
	int value;
	node *next;
};

struct list {
	node *head;
};

list *create_list() {
	list *l = (list *) malloc(sizeof(list));
	l->head = NULL;
	return l;
}

void add(list *l, int value) {
	node *newnode = (node *) malloc(sizeof(node));
	node *aux = l->head;
	newnode->value = value;
	newnode->next = NULL;
	
	if(l->head == NULL) {
		l->head = newnode;
		return;
	}
	
	while(aux->next != NULL) 
	    aux = aux->next;
	aux->next = newnode;
}


void print(list *l) {
	node *i = l->head;
	while(i != NULL) {
		printf("%d ", i->value);
		i = i->next;
	}
	printf("\n");
}

void reverse(node *current, node *prev, list *l) {
	if(current->next != NULL) {
		reverse(current->next, current, l);
	}
	if(current->next == NULL) {
		l->head = current;
	}
	current->next = prev;	
}

int main() {
	int n;
	list *l = create_list();
	while(scanf("%d", &n) != EOF) {
		add(l, n);
	}
	reverse(l->head, NULL, l);
	print(l);
	return 0;
}