%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *);
%}

%token CHIK CHEK INDIA

%%

rhyme : sound place { printf("Valid rhyme\n"); }
      ;

sound : CHIK CHEK ;
place : INDIA ;

%%

int main() {
    return yyparse();
}

int yyerror(char *s) {
    printf("Invalid rhyme\n");
    return 0;
}