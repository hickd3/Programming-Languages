/* The following code, START to FINISH, was provided by Max Bender. It has chnaged to accomodate my code additions. Advise this as a citation of the materials.*/


///////////////////START///////////////////////////

/**
 * @file BankExample.c
 * @author Max Bender
 * @date 2024-01-22
 *
 * A goofy example to demonstrate need for care when managing strings in C.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arg, char *argv[])
{
    /**
     * This creates a definition for the struct Account.
     *
     * Note that balance (an int) is saved after name in memory.
     */
    typedef struct Account
    {
        char name[10];
        int balance;
    } Account;

    printf("Please input your name for a new bank account: ");
    Account newAccount = {"", 0};

    /**
     * The following line reads input from the terminal.
     *
     * One could have simply done: scanf("%s", newAccount.name), but this would 
     * include the newline character at the end of the line. The [^\n] tells the
     * program to only read as much until a newline character is encountered. 
     */
    scanf("%[^\n]s", newAccount.name);
    printf("Thank you %s, your new account has been initialized with balance %d.",
           newAccount.name, newAccount.balance);
///////////////////FINISH///////////////////////////
  
  
  
  printf("\nThis is the memory location of the name field: \n ");
    for (int i = 0; i < sizeof(newAccount); i++){
        printf("%p: %02X\n", (void* )&newAccount.name + i, ((unsigned char *)&(newAccount))[i]);
        }

           return 0;        //the code runs and compiles successfully.
}



