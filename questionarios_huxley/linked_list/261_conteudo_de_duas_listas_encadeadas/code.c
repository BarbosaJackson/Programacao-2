#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *next;
	int value;
} _node;

typedef struct list{
	_node *head;
} _list;

_list *create_list() {
	_list *l = (_list *) malloc(sizeof(_list));
	l->head = NULL;
	return l;
}

void add(_list *l, int value) {
	_node *newnode = (_node *) malloc(sizeof(_node));
	newnode->value = value;
	newnode->next = l->head;
	l->head = newnode;
}

int search(_list *l, int key) {
	_node *aux = l->head;
	while(aux != NULL && aux->value != key)
		aux = aux->next;
	return aux == NULL;
}

int main(void) {
	_list *a = create_list(), *b = create_list();
	_node *current;
	int n, num;
	scanf("%d", &n);
	while(n-- > 0) {
		scanf("%d", &num);
		add(a, num);
	}
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &num);
		add(b, num);
	}

	for(current = b->head; current != NULL; current = current->next) {
		if(search(a, b->head->value)) {
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");
	return 0;
}