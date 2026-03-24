/*
*Dean Hickman
*CS333
*wordCounter.h
*5/21/24
*
* with help from Lucy Barest
*/

#ifndef wordCounter
#define wordCounter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define MAX_WORD_LENGTH 100

typedef struct WordCounter {
    // File object
    FILE *fptr;
    // File path
    char path[100];
    // Linked list of distinct words and their frequencies
    LinkedList *words_list;
} WordCounter;

WordCounter *wc_create(); //create the object
void wc_read(WordCounter *wc, char *path); //read filename from commandline
void wc_print(WordCounter *wc); //print top 20 words and their frequencies in descending order
void wc_clear(WordCounter *wc); //clear the obkect

#endif