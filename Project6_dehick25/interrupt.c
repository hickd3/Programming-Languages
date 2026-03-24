/*
*Dean Hickman
*CS333
*interrupt.c
*5/21/24
*
*
*/


/*This program shows how to interrupt a signal using ctrl-c.*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // predefined signal constants, we can define our own but the standard package has what we need

  
//SIGNIT handler, user generated
void handler(int sig){
    printf("\nInterrupted!\n");
    exit(0);
}

int main( int argc, char *argv[]){
    //infinite loop, interrupt with ctrl-c
    signal(SIGINT, handler);
    while (1) ;
    return 0;
}