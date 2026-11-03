%{
#include <stdio.h>

int line = 1;
%}

%%
\n {line++;};
[\t\r] { /* ignore whitespace */ }
[a-zA-Z0-9+\-*/= ] {printf("%s\n", yytext);}
[^a-zA-Z0-9+\-*/= ] {printf("Error: illegal character '%s' at line %d\n", yytext, line);}

%%

int yywrap() { 
    return 1; 
}

int main() {
    yylex();
    return 0;
}
