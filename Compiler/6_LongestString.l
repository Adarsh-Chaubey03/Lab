%{
#include <stdio.h>
#include <string.h>

char longest[100];
int max = 0;
%}

%%

[a-zA-Z]+ {
             int len = yyleng;

             if (len > max) {
                       max = len;
                       strcpy(longest, yytext);
               }
            }

[ \t\n]     ;  
.           ;         

%%

int main()
{
    printf("Enter the string:\n");
    yylex();

    printf("Longest word: %s\n", longest);
    printf("Length: %d\n", max);

    return 0;
}

int yywrap()
{
    return 1;
}