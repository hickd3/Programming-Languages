/*
*Dean Hickman
*CS333
*LinkedList.c
*5/21/24
*
*
*/

/*Create a generic linked list class in C.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


//creates a new LinkedList struct, initializes it, and returns it.
LinkedList *ll_create(){
    LinkedList *list = malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

//adds a node to the front of the list, storing the given data in the node
void ll_push(LinkedList *l, void *data){
    Node *newNode = malloc(sizeof(Node)); //add memory for a new node
    newNode->value = data; //newNode gets the value of in the data paramter
    //if the tail is null it gets newNode
    if(l->tail == NULL){
        l->tail = newNode;
    }
    //if the head is not empty reverse link the list
    if(l->head != NULL){
        l->head->prev = newNode;
    }
    //re-assign the head
    newNode->next = l->head;
    l->head = newNode;
    l->size += 1;
    return;
}

//removes the node at the front of the list and returns the associated data
void *ll_pop(LinkedList *l){
    if (l->head == NULL){
        printf("Popping an empty list?\n");
        exit(EXIT_FAILURE);
    }
    Node *prevHead = l->head; 
    void *output = prevHead->value;
    l->head = l->head->next; // new head is set to the next node
    l->head->prev = NULL; // new head previous is null so the head is in fact a head 
    l->size -= 1;
    free(prevHead);
    if(l->head == NULL){
        l->tail = NULL;
    }
    return output;
}

//adds a node to the end of the list, storing the given data in the node
void ll_append(LinkedList *l, void *data){
    Node* newNode = malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = NULL;
    //empty list? assign a head
    if(l->head == NULL){
        l->head = newNode;
    }
    //adjust the linkedlist forwards if the list is not empty 
    if(l->tail != NULL){
        l->tail->next = newNode;
    }
    //reassign the tail 
    newNode->prev = l->tail;
    l->tail = newNode;
    l->size += 1;
    return;
}

//removes the first node in the list whose data matches target given the comparison function. The function returns the pointer to the data in the removed node.
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)){
     Node* node = l->head;
    //empty list? return null value
    if (node == NULL){
        return node;
    }
    //for each not find a match
    while (node != NULL && !compfunc(node->value, target)) {
        node = node->next;
    }
    //if a node is not in the list return null
    if (node == NULL){
        return NULL;
    }
    if (node->prev != NULL){
        node->prev->next = node->next;
    } else {
        //emphasize head
        l->head = node->next;
    }
    if(node->next != NULL){
        node->next->prev = node->prev;
    } else{
        //emohasize tail
        l->tail = node->prev;
    }
    void * output = node->value;
    free(node); //deallocate the memory associated with node
    l->size -= 1;
    return output;
}

//finds the first node in the list whose data matches target given the comparison function. The function returns the pointer to the data in the node. If the target is not in the list, then the function returns NULL.
void *ll_find(LinkedList *l, void *target, int (*compfunc)(void *, void *)){
     Node *curr = l->head;
    //iterate through the linkedlist until a match is found or the end of the list is reached
    while (curr != NULL) {
        if (compfunc(curr->value, target)) {
            //if a match is found return the curr pointer
            return curr->value;
        }
        curr = curr->next;
    }

    //no match is found? return NULL
    return NULL;
}

//returns the size of the list
int ll_size(LinkedList *l){
    return l->size;
}

//removes all of the nodes from the list, freeing the associated data using the given function
void ll_clear(LinkedList *l, void (*freefunc)(void *)){
    Node* node;
    while (l->head != NULL) { //iterate the linkedlist as long as the head is not NULL
        node = l->head; //set head as current node
        l->head = l->head->next; //move the head to the next node
        freefunc(node->value); //free the node value
        free(node); //free the node memory allocation
    }
    l->head = NULL; //set the head to NULL
    l->tail = NULL; //set the tail to NULL
    l->size = 0; //set the size to 0
    return;
}

//traverses the list and applies the given function to the data at each node
void ll_map(LinkedList *l, void (*mapfunc)(void *)){
    Node* node = l->head;
    while (node != NULL) { //iterate through the linkedlist
       mapfunc(node->value);// apply map function to the node value
       node = node->next; //move to the next node
    }
    return;
}

