#ifndef _LIST_H
#define _LIST_H

typedef struct list_node {
	void *data;
	struct list_node *next;
} list_node;

typedef struct llist {
	int (*CmpFunc)(list_node*,void*);
	list_node *node;
} llist;

/* linked list */
llist* list_create(int (*CmpFunc)(list_node*,void*),void *data);
void list_destroy(llist *list);
list_node* list_node_create(void *data);
void list_node_destroy(list_node *node);
list_node* list_insert_after(list_node *node, void *data);
list_node* list_insert_beginning(llist *l, void *data);
list_node* list_insert_end(llist *l, void *data);
void list_remove(llist *l, list_node *node);
//void list_remove_by_data(list_node **list, void *data);
list_node* list_find_node(llist *l, list_node *node);
list_node* list_find_by_data_ptr(llist *l, void *data);
list_node* list_find(list_node *list, int(*func)(list_node*,void*), void *data);

/* Make the linked list a stack too! */
void *list_pop(llist *l);

#define list_remove_by_data(l, d) list_remove(l, list_find_by_data(l, d))
#define list_find(l, d) list_find_by_data(l, d)
#define list_insert(l, d) list_insert_end(l, d)

#endif

