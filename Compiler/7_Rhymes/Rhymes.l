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
gcc lex.yy.c y.tab.c -o out          // gcc y.tab.c lex.yy.c -o out  // do this if you get an error: ld returned 1 exit status
./a.out

Enter input:
chik chek india
CHIK CHEK INDIA Valid rhyme

chek chik india
CHEK Invalid rhyme
*/