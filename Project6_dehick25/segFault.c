/*
*Dean Hickman
*CS333
*segFault.c
*5/21/24
*
*
*/

/* This program demonstrates a segementation fault*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

  
//Segmentation fault caught by SIGSEVC.
void handler(int sig){
    printf("\nSegmentation fault caught. Exiting program.\n");
    exit(0);
}

int main(int argc, char *argv[]){
    signal(SIGSEGV, handler);
    printf("Create a bad behavior\n");
    char *ptr = 0;
    printf("Program continues after segmentation fault\n");
    return 0; //program runs and compiles successfully
}