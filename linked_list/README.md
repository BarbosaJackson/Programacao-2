# Linked list

Uma lista encadeada é uma estrutura de dados que organiza os dados de forma que o primeiro elemento tem o seu conteúdo e um ponteiro que referencia o próximo e assim sucessivamente até o último, este tem seu ponteiro para o próximo apontado para NULO.
Aqui será implementada uma lista para valores inteiros, para utilizar com outro tipo de dado, basta trocar o tipo de dado de *value* na *struct node* e nas funções onde um valor é exigido.

# checklist to TAD
  - create_linked_list [ :heavy_check_mark: ]
  - create_node [ :heavy_check_mark: ]
  - insert_front [ :heavy_check_mark: ]
  - insert_back [ :heavy_check_mark: ]
  - remove_node [ :heavy_check_mark: ]
  - is_empty [ :heavy_check_mark: ]
  - print_linked_list [ :heavy_check_mark: ]
  - sort_list [ :heavy_check_mark: ]

# Linked List struct

```c

typedef struct node node;
typedef struct list list;
/*
 * struct node é uma struct com os dados de cada nó da 
 * lista e uma referencia para o próximo nó.
 */
struct node {
	int value;
	node *next;
};

/*
 * struct list é uma struct com a referencia pra 
 * cabeça da lista (cabeça é o primeiro elmento da 
 * lista).
 */
struct list {
	node *head;
};

```

# Linked List TAD

```c
/*
 * create_linked_list é uma função que cria uma lista 
 * alocando memória e setando a cabeça da lista para 
 * NULO, depois disso retorna a lista para onde foi 
 * chamada.
 */
list *create_linked_list();

/*
 * create_node recebe o valor que vai ser inserido na 
 * lista, na função é alocada memória para um nó, o 
 * campo value do node é atribuido ao value passado 
 * por parâmetro e seta o próximo para NULO, se o 
 * ponteiro para o próximo elemento for atribuir um 
 * outro nó da lista isto deve ser feito por quem 
 * invocar create_node.
 */
node *create_node(int value);
/*
 * is_empty verifica se a lista está vazia.
 * se estiver retorna 1, senão retorna 0.
 */
int is_empty(list *li);
/*
 * insert_front recebe a lista e o valor que se deseja 
 * inserir nela e o insere sempre como a nova cabeça 
 * da lista.
 */
void insert_front(list *li, int value);

/*
 * insert_back recebe a lista e o valor que se deseja 
 * inserir nela e o insere sempre como o último 
 * elemento da lista.
 */
void insert_back(list *li, int value);

/*
 * remove_element recebe a lista e o elemento que se 
 * deseja remover da lista, ele procura o elemento e 
 * se o encontrar o remove da lista e retorna 1, caso 
 * o elemento não seja encontrado, retorna 0.
 */
int remove_element(list *li, int element);

/*
 * print_linked_list recebe a lista e exibe todos os 
 * elementos pertencentes a lista.
 */
void print_linked_list(list *li);

/*
 * recebe a lista e a ordena utilizando um bubblesort.
 */
void sort_list(list *li);
```