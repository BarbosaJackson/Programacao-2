#include "../inc/linked_list.h"

void print(void *item) {
	int i = *(int *)item;
	printf("%d\n", i);
}

int main() {
	LIST *l = create_linked_list();
	int *e = malloc(sizeof(int) * 10), i;
	for(i = 0; i < 5; i++) {
		e[i] = 10 + i;
		add_front(l, &e[i]);
	}
	for(i = 5; i < 10; i++) {
		e[i] = 10 + i;
		add_back(l, &e[i]);
	}
	print_linked_list(l, print);
	return 0;
}