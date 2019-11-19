#ifndef _INTEGER_LIST_
#define _INTEGER_LIST_

#include<stdbool.h>

typedef struct node node;
struct node {
	void *value;
	node *next;
};

typedef struct list list;
struct list {
	node *first;
	int length;
};

//Constructeurs
list* newList();
node* newNode();

void printList(list* myList);
void addToList(int n, list* l);

/*
* Add value to list
* @param list The list we add the element to
* @param value The value to add
*/
int add(list* list, void *value);
int rm(list* list, int index)

#endif
