/*
* Dean Hickman
* 5/19/24
* task2.c
* Stack Access
*/

#include <stdio.h>
#include <stdlib.h>

/*Write a program that allows you to see where values are stored on the stack */

int main (int arg, char *argv[]){

 // declare type variables 
    char a = 'd';   //char variable
    short b = 31000;       //short variable
    int c = 5;     //int variable
    long d = 2000000;       //long variable
    float e = 5.1f;        //float variable
    double f = 3.1415926;     //double variable


    unsigned char *ptr;     //create a variable that is an unsigned char pointer
    ptr = &ptr;      //assign the pointer variable its own memory location
    

    for (int i= 0; i>=0; i++){      //looping without stopping condition
        printf("%d: %02X\n ", i, ptr[i]);       //print the location of each byte in the string format 
    }
    
    return 0;       //program complies and runs successfully
}