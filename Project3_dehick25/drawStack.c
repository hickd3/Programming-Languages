/*
 *Dean Hickman
 *CS333 
 *drawStack.c
 *5/20/24
 *
 */

//Code adapted from Stephanie Taylor and Max Bender


#include <stdio.h>
#include <stdlib.h>
#include "cstk.h"

int main (int argc, char **argv) {
    int *a = (int *)malloc( sizeof(int)*4 );
    int i;
    printf( "a is at %p\n", &a );
    printf( "i is at %p\n", &i );
    
    printf( "array starts at %p\n", a );
    for (i = 0; i < 4; i++) {
        a[i] = i*2;
    }
    
    // Mark 1 (first memory picture)
    printf("Heap:\n");
    //print the memory address and values of the objects stored in the heap
    printf("%p: %d\n", (void *)a, *a);
    printf("%p: %d\n", (void *)(a+1), *(a+1));
    printf("%p: %d\n", (void *)(a+2), *(a+2));
    printf("%p: %d\n", (void *)(a+3), *(a+3));
   
    printf("Stack:\n");
    //print the memory address and the values of the variables 
    printf("%p: %d\n", (void *)&i, i);
    printf("%p: %p\n", (void *)&a, (void *)a);
    
    free(a); // free the heap memory associated with array 
    // Mark 2 (second memory picture)
    //this code block is the same as the one above except we have freed the variable a
    printf("Heap:\n");
    printf("%p: freed\n", (void *)a);
    printf("Stack:\n");
    printf("%p: %d\n", (void *)&i, i);
    printf("%p: %p\n", (void *)&a, (void *)a);
    
    return 0;
}