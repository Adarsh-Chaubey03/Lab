%{
#include <stdio.h>
#include <math.h>

int yylex();
void yyerror(const char *s);
int pos = 0;   // position for power calculation
%}

%token DIGIT

%%

input:
    expr '\n' { printf("Decimal = %d\n", $1); }
;

expr:
    expr DIGIT { $$ = $1 * 2 + $2; }
    | DIGIT    { $$ = $1; }
;

%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

int main() {
    printf("Enter binary number: ");
    yyparse();
    return 0;
}
