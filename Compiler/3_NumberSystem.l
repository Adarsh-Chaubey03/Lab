%{
#include <stdio.h>
%}

%%
0[xX][0-9a-fA-F]+    { printf("%s is Hexadecimal\n", yytext); }
0[bB][01]+           { printf("%s is Binary\n", yytext); }
0[0-7]+              { printf("%s is Octal\n", yytext); }
[0-9]+               { printf("%s is Decimal\n", yytext); }
[ \t\n]              ;
.                    ;
%%

int main()
{
    printf("Enter the numbers:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}