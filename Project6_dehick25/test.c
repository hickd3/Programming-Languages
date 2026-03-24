/*
 * Dean Hickman
 * CS333 A
 * test.c
 *  5/21/24
 * 
 */

/*This program tests the wordCounter*/

#include <stdio.h>
#include <stdlib.h>
#include "wordCounter.h"

int main(int argc, char *argv[]){ //main method
    //is the filepath the command line argument?
    if (argc != 2) {
        printf("Please adhere to the following format: %s <file_path>\n", argv[0]);
        return 1; //program encountered an error
    }

  
    WordCounter *wc = wc_create(); //create a word count
    if (wc == NULL) {
        printf("Word counter could not be created.\n");
        return 1;
    }

   
    wc_read(wc, argv[1]); //read the file and count the words

    
    wc_print(wc); //print the top 20 words and their frequencies

    
    wc_clear(wc); //clear the wordCounter object, i.e. free the dyamically allocated memory 
    
   
    free(wc); //free the allocated memory for the wordCounter object

    return 0; //code runs and compiles successfully
}
