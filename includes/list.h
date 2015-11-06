/*
 * list.h
 *
 *  Created on: 17 Nov 2014
 *      Author: jack
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>

typedef struct link {
	char item;
	struct link *next;
} link;

typedef struct linked_list {
	link *head;
	size_t size;
} linked_list;

linked_list* create_list();
int add_list_item(linked_list *list, char item);
int delete_list_item(linked_list *list, link *item);
link *find_list_item(linked_list *list, char item);
void print_list(linked_list *list);
void delete_list(linked_list *list);

#endif /* LIST_H_ */
