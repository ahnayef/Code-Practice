%{
#include <stdio.h>


int cnt=0;

%}

%%
stop {return 0;}
[a-zA-Z0-9]  {printf("Token %s\n", yytext); cnt++;}
%%

int yywrap() { 
    return 1; 
}

int main() {
    yylex();

    printf("Total: %d", cnt);
    return 0;
}
