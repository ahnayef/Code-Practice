%{
#include <stdio.h>


%}

%%

"int"|"float"|"void"|"main"|"return" {printf("(Keyword, %s)\n", yytext);}
[a-zA-Z_][a-zA-Z_0-9]* {printf("(Identifier, %s)\n", yytext);}
[.0-9][0-9]* {printf("(Int, %s)\n", yytext);}
; {printf("(Punctuation, %s)\n", yytext);}
"=="|"<="|">=" {printf("(Operator, %s)\n", yytext);}
[+\-*/%<>=] {printf("(Operator, %s)\n", yytext);}
\/\/.* {}
%%

int yywrap() { 
    return 1; 
}

int main() {
    yylex();
    return 0;
}
