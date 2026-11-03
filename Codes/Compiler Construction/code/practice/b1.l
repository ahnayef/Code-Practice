%{
#include <stdio.h>


%}

%%

"int"|"float"|"void"|"main"|"return" {printf("%s --> Keyword\n", yytext);}
[a-zA-Z_][a-zA-Z_0-9]* {printf("%s --> IDENTIFIER\n", yytext);}
; {printf("%s --> Punctuation\n", yytext);}
"=="|"<="|">=" {printf("%s --> Operator\n", yytext);}
[+\-*/%<>=] {printf("%s --> Operator\n", yytext);}
[.0-9][0-9]+ {printf("%s --> Float\n", yytext);}
\/\/.* {}
%%

int yywrap() { 
    return 1; 
}

int main() {
    yylex();
    return 0;
}
