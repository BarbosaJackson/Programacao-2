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

void order_list(_list *l) {
	_node *i, *j;
	int aux;
	for(i = l->head; i != NULL; i = i->next) {
		for(j = i->next; j != NULL; j = j->next) {
			if(j->value < i->value) {
				aux = i->value;
				i->value = j->value;
				j->value = aux;
			}
		}
	}
}

int search(_list *l, int key) {
	_node *aux = l->head;
	while(aux != NULL && aux->value != key)
		aux = aux->next;
	return aux == NULL;
}

void print_list(_list *l) {
	_node *current = l->head;
	while(current != NULL) {
		printf("%d\n", current->value);
		current = current->next;
	}
}

void read_list(int limite, int cont, _list *l) {
	int n;
	if(limite == cont) 
		return;
	scanf("%d", &n);
	add(l, n);
	read_list(limite, cont + 1, l);
}

int main(void) {
    _list *l1 = create_list(), *l2 = create_list(), *l3 = create_list();
    _node *i;
    int flag = 0;
    read_list(20, 0, l1);
    read_list(20, 0, l2);
    for(i = l2->head; i != NULL; i = i->next) {
    	if(!search(l1, i->value)){
    		if(search(l3, i->value))
    			add(l3, i->value);
    	}
    }
    if(l3->head != NULL) {
    	order_list(l3);
    	print_list(l3);
	} else printf("VAZIO\n");
    return 0;
}