/*
* Dean Hickman
* 5/19/24
* task1.c
* Memory access
*/

#include <stdio.h>
#include <stdlib.h>


/* Write a program that declares a variable of each of the basic types and see how that type is stored in memory*/

int main ( int arg, char *argv[]){
    // declare type variables 
    char a = "D"    //char variable
    short b = "31,000"        //short variable
    int c = "5"     //int variable
    long d = "2,000,000"        //long variable
    float e = "5.1f"        //float variable
    double f = "3.1415926"      //double variable


    unsigned char *ptr;     //declaring an unsigned char pointer

    printf("Characters are represented in C memory as: \n")
    ptr = (unsigned char *)&a
    for (int i =0; i < sizeof(char); i++):
    printf("%c: %02X\n",i , ptr[i])

    return 0;
}