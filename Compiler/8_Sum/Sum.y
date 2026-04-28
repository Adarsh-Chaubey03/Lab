%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(const char *s);
int yylex();
%}

%token NUMBER

%%
input:
    input line
    | /* empty */
    ;

line:
    expr '\n'   { printf("Result = %d\n", $1); }
    ;

expr:
    expr '+' term   { $$ = $1 + $3; }
    | term          { $$ = $1; }
    ;

term:
    NUMBER          { $$ = $1; }
    ;
%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

int main() {
    printf("Enter expression:\n");
    yyparse();
    return 0;
}
