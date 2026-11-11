%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bison.tab.h"

void errorMessage();
%}

%option noyywrap

number [0-9]+

%%
{number} {yylval = atoi(yytext); return NUM;}
\+        {return PLUS;}
\r?\n     {return EOL;}
[ \t]     {}
.+         {errorMessage();}
%%

void errorMessage(){
     printf("Invalid Input! %s\n", yytext);
}