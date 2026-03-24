/*
 * Dean Hickman
 * CS333 
 * time.c
 * 5/24/24
 * 
 */

/* This program will find the avg time it takes to allocate and de-allocate memory*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]){
    printf("%-15s \t%-15s \t%-15s\n", "bytes", "mallocTime", "freeTime");
    
    int memory[] = {100 * sizeof(int), 10000 * sizeof(int), 1000000 * sizeof(int)}; //initialize memory sizes
    int memoryVal = sizeof(memory) / sizeof(memory[0]);

    //iterate over every m in each of the memory[] arrays
    for (int m = 0; m < memoryVal; m++) {
        int mem = memory[m];
        clock_t start, end;
        float timeMalloc = 0.0, timeFree = 0.0;

        //gather allocation data
        int allocations = 1000;
        for (int i = 0; i < allocations; i++) {
            void *ptr;
            
            //time the malloc for the first call
            if (i == 0) {
                ptr = malloc(mem);
                free(ptr); //free to avoid memory leak
                continue; //skip the time of the first call 
            }
            //time to malloc
            start = clock();
            ptr = malloc(mem);
            end = clock();
            timeMalloc += ((float)(end - start)) / CLOCKS_PER_SEC;
        
            //did malloc, malloc?  
            if (ptr == NULL) {
                printf( "Failed to allocate memory.\n");
                exit(EXIT_FAILURE);
            }
            //free the time
            start = clock();
            free(ptr);
            end = clock();
            timeFree += ((float)(end - start)) / CLOCKS_PER_SEC;
        }
        //compute avg time
        timeMalloc /= allocations;
        timeFree /= allocations;

        //display the times 
        printf("%-15d \t%-15f \t%-15f\n", mem, timeMalloc, timeFree);
    }

    return 0;
}
