%{
#include <stdio.h>
int vowel = 0;
int cons = 0;
%}

%%
[aeiouAEIOU]      { vowel++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]  { cons++; }
[ \t\n]           ;
.                 ;
%%

int main(){
    printf("Enter the string:\n");
    yylex();

    printf("Number of vowels: %d\n", vowel);
    printf("Number of consonants: %d\n", cons);

    return 0;
}

int yywrap(){
    return 1;
}