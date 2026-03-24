/** 
 * 
 * 
 * 
 * flex -o q2_file2.yy.c q2_file2.yy
 * gcc -o q2_file2 q2_file2.yy.c -ll

 */

 %%

[[:space:]]   printf( "space: |%s|\n", yytext );

%%
int main( int argc, char *argv[] ) {

    if (argc > 1)
        yyin = fopen( argv[1], "r" ); //where yylex reads its input 
        
    yylex(); // a function of flex that read input till it is exhausted
        
    return 0;
}