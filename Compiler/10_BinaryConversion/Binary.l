%{
#include "y.tab.h"
%}

%%
[0-1]    { yylval = yytext[0] - '0'; return DIGIT; }
\n       { return '\n'; }
[ \t]    ;   // ignore spaces
.        { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
