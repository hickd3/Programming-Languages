/*
* Dean Hickman
* CS333
*5/19/24
*string.yy
*/

/*This program should parse an input file/string and count the number of rows, characters, and vowels.*/
%{
#include <stdio.h>

int row = 0, letters = 0, vowels = 0;   //declare global variables to count the line number, character count, and vowel count
%}

%%      //start flex rules 
\n  {row++;}    // rule: match newline and increment the row count by one 
[aeiouAEIOU] {vowels++; letters++;}     //rule: match vowels and increment the vowel + character count by one 
.   {letters++;}        //rule: match every character and icrement the character count 
%%      //finish flex rules

int main (int argc, char *argv[]){      //main method
    if (argc > 1)       //if there is an argument of a length more than one 

    yyin = fopen(argv[1], "r"); //open the input file or string and read it character by character

    yylex();    //call flex

    row++; 
    
    printf("Number of lines in the file: %i \n", row);   //print the number of lines in the file
    printf("Number of characters in the file: %i \n", letters); //print the number of characters in the file 
    printf("Number of vowels in the file: %i \n", vowels);      //print the number of vowels 


    return 0;   //program compiles and runs successfully
}

