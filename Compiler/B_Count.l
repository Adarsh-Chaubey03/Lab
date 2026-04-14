%{
#include <stdio.h>

int lines = 0;
int words = 0;
int spaces = 0;
%}

%%
\n              { lines++; }
[ ]+            { spaces += yyleng; }
[^ \t\n]+       { words++; }
.               ;   /* ignore everything else */
%%

int main()
{
    printf("Enter text (Press Ctrl+D to stop):\n");
    yylex();

    printf("\nlines: %d\n", lines);
    printf("words: %d\n", words);
    printf("spaces: %d\n", spaces);

    return 0;
}

int yywrap()
{
    return 1;
}



/*  How to Run ?

lex B_Count.l
gcc lex.yy.c -o B_Count
.B_Count

*/  
