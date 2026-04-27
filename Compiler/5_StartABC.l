%{
#include <stdio.h>
int a_count = 0;
int b_count = 0;
int c_count = 0;
%}

%%
[aA][a-zA-Z]* { a_count++; }
[bB][a-zA-Z]* { b_count++; }
[cC][a-zA-Z]* { c_count++; }
[ \t\n] ;
. ;
%%

int main(){
    printf("Enter the text:\n");
    yylex();

    printf("No. of words starting with A: %d\n", a_count);
    printf("No. of words starting with B: %d\n", b_count);
    printf("No. of words starting with C: %d\n", c_count);

    return 0;
}

int yywrap(){
    return 1;
}