/*
* Dean Hickman
* 5/19/24
* task3.c
* Memory Allocation
*/

#include <stdio.h>
#include <stdlib.h>

/* Write a program that repeatedly allocates small 
* amount of memory that goes on for a long time
*/

int main (int argc,  char *argv[]){
    int* x;     //declare an int pointer
    for (int i=0; i >= 0; i++){         //no stopping condition 
        x = (int*)malloc(10 * sizeof(int)); //allocate memory for the size of 10 integers. Have that pointer cast to int*. x gets the value of int* 
        free(x);        //allows the memory to be freed before it its allocated again. Toggle this to see a memory leak
    }

    return 0; 
}