/*
 * list.c
 *
 *  Created on: 17 Nov 2014
 *      Author: jack
 */

#include <list.h>
#include <stddef.h>
#include <stdio.h>

linked_list* create_list() {
	linked_list* list = malloc(sizeof(linked_list));
	list->head = NULL;
	list->size = 0;
	return list;
}

int add_list_item(linked_list *list, char item) {
	if (find_list_item(list, item)) {
		return 0;
	}
	link *new = malloc(sizeof(link));
	new->item = item;
	new->next = list->head;
	list->head = new;
	list->size++;
	return 1;
}
int delete_list_item(linked_list *list, link *item) {
	if (list->head == item) {
		list->head = item->next;
		free(item);
		list->size--;
		return 1;
	} else {
		link *prev = list->head;
		link *next = prev->next;
		while (next != NULL) {
			if (next == item) {
				prev->next = next->next;
				free(item);
				list->size--;
				return 1;
			}
			prev = next;
			next = next->next;
		}
		return 0;
	}
}
link* find_list_item(linked_list *list, char item) {
	link *temp = list->head;
	while (temp != NULL) {
		if (temp->item == item) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void print_list(linked_list *list) {
	link *temp = list->head;
	while (temp != NULL) {
		printf("%c", temp->item);
		printf(", ");
		temp = temp->next;
	}
	printf("\n");
}

void delete_list(linked_list *list) {
	link *head = list->head;
	link *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	free(list);
}

