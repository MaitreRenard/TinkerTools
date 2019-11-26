#include "list.h"
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

node* new_node() {
	node* n = malloc(sizeof(node));
	n->value = 0;
	n->next = NULL;

	return n;
}

list* new_list() {
	list* l = malloc(sizeof(list));
	l->length = 0;
	l->first = newNode();

	return l;
}

void print_list(list* myList) {
	node* currentNode = myList->first;
	int index = 0;
	
	printf("[%d] ",myList->length);
	printf("[ ");

	while (currentNode->next != NULL) {
		printf("%d ",currentNode->value);
		currentNode = currentNode->next;
		index++;
	}

	printf("]");
}

void add_to_list(list* l, int n) {
	l->length++;
	node* currentNode = l->first;

	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}

	currentNode->value = n;
	currentNode->next = new_node();
}

void rm_from_list(list* l, int index) {
	if (index > l->length - 1 || index <= 0) {
		//Change behavior
		exit(1);
	} else {
		int i = 0;

		while (i < index - 1)

		l->length--;
	}
}
