
/*
 * Dean Hickman
 * CS333
 * task3.c
 * 5/20/24
 *  With help from Lucy Barest
 */


/* This program should draw the memory contents of the structure "Account".*/

#include "cstk.h"

typedef struct Account {
    char *name;
    int balance;
} Account;

int main() { 
    Stack *stack = stk_create(10); // create a stack with balance 10
    for (int i = 0; i < 5; i++) {
        int *x = (int *)malloc(sizeof(int));
        *x = i;
        stk_push(stack, x); // push this parameter onto the stack 
    }

    Account account = {"Max Bender", 10}; // account name is Max Bender
    stk_push(stack, &account); //push this structure onto the stack

    // MARK 1 - draw current contents of stack and relevant contents of heap
    //print the memory contents of the stack 
    printf("Stack:\n");
    for (void **ptr = stack->data; ptr < stack->top; ptr++) {
        if (*ptr != NULL) {
            if (ptr - stack->data < 5) {
                printf("   %p: %d\n", *ptr, **((int **)ptr));
            } else {
                Account *account = (Account *)*ptr;
                printf("   %p: Account {name: %s and balance: %d}\n", *ptr, account->name, account->balance);
            }
        }
    }
    //print the memory contents of the heap
    printf("Heap:\n");
    for (void **ptr = stack->data; ptr < stack->top; ptr++) {
        if (*ptr != NULL) {
            printf("   %p: ", *ptr);
            if (ptr - stack->data < 5) {
                printf("%d\n", **((int **)ptr));
            } else {
                Account *account = (Account *)*ptr;
                printf("Account {name: %s and  balance: %d}\n", account->name, account->balance);
            }
        }
    }

    
    stk_destroy(stack); //free the memory 

    return 0; //program runs and compiles successfully
}