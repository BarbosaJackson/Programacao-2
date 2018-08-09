# Stack

Pilha é a estrutura de dados que organiza os dados seguindo o conceito de first in last out, ou seja, o primeiro a entrar na pilha é o ultimo a sair dela, com isso, sempre retira-se o valor que está no topo da pilha.

# checklist Stack TAD
  - create_stack  [ :heavy_check_mark: ]
  - create_node_s [ :heavy_check_mark: ]
  - push [ :heavy_check_mark: ]
  - pop [ :heavy_check_mark: ]
  - peek [ :heavy_check_mark: ]
  - is_empty [ :heavy_check_mark: ]
  - stack_size [ :heavy_check_mark: ]

# Stack struct
```c
typedef struct node_stack node_s;
typedef struct stack stack;

/*
 * o nó que compõe a pilha é formado por um valor e um
 * ponteiro para o elemento que estará abaixo dele
 * sendo que o último elemento aponta para NULO.
 */
struct node_stack {
	int value;
	node_s *bellow;
};

/*
 * guarda o nó que contém o topo e o tamanho atual da 
 * pilha.
 */
struct stack {
	node_s *top;
	int size;
};

```

# Stack TDA

```c
/*
 * create_stack aloca memória para uma pilha, aponta
 * o topo dela para NULO e inicia o tamanho dela com 0,
 * depois, retorna a pilha criada.
 */
stack *create_stack();

/*
 * create_node_s aloca memória para um nó da pilha 
 * adicionando nele o valor passado por parâmetro e 
 * apontando seu ponteiro para baixo para NULO.
 */
node_s *create_node_s(int value);

/*
 * push insere um valor no topo da pilha.
 */
void push(stack *s, int value);

/*
 * pop remove o valor que está no topo da pilha se ela 
 * não estiver vazia.
 */
int pop(stack *s);

/*
 * peek retorna o valor que está no topo da pilha, sem 
 * o remover dela.
 */
int peek(stack *s);

/*
 * is_empty retorna 1 se a pilha está vazia e 0 se ela 
 * não estiver.
 */
int is_empty(stack *s);

/*
 * stack_size retorna o tamanho atual da pilha.
 */
int stack_size(stack *s);
```