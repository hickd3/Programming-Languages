/*
* Dean Hickman
* CS333
*5/19/24
encode.yy
*/


/*Write a program that takes any character in a-z or A-Z and shifts it 13 spaces forward in the alphabet, with wraparound from z back to a. */

%%  //start rules for lexical analysis 
[a-zA-Z] {  //pattern matching 
    char ident = yytext[0]; // ident is the single character that appears in the string and matches the pattern
    char shift = ((ident +13 - 97) % 26) + 97; // shift the character 13 letters over, convert the character into an integer then sort it into the alphabet and then convert it back into a letter
    printf("%c\n", shift);      //print the new ordered charcters line by line 
    }
%%

int main (int argc, char * argv[]){    //main method 
    if (argc > 1) //if there is an argument of a length more than one 

    yyin  =fopen (argv[1], "r"); //open the input file or string and read it character by character

    yylex();    //call flex 
    
    return 0;   //program compiles and runs successfully
}

