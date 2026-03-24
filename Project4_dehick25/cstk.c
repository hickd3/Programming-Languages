
/*
 * Dean Hickman
 * CS333
 * cstk.c
 * 5/20/24
 * with help from Lucy Barest
 */

/* This program completes and builds on the work of the previous cstk.c file from project 3*/
#include "cstk.h"

//creates a Stack with a maximal capacity specified by the int value 
Stack *stk_create(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failure\n");
        exit(EXIT_FAILURE); //end the program
    }
    stack->data = (void **)malloc(capacity * sizeof(void *));
    if (stack->data == NULL) {
        printf("Memory allocation failure\n");
        free(stack);  // Free previously allocated memory before exit
        exit(EXIT_FAILURE);
    }
    stack->top = stack->data;
    stack->capacity = capacity;
    return stack;
}

//checks if stack is empty treated as boolean with 1 being empty
int stk_empty(Stack *stack) {
    return stack->top == stack->data;
}


//checks if stack is full treated as a traditional boolean
int stk_full(Stack *stack) {
    return (stack->top - stack->data) == stack->capacity;
}

//adds a new value to the top of the stack if there is space, does nothing if there isn't
void stk_push(Stack *stack, void *item) {
    if (stk_full(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    *(stack->top++) = item;
}

//returns the value on the top of the stack if such a value exists
void *stk_peek(Stack *stack) {
    if (stk_empty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return *(stack->top - 1);
}

//removes and returns the value on the top of the stack if such a value exists
void *stk_pop(Stack *stack) {
    if (stk_empty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return *(--stack->top);
}

//prints out the list in the reverse order if the int value is 1 otherwise the list stays in the original order
void stk_display(Stack *stack, int reverse) {
    int size = stk_size(stack);
    if (reverse) {
        for (int i = size - 1; i >= 0; i--) {
            printf("%p ", stack->data[i]);
        }
    } else {
        for (int i = 0; i < size; i++) {
            printf("%p ", stack->data[i]);
        }
    }
    printf("\n");
}

//frees up the memory
void stk_destroy(Stack *stack) {
    free(stack->data);
    free(stack);
}

//makes duplicate stack
Stack *stk_copy(Stack *stack) {
    Stack *new_stack = stk_create(stack->capacity);
    int size = stk_size(stack);
    for (int i = 0; i < size; i++) {
        new_stack->data[i] = stack->data[i];
    }
    new_stack->top = new_stack->data + size;
    return new_stack;
}

//return the number of items in the stack
int stk_size(Stack *stack) {
    return stack->top - stack->data;
}

//convert the stack into a string using the toString function on each item 
char *stk_toString(Stack *stack, char *(*toString)(void *)) {
    int size = stk_size(stack);
    int bufferSize = 20; // You can change the buffer size as needed
    char *result = (char *)malloc(bufferSize);
    if (result == NULL) {
        printf("Memory allocation failure\n");
        exit(EXIT_FAILURE);
    }
    result[0] = '\0'; // Result string initialization
    int resultLength = 0;

    for (int i = 0; i < size; ++i) {
        char *itemString = toString(stack->data[i]);
        int itemLength = strlen(itemString);

        // Does the buffer need to be resized?
        if (resultLength + itemLength + 2 > bufferSize) { //space by +2 if item is separated by comma
            bufferSize *= 2;
            result = realloc(result, bufferSize);
            if (result == NULL) {
                printf("Memory reallocation failure\n");
                exit(EXIT_FAILURE);
            }
        }

        //Add the string to result
        strcat(result, itemString);
        resultLength += itemLength;

        //Make a list if i isn't the last item by using a comma
        if (i != size - 1) {
            strcat(result, ", ");
            resultLength += 2;
        }

        free(itemString); //Free the item string
    }

    return result; //Return the result
}
