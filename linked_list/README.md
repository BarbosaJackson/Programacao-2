# checklist to TAD
  - create_linked_list [ :x: ]
  - create_node [ :x: ]
  - add_front [ :x: ]
  - add_back [ :x: ]
  - remove_node [ :x: ]
  - is_empty [ :x: ]
  - print_linked_list [ :x: ]
  - sort_list [ :x: ]

# Linked List struct

```c

typedef struct node node;
typedef struct list list;

struct node {
	int value;
	node *next;
}

struct list {
	node *head;
}

```

# Linked List TAD

```c

list *create_linked_list();
node *create_node(int value);
int is_empty(list *li);
void insert_front(list *li, int value);
void insert_back(list *li, int value);
int remove_element(list *li, int element);
void print_linked_list(list *li);

```