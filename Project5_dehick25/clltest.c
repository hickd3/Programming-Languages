/*
        Bruce Maxwell
        Fall 2012
        CS 333

        Linked list test function
 */

/*
*Dean Hickman
*CS333
*clltest.c
*5/21/24
*
*
*/

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

// function that prints an integer
void printInt(void *i) {
    int *a = (int *)i;

    printf("value: %d\n", *a);
}
// function that prints a double
void printDouble(void *d) {
    double *b = (double *)d;
    printf("Double value: %.4f\n", *b);
}

// function that squares an integer
void squareInt(void *i) {
    int *a = (int *)i;

    *a = *a * *a;
}

// function that cubes a double
void cubeDouble(void *d) {
    double *b = (double *)d;
    *b = (*b) * (*b) * (*b);
}

// function that compares two integers and returns 1 if they are equal
int compInt(void *i, void *j) {
    int *a = (int *)i;
    int *b = (int *)j;

    return (*a == *b);
}

// function that compares two doubles and returns 1 if they are equal
int compDouble(void *p, void *q) {
    double *a = (double *)p;
    double *b = (double *)q;
    return (*a == *b);
}

// test function for the various linked list functions
 int main(int argc, char *argv[]) {
    LinkedList *l_int;
    LinkedList *l_double;
    int *a;
    double *b;
    int *target_int;
    double *target_double;
    int i;

    // create a list
    l_int = ll_create();

    // push data on the list
    for (i = 0; i < 20; i += 2) {
        a = malloc(sizeof(int));
        *a = i;

        ll_push(l_int, a);
    }

    // printing the list and testing map
    printf("After initialization\n");
    ll_map(l_int, printInt);

    ll_map(l_int, squareInt);

    printf("\nAfter squaring\n");
    ll_map(l_int, printInt);

    // testing removing data
    target_int = malloc(sizeof(int));

    *target_int = 16;
    a = ll_remove(l_int, target_int, compInt);
    if (a != NULL)
        printf("\nremoved: %d\n", *a);
    else
        printf("\nNo instance of %d\n", *target_int);

    *target_int = 11;
    a = ll_find(l_int, target_int, compInt);
    if (a != NULL)
        printf("\nFound: %d\n", *a);
    else
        printf("\nNo instance of %d\n", *target_int);
    a = ll_remove(l_int, target_int, compInt);
    if (a != NULL)
        printf("\nremoved: %d\n", *a);
    else
        printf("\nNo instance of %d\n", *target_int);

    printf("\nAfter removals\n");
    ll_map(l_int, printInt);

    // testing appending data
    ll_append(l_int, target_int);

    printf("\nAfter append\n");
    ll_map(l_int, printInt);

    // test clearing
    ll_clear(l_int, free);

    printf("\nAfter clear\n");
    ll_map(l_int, printInt);

    // rebuild and test append and pop
    for (i = 0; i < 5; i++) {
        a = malloc(sizeof(int));
        *a = i;
        ll_append(l_int, a);
    }

    printf("\nAfter appending\n");
    ll_map(l_int, printInt);

    a = ll_pop(l_int);
    printf("\npopped: %d\n", *a);
    free(a);

    a = ll_pop(l_int);
    printf("popped: %d\n", *a);
    free(a);

    printf("\nAfter popping\n");
    ll_map(l_int, printInt);

    printf("\nList size: %d\n", ll_size(l_int));

    // create a list
    l_double = ll_create();

    // push data on the list
    for (i = 0; i < 20; i += 2) {
        b = malloc(sizeof(int));
        *b = i;

        ll_push(l_double, b);
    }

    // printing the list and testing map
    printf("After initialization\n");
    ll_map(l_double, printDouble);

    ll_map(l_double, cubeDouble);

    printf("\nAfter cubing\n");
    ll_map(l_double, printDouble);

    // testing removing data
    target_double = malloc(sizeof(double));

    *target_double = 3.1415;
    b = ll_remove(l_double, target_double, compDouble);
    if (b != NULL)
        printf("\nremoved: %.4f\n", *b);
    else
        printf("\nNo instance of %.4f\n", *target_double);

    *target_double = 2.7123;
    b = ll_find(l_double, target_double, compDouble);
    if (b != NULL)
        printf("\nFound: %.4f\n", *b);
    else
        printf("\nNo instance of %.4f\n", *target_double);
    b = ll_remove(l_double, target_double, compDouble);
    if (b != NULL)
        printf("\nremoved: %.4f\n", *b);
    else
        printf("\nNo instance of %.4f\n", *target_double);

    printf("\nAfter removals\n");
    ll_map(l_double, printDouble);

    // testing appending data
    ll_append(l_double, target_double);

    printf("\nAfter append\n");
    ll_map(l_double, printDouble);

    // test clearing
    ll_clear(l_double, free);

    printf("\nAfter clear\n");
    ll_map(l_double, printDouble);

    // rebuild and test append and pop
    for (i = 0; i < 5; i++) {
        b = malloc(sizeof(double));
        *b = i;
        ll_append(l_double, b);
    }

    printf("\nAfter appending\n");
    ll_map(l_double, printDouble);

    b = ll_pop(l_double);
    printf("\npopped: %.4f\n", *b);
    free(b);

    b = ll_pop(l_double);
    printf("popped: %.4f\n", *b);
    free(b);

    printf("\nAfter popping\n");
    ll_map(l_double, printDouble);

    printf("\nList size: %.4d\n", ll_size(l_double));

    return (0);
}