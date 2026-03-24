/*
*Dean Hickman
*CS333
*cstk.h
*5/20/24
*
*/

#ifndef cstk_h
#define cstk_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stack 
{
	int *data; // this is a pointer to the start of the data for the stack
	int *top; // this will point to the next place to insert in the stack
	int capacity; // this is the maximal size of the stack
} Stack;

Stack *stk_create(int capacity); // creates a Stack with a maximal capacity specified by the int value 

int stk_empty(Stack *); //checks if stack is empty treated as boolean with 1 being empty 

int stk_full(Stack *); //checks if stack is full treated as a traditional boolean 

void stk_push(Stack *, int); //adds a new value to the top of the stack if there is space, does nothing if there isn't

int stk_peek(Stack *); //returns the value on the top of the stack if such a value exists

int stk_pop(Stack *);  //removes and returns the value on the top of the stack if such a value exists

void stk_display(Stack *, int); //prints out the list in the reverse order if the int value is 1 otherwise the list stays in the original order

void stk_destroy(Stack *); //frees up the memory

Stack *stk_copy(Stack *); // copies the contents into another Stack of the same maximal size of and returns it
#endif