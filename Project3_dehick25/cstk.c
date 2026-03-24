
/*
*Dean Hickman
*CS333
*cstk.c
*5/20/24
*
*/

/*Implementation of the basic functions declared in the cstk.h file*/
#include "cstk.h"

// creates a Stack with a maximal capacity specified by the int value 
Stack *stk_create(int capacity){ 
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = stack->data = (int *)malloc(capacity * sizeof(int));
    return stack;
} 

//checks if stack is empty treated as boolean with 1 being empty
int stk_empty(Stack *O){
    return O->top == O->data;
}  

//checks if stack is full treated as a traditional boolean 
int stk_full(Stack *O){
    return O->top - O->data == O->capacity;
}

//adds a new value to the top of the stack if there is space, does nothing if there isn't
void stk_push(Stack * O, int val){
    if (!stk_full(O))
        *O->top++ = val;
    else
        printf("Warning: Cannot push, no space available!\n");
}

//returns the value on the top of the stack if such a value exists
int stk_peek(Stack *O){
    if (stk_empty(O)) {
        printf("Warning: Cannot peek, no objects in stack.\n");
        return 0;
    }
    return *(O->top - 1);
}

//removes and returns the value on the top of the stack if such a value exists
int stk_pop(Stack *O){
    if (stk_empty(O)) {
        printf("Warning: Cannot pop, no objects in the stack.\n");
        return 0;
    }
    return *--O->top;
} 

//prints out the list in the reverse order if the int value is 1 otherwise the list stays in the original order
void stk_display(Stack *O, int reverse){
    if (reverse == 1) {
        for (int *ptr = O->top - 1; ptr >= O->data; ptr--)
            printf("%d ", *ptr);
    } else {
        for (int *ptr = O->data; ptr < O->top; ptr++)
            printf("%d ", *ptr);
    }
    printf("\n");
}


//frees up the memory
void stk_destroy(Stack *O){
    free(O->data);
    free(O);
} 

//makes duplicate stack
Stack *stk_copy(Stack *O){
     Stack *duplicate = stk_create(O->capacity);
    duplicate->top = duplicate->data + (O->top - O->data);
    memcpy(duplicate->data, O->data, (O->top - O->data) * sizeof(int));
    return duplicate;
} 