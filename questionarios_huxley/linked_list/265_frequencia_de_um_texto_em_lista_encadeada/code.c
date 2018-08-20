#include <stdio.h>
#include <string.h>

typedef struct node {
	struct node *next;
	char value;
	int cont;
} _node;

typedef struct list{
	_node *head;
} _list;

_list *create_list() {
	_list *l = (_list *) malloc(sizeof(_list));
	l->head = NULL;
	return l;
}

void add(_list *l, char value, int qtd) {
	_node *newnode = (_node *) malloc(sizeof(_node)), *aux = l->head;
	newnode->value = value;
	newnode->next = l->head;
	newnode->cont = qtd;
	l->head = newnode;
}

void print_list(_list *l) {
	_node *current = l->head;
	if(current == NULL) {
	    printf("VAZIO\n");
	    return;
	}
	while(current != NULL) {
		printf("%c %d\n", current->value, current->cont);
		current = current->next;
	}
}

int main(void) {
	char str[100000];
	int chars[256], i, t;
	_list *l = create_list();

	scanf("%[^\n]s", str);
	
	t = strlen(str);
	
	for(i = 0; i < 256; i++) {
		chars[i] = 0;
	}
	
	for(i = 0; i < t; i++) {
		chars[str[i]]++;
	}
	
	for(i = 0; i < 255; i++) {
		if(chars[i] > 0) {
			add(l, i, chars[i]);
		}
	}
	print_list(l);
	return 0;
}