#include "../inc/linked_list.h"

int main(void) {
	list *li = create_linked_list();
	int i;
	for(i = 0; i < 10; i++){
		if(i < 5)
			insert_front(li, i + 1);
		else
			insert_back(li, i + 1);
	}
	print_linked_list(li);
	if(remove_element(li, 5))
		printf("5 removido\n");
	else
		printf("nao conseguiu remover o 5 \n");
	print_linked_list(li);
	if(remove_element(li, 1))
		printf("1 removido\n");
	else
		printf("nao conseguiu remover o 1\n");
	print_linked_list(li);
	if(remove_element(li, 10))
		printf("10 removido\n");
	else
		printf("nao conseguiu remover o 10\n");
	print_linked_list(li);
	sort_list(li);
	printf("ordered list:\n");
	print_linked_list(li);
	return 0;
}