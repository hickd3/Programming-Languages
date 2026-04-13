/*
* Dean Hickman
* 5/19/24
* task4.c
* Struct Design
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Create a struct of at least 3 different data types to see how the compilier lays out memory for the variables */

int main (int argc, char *argv[]){

    struct Patient{
        /* The basic characterstics of the patient object. 
        Every patient will have a weight, an age, a sex and a WBC count.*/

        float Weight;        //a range of 4 bytes presenting a decimal. 0.00 to 1500.00lbs
        char  Sex;       //F = female, M = male, I = Intersex, a total of 1 byte
        int Age;         //a range of 4 bytes representing a whole number. 0 - 127
        short WBC;      //a range of 2 bytes representing a whole number. 0 - 20
        char Healthy[6];   // Boolean True or False
    };

    struct Patient sickKid;      //sickKid is a type of patient
    strcpy (sickKid.Healthy, "False");
    sickKid.Sex = 'M';     //sickKid is a male  
    sickKid.Weight = 37.01;        //sickKid has a weight of 37.01lbs this is low for a male his age  
    sickKid.WBC = 17;      //sickKid has a white bllod cell count of 17, this is high
    sickKid.Age = 8;        //sickKid is 8 years old
   


    unsigned char *ptr;         //declare a ptr variable that is type unsigned char *
    ptr= (unsigned char *)&(sickKid);       //the ptr gets the value of the memory locaton casted to an unsigned char *

    for (int i=0; i < sizeof(sickKid); i++){    //loop through every byte of sickKid 
        printf("%d: %02X\n", i, ptr[i]);        //print out each byte in sickKid

    }

    printf("The size of sickKid is:  %zu", sizeof(sickKid));        //print out the size of sickKid

    return 0; //the program compiles and runs successfully
}