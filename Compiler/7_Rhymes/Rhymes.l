%{
#include <stdio.h>
#include "y.tab.h"
%}

%%

chik    { printf("CHIK "); return CHIK; }
chek    { printf("CHEK "); return CHEK; }
india   { printf("INDIA "); return INDIA; }

[ \t\n] ;
.       { return yytext[0]; }

%%

int yywrap() {
    return 1;
}


/* How to Run ?

yacc -d rhyme.y
lex rhyme.l
gcc y.tab.c lex.yy.c -o out  
./a.out                     or ./rhyme 

Enter input:
chik chek india
CHIK CHEK INDIA Valid rhyme

chek chik india
CHEK Invalid rhyme
*/