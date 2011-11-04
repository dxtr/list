#include <stdlib.h>
#include <string.h>
#include "list.h"

/* Creates a list node and returns it
 * Arguments: The data the list will contain
 */
list_node* list_create(void *data)
{
	list_node *l = malloc(sizeof(list_node));
	if (l != NULL) {
		l->next = NULL;
		l->data = data;
	}

	return l;
}

void list_destroy(list_node **list)
{
	if (list == NULL) return;
	while (*list != NULL) {
		lust_remove(list, *list);
	}
}

/* Creates a list node and inserts it after the specified node
 * Arguments: A node to insert after and the data the new node will contain
 */
list_node* list_insert_after(list_node *node, void *data)
{
	list_node *new_node = list_create(data);
	if (new_node != NULL) {
		new_node->next = node->next;
		node->next = new_node;
	}

	return new_node;
}

/* Creates a new list node and inserts it in the beginning of the list
 * Arguments: The list the node will be inserted to and the data the node will
 * contain
 */
list_node* list_insert_beginning(list_node *list, void *data)
{
	list_node *new_node = list_create(data);
	if (new_node != NULL) { new_node->next = list; }
	return new_node;
}

/* Creates a new list node and inserts it at the end of the list
 * Arguments: The list the node will be inserted to and the data the node will
 * contain
 */
list_node* list_insert_end(list_node *list, void *data)
{
	list_node *new_node = list_create(data);
	if (new_node != NULL) {
		for(list_node *it = list; it != NULL; it = it->next) {
			if (it->next == NULL) {
				it->next = new_node;
				break;
			}
		}
	}
	return new_node;
}

/* Removes a node from the list
 * Arguments: The list and the node that will be removed
 */
void list_remove(list_node **list, list_node *node)
{
	list_node *tmp = NULL;
	if (list == NULL || *list == NULL || node == NULL) return;

	if (*list == node) {
		*list = (*list)->next;
		free(node);
	} else {
		tmp = *list;
		while (tmp->next && tmp->next != node) tmp = tmp->next;
		if (tmp->next) {
			tmp->next = node->next;
			free(node);
		}
	}
}

void list_remove_by_data(list_node **list, void *data)
{
	if (list == NULL || *list == NULL || data == NULL) return;
	list_remove(list, list_find_by_data(*list, data));
}

list_node* list_find_node(list_node *list, list_node *node)
{
	if (list == NULL || node == NULL) goto ret;

	while (list) {
		if (list == node) return list;
		list = list->next;
	}
ret:
	return NULL;
}

list_node* list_find_by_data(list_node *list, void *data)
{
	if (list == NULL || data == NULL) goto ret;

	while (list) {
		if (list->data == data) return list;
		list = list->next;
	}

ret:
	return NULL;
}

list_node* list_find(list_node *list, int(*func)(list_node*,void*), void *data)
{
	if (!func) goto ret;
	while(list) {
		if (func(list, data) > 0) return list;
		list = list->next;
	}
ret:
	return NULL;
}

