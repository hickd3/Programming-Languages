/*
* Dean Hickman
* CS333
* 5/20/24
* task2.c
*
*
*/

/*Write a program that takes in an integer argument and returns its factorial value*/

#include <stdio.h>
#include <stdlib.h>


int factorial(int n){ //integer n is the argument 
    int result = 1, i;  // 1 is going to be the factorial result and i is the loop variable
    for (i = 2; i <= n; i++){ //factorials are calulated for integers greater than 2 
        result *= i;    //def of factorial
    }
    return result; //return the factorial
}

int main (int argc, char *argv[]){ //main method 
    if(argc != 2){ // there must be 2 command line arguments
        printf("Argument: %s <integer>\n", argv[0]); //if not print instruction s
        return 1; //error
    }
    //defining the factorial pointer
    int(*calc)(const int); 
    calc = &factorial;

    int N = strtol(argv[1], NULL, 10); // take the string to a long and call it N

    int result =(*calc)(N); // call the factorial function via pointer on the argument N
    printf("%d! is %d\n", N, result); // print the result in the proper format

    return 0; //the program runs and compiles successfully 
}