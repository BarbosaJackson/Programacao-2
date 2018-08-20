#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node node;
typedef struct _list _list;

struct _node {
	char key;
	node *next;
};

struct _list {
	node *head;
};

void add(_list *l, char c) {
	node *newnode = (node *) malloc(sizeof(node));
	node *aux = l->head;
	newnode->key = c;
	newnode->next = NULL;
	if(l->head == NULL) {
		l->head = newnode;
		return;
	}
	while(aux->next != NULL)
		aux = aux->next;
	aux->next = newnode;
}

void search_greater_sequence(_list *l) {
	node *i = l->head;
	int start, end, greater_start, greater_end, cont = 0, len_seq = 0, greater_sequence = 0;
	while(i != NULL) {
		if(i->key == '0') {
			len_seq = 0;
			start = cont;
			while(i != NULL && i->key == '0') {
				cont++;
				len_seq++;
				i = i->next;
			}
			end = cont-1;
			if(len_seq > greater_sequence) {
				greater_sequence = len_seq;
				greater_start = start;
				greater_end = end;
			}
		}
		if(i != NULL) {
			i = i->next;
		}
		cont++;
	}
	printf("%d %d\n", greater_start, greater_end);
}

_list *create_list() {
	_list *l = (_list *) malloc(sizeof(_list));
	l->head = NULL;
	return l;
}

void clear_list(_list *l) {
	node *aux = l->head;
	while(aux != NULL) {
		l->head = l->head->next;
		free(aux);
		aux = l->head;
	}
}

int main() {
	int i, len;
	char str[100000];
	_list *l = create_list();
	scanf("%s", str);
	while(strcmp(str, "0") != 0) {
		len = strlen(str);
		for(i = 0; i < len; i++) {
			add(l, str[i]);
		}
		search_greater_sequence(l);
		clear_list(l);
		scanf("%s", str);
	}
	return 0;
}