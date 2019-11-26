#ifndef _LIST_
#define _LIST_

#include <stdbool.h>

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
list* new_list();
node* new_node();

void print_list(list* myList);

/*
* Add value to list
* @param list The list we add the element to
* @param value The value to add
*/
int add_to_list(list* list, void *value);

/*
* Remove the value at index
* @param list The list we remove the element from
* @param index The index of the value to remove
*/
int rm_from_list(list* list, int index)

#endif /* define _LIST_ */
