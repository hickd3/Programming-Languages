/*
*Dean Hickman
*CS333
*LinkedList.h
*5/21/24
*
*
*/

/*Create a basic linkedlist structure.*/
/*this file has been updated and differs from project 5*/

#ifndef linkedlist
#define linkedlist

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void * value;
    struct Node * prev;
    struct Node * next;
} Node;

typedef struct LinkedList {
    int size;
    Node *head;
    Node *tail;
} LinkedList;

//creates a new LinkedList struct, initializes it, and returns it.
LinkedList *ll_create();

//adds a node to the front of the list, storing the given data in the node
void ll_push(LinkedList *l, void *data);

//removes the node at the front of the list and returns the associated data
void *ll_pop(LinkedList *l);

//adds a node to the end of the list, storing the given data in the node
void ll_append(LinkedList *l, void *data);

//removes the first node in the list whose data matches target given the comparison function. The function returns the pointer to the data in the removed node.
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));

//finds the first node in the list whose data matches target given the comparison function. The function returns the pointer to the data in the node. If the target is not in the list, then the function returns NULL.
void *ll_find(LinkedList *l, void *target, int (*compfunc)(void *, void *));

//returns the size of the list
int ll_size(LinkedList *l);

//removes all of the nodes from the list, freeing the associated data using the given function
void ll_clear(LinkedList *l);

//traverses the list and applies the given function to the data at each node
void ll_map(LinkedList *l, void (*mapfunc)(void *));

#endif 