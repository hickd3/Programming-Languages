/*
* Dean Hickman
* CS333
*5/19/24
clite.yy
*/


/* Implement a parser for Clite */

%{
#include <stdio.h> 
%}

DIGIT [0-9] 
ID [a-zA-Z]   

%%      //start flex rule
//match integers
{DIGIT}* {
    printf("Integer - %s\n", yytext);
}
//match floats
{DIGIT}+"."{DIGIT}* {
    printf("Float - %s\n", yytext);
}
//match keywords
if|else|while|for|int|float {
    printf("Keyword - %s\n", yytext);
}
//match identifiers based on name
{ID} {
    printf("Identifier - %s\n", yytext);
}
//match assignment symbols
= {
    printf("Assignment\n");
}
//match comparison symbols
==|<|>|<=|>= {
    printf("Comparison - %s\n", yytext);
}
//match operator symbols
"+"|"-"|"*"|"/" {
    printf("Operator - %s\n", yytext);
}
//match braces
"{" {
    printf("Open-bracket\n");
}
"}" {
    printf("Close-bracket\n");
}
//match parentheses
"(" {
    printf("Open-paren\n");
}
")" {
    printf("Close-paren\n");
}
\n      //match new-lines
.       //match the rest of the characters
%%      //end flex rules







int main (int argc, char *argv[]){  //main method
    if (argc > 1) //if there is an argument of a length more than one 

    yyin = fopen (argv [1], "r"); //open the input file or string and read it character by character

    yylex();        //run flex

    return 0; //program runs an compiles successfully
}





