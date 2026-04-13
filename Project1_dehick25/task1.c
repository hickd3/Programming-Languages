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
    char a = 'd';   //char variable
    short b = 31000;       //short variable
    int c = 5;     //int variable
    long d = 2000000;       //long variable
    float e = 5.12;        //float variable
    double f = 3.1415926;     //double variable


    unsigned char *ptr;     //declaring an unsigned char pointer
        //the format for each loop is computationally the same, the only thing that changes is the dataype
    printf("Characters are represented in C memory as: \n");
    ptr = (unsigned char *)&a;      //pointer gets the address of the variable and is cast to an unsigned char *
    for (int i =0; i < sizeof(char); i++){      //loop through the bytes in the variable
        printf("%d: %02X\n", i, ptr[i]);        //print the memory location of each byte in the memory location
    }
    
    printf("Shorts are represented in C memory as: \n");
    ptr = (unsigned char *)&b;
    for (int i =0; i < sizeof(short); i++){
        printf("%d: %02X\n", i, ptr[i]);
    }
    
    printf("Integers are represented in C memory as: \n");
    ptr = (unsigned char *)&c;
    for (int i =0; i < sizeof(int); i++){
        printf("%d: %02X\n", i, ptr[i]);
    }
    
    printf("Longs are represented in C memory as: \n");
    ptr = (unsigned char *)&d;
    for (int i =0; i < sizeof(long); i++){
        printf("%d: %02X\n", i, ptr[i]);
    }
    
    printf("Floats are represented in C memory as: \n");
    ptr = (unsigned char *)&e;
    for (int i =0; i < sizeof(float); i++){
        printf("%d: %02X\n", i, ptr[i]);
    }

    printf("Doubles are represented in C memory as: \n");
    ptr = (unsigned char *)&f;
    for (int i =0; i < sizeof(double); i++){
        printf("%d: %02X\n", i, ptr[i]);
    }
    
    

    return 0;       //program complies and runs successfully
}

