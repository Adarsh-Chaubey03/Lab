%{
#include <stdio.h>
%}

%%
[0-9]+              { printf("NUM\n"); }

"if"                { printf("IF\n"); }
"then"              { printf("THEN\n"); }
"else"              { printf("ELSE\n"); }
"while"             { printf("WHILE\n"); }

[a-zA-Z][a-zA-Z0-9]* { printf("ID\n"); }

"<"|">"             { printf("RELOP\n"); }

"("                 { printf("BRACKET\n"); }
")"                 { printf("BRACKET\n"); }

[ \t\n]             ;   /* ignore whitespace */

.                   { printf("INVALID\n"); }

%%

int yywrap(){
    return 1;
}

int main()
{
    printf("Enter the string: ");
    yylex();
    return 0;
}




/*  How to Run ?

lex A_PrintToken.l
gcc lex.yy.c -o A_PrintToken
./A_PrintToken
 

*/  
