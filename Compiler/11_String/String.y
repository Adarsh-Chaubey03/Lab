%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token A B

%%

input:
    S '\n'  { printf("Valid string\n"); }
;

S:
    A S B
    | /* empty */
;

%%

void yyerror(const char *s) {
    printf("Invalid string\n");
}

int main() {
    printf("Enter string: ");
    yyparse();
    return 0;
}
