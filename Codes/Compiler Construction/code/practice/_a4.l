%{
#include <stdio.h>
#include <string.h>

char* reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    return str;
}
%}

%%

[a-zA-Z]+      { printf("%s(%d)", reverse(yytext), yyleng); }
[0-9]+         { printf("%s(%d)", reverse(yytext), yyleng); }
[^a-zA-Z0-9]+  { /* Ignore all other characters */ }

%%

int yywrap() { 
    return 1; 
}

int main() {
    yylex();
    return 0;
}
