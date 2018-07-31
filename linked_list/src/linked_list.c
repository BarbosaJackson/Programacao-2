#include "../inc/linked_list.h"

// cria e retorna uma lista inicializada com memória alocada e sua cabeça inicial apontando pra NULL
LIST *create_linked_list() {
	LIST *l = (LIST *) malloc(sizeof(LIST));
	l->head = NULL;
	return l;
}

// adiciona um elemento no inicio da lista
void add_front(LIST *l, void *item) {
	NODE *new_node = (NODE *) malloc(sizeof(NODE));
	new_node->item = item;
	new_node->next = l->head;
	l->head = new_node;
}

// verifica se a lista está vazia
int is_empty(LIST *list) {
	return list->head == NULL;
}

// adiciona um elemento no final da lista
void add_back(LIST *list, void *item) {
	NODE *new_node = (NODE *) malloc(sizeof(NODE));
	NODE *aux = list->head;

	new_node->item = item;
	new_node->next = NULL;
	
	if(is_empty(list)) {
		list->head = new_node;
		return;
	}
	
	while(aux->next != NULL) 
		aux = aux->next;
	
	aux->next = new_node;
}

// remove um elemento da lista, requisitando uma função que compara os elementos do tipo desejado para a lista
void remove_node(LIST *list, void *item, int (*equals)(void *, void *)) {
	return;
}

// exibe a lista, requisitando uma função que imprima um elemento do tipo desejado para a lista
void print_linked_list(LIST *list, void (*print)(void *)) {
	NODE *aux = list->head;
	while(aux != NULL) {
		(*print)(aux->item);
		aux = aux->next;
	}
}
