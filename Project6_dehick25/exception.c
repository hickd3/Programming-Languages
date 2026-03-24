/*
*Dean Hickman
*CS333
*exception.c
*5/21/24
*
*
*/
/* This program handles floating point exceptions*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//Floating point exception caught by SIGFPE 
void handler(int sig){
    printf("\nFloating point exception. Please revise arithmetic\n");
    exit(0);
}

int main(int argc, char *argv[]){
    signal(SIGFPE, handler);
    printf("We don't like this arithmetic\n");
    //division by 0
    int a = 1;
    int b = 0;
    int result = a / b; //floating point exception
    printf("Program continued passed the floating point exception\n");
    return 0; //program runs and compiles successfully
}
