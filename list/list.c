#include "list.h"
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

node* newNode() {
	node* noeud = malloc(sizeof(node));
	noeud->value = 0;
	noeud->next = NULL;

	return noeud;
}

list* newList() {
	list* liste = malloc(sizeof(list));
	liste->length = 0;
	liste->first = newNode();

	return liste;
}

void printList(list* myList) {
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

void addToList(int n, list* l) {
	l->length++;
	node* currentNode = l->first;

	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}

	currentNode->value = n;
	currentNode->next = newNode();
}
