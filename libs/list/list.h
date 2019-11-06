#ifndef _INTEGER_LIST_
#define _INTEGER_LIST_

typedef struct node node;
struct node {
	int value;
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

#endif
