#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
typedef struct list LIST;

struct node{
	int value;
	NODE *next, *prev;
};

struct list {
	NODE *head;
	int size;
};


LIST *create_list() {
	LIST *l = (LIST *) malloc(sizeof(LIST));
	l->head = NULL;
	return l;
}


NODE *create_node (int value) {
	NODE *n = (NODE *) malloc(sizeof(NODE));
	n->next = n->prev = NULL;
	n->value = value;
	return n;
}


void add(LIST *l, int value) {
	NODE *n = create_node(value);
	NODE *aux = l->head;
	if(l->head == NULL) {
		l->head = n;
		return;
	}
	while(aux->next != NULL) {
		aux = aux->next;
	}
	aux->next = n;
	n->prev = aux;
}


void print_list(LIST *l) {
	NODE *n = l->head;
	while(n != 	NULL) {
		if(n->next == NULL)	printf("%d\n", n->value);
		else printf("%d ", n->value);		
		n = n->next;
	}
}


NODE *highest_value(LIST *l, int sz) {
	int i;
	NODE *current = l->head->next;
	NODE *highest = (NODE *)malloc(sizeof(NODE));
	highest = l->head;
	for(i = 1; i < sz; i++) {
		if(highest->value < current->value) {
			highest = current;
		}
		current = current->next;
	}
	return highest;
}


int size(LIST *l) {
	int i = 0;
	NODE *current = l->head;
	while(current != NULL){
		i++;
		current = current->next;
	}
	return i;
}


int get_index(NODE *n, LIST *l) {
	NODE *nn = l->head;
	int i = 0;
	while(nn != NULL) {
		if(nn->value == n->value) {
			return i;
		}
		nn = nn->next;
		i++;
	}
	return -1;
}


void order(LIST *l) {
	int sz = size(l), i;
	while(sz) {
		NODE *n, *aux, *ref; 
		n = highest_value(l, sz); 
		aux = n; 
		i = get_index(n, l); 
		while(i < sz-1) { 
			if(!i && aux->prev == NULL){ 
				l->head = aux->next;
			}
			if(aux->next != NULL){ 
				
				ref = aux->next; 

				ref->prev = aux->prev; 
				if(aux->prev != NULL){ 
					aux->prev->next = ref; 
				}
				aux->prev = ref; 
				aux->next = ref->next; 
				if(ref->next != NULL) { 
					ref->next->prev = aux; 
				}
				ref->next = aux; 
			}
			i++; 
		}
		sz--; 
	}
}

int main() {
	LIST *l = create_list(); 
	int n; 
	while(scanf("%d", &n) != EOF) { 
		add(l, n); 
	}
	order(l); 
	print_list(l); 
	return 0;
}
