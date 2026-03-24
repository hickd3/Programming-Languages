/*
* Dean Hickman
* CS333
*5/19/24
html.yy
*/

/*Write a program that strips an html file of tags, single-line comments, and extraneous whitespace */

%{
#include <stdio.h>

int fileTag = 0, fileLine = 0, fileComment = 0; //define global variables as integers interpret as boolean

%}


%%  //define flex rules
\<p     {fileTag = 1; fileLine = 1; } //match the beginnging of a paragraph, mark that we are in the html file and on a line of text 
\<!--  {fileComment = 1;}   //match the beggining of a comment line, mark that we have entered a comment
\-->    {fileComment = 0;}   //match the end of a comment line, mark that we have left the comment tag
\<      {fileTag = 1;}  //match the beggining of an html file, mark that we are in the html file
\>      {fileTag = 0; if (fileLine) {printf("\n\n");} fileLine = 0; fileComment = 0;}   //match the end of the html file, mark that we are no longer in the file or comment. If we are in a paragraph tag though we will print two new lines to maintain the format
[\t\n ]+ //match any kind of extraneous spacing 
.      {if (!fileTag && !fileComment) {printf("%s", yytext);}} //match any remaining characters that are not in thr file tag or comment. We format those characters as a string 

%%  //end flex rules

int main (int argc, char *argv[]){ //main method
    if (argc > 1)  // if the command line gets an argument greater than length one

    yyin = fopen( argv[1], "r"); // open the file named by the first parameter entered to the command line and read its contents

    yylex();    //run flex

    return 0;       //program runs and compiles successfully
}

