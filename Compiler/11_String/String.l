%{
#include "y.tab.h"
%}

%%
a       { return A; }
b       { return B; }
\n      { return '\n'; }
[ \t]   ;   // ignore spaces
.       { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
