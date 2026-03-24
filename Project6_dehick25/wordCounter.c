/*
*Dean Hickman
*CS333
*wordCounter.h
*5/21/24
*
*with guidance from Lucy Barest
*/

#include "wordCounter.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


typedef struct KeyValuePair {
    char * word;
    int num;
} KeyValuePair;

WordCounter *wc_create(){
    WordCounter *counter = malloc(sizeof(WordCounter));
    if (counter == NULL) {
        printf("Cannot allocate memory for wordCounter.\n");
        return NULL;
    }
    counter->words_list = ll_create(); //initialize a linked list of words
    if (counter->words_list == NULL) {
        printf("Linked list for words could not be created.\n");
        free(counter); //free the allocated memory for the object counter
        return NULL;
    }
    return counter;
}
int word_compare(void *a, void *b) { //compare two words
    return strcmp((char *)a, (char *)b) == 0;
}

int comparatorForFind(void *a, void *b){ //use a comparator to find unique key value pairs
    KeyValuePair *dict = (KeyValuePair *)a;
    
    char *target = (char*) b;
    
    return strcmp(dict->word, target) == 0;
}
void wc_read(WordCounter *wc, char *path){
    //open and read file
    wc->fptr = fopen(path, "r");

    //if file can't be opened let us know
    if (wc->fptr == NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    
    while (fscanf(wc->fptr, "%s", word) != EOF)
    {
        //words to lowercase
        for(int i = 0; i < strlen(word); i++){
            word[i] = tolower(word[i]);
        }

        //no punctuation the counter should be case-insensitive
        int len = strlen(word);
        if (ispunct(word[len - 1])){
            word[len - 1] = '\0';
        }

        //look for word in the lisr
        KeyValuePair *dict = ll_find(wc->words_list, word, comparatorForFind);
        // if you find a word for the first time add it to the list otherwise increase the frequency count
        if (dict != NULL) {
            dict->num++;
        } else {
            char *newWord = malloc((strlen(word) + 1) * sizeof(char));
            if (newWord == NULL) {
                printf("Cannot allocate memory for word.\n");
                fclose(wc->fptr); //close the file
                return;
            }
            strcpy(newWord, word);
            KeyValuePair *newDict = malloc(sizeof(KeyValuePair));
            newDict->word = newWord;
            newDict->num = 1;
            ll_append(wc->words_list, newDict); //add the key value pair to the list
        }
    }

    fclose(wc->fptr);
}
int dict_compare(const void *a, const void *b) {
    const KeyValuePair *dict1 = *(const KeyValuePair **)a;
    const KeyValuePair *dict2 = *(const KeyValuePair **)b;
    return dict2->num - dict1->num; //compare the frequencies 
}

void wc_print(WordCounter *wc) {

    //make the LinkedList and array so that we can sort it
    KeyValuePair **array = (KeyValuePair **)malloc(ll_size(wc->words_list) * sizeof(KeyValuePair *));
    if (array == NULL) {
        printf("Error: Memory allocation failed for array.\n");
        return;
    }

    Node *current = wc->words_list->head;
    int index = 0;
    while (current != NULL && index < ll_size(wc->words_list)) {
        array[index++] = (KeyValuePair *)current->value;
        current = current->next;
    }

    // sort our so called dictionary by frquency in descendign order
    qsort(array, index, sizeof(KeyValuePair *), dict_compare);

    //this is wc_print()
    int print_count = 0;
    for (int i = 0; i < index && print_count < 20; i++) {
        printf("%-15s => %d\n", array[i]->word, array[i]->num);
        print_count++;
    }

    
    free(array); //de-allocate the memory for the array
}
void wc_clear(WordCounter *wc) {
    if (wc == NULL) {
        printf("Encountered NULL pointer for wordCounter\n");
        return;
    }
   
    ll_clear(wc->words_list); //clear the list of words
}
