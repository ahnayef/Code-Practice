%{
#include<stdio.h>
#include<stdlib.h>
extern FILE *yyin;
int yyerror(const char *s);
int yylex();
%}

%token NUM PLUS EOL

%%
expr :
     NUM PLUS NUM EOL {printf("%d + %d = %d", $1, $3, $1+$3);return 0;}
     ;

%%


int yyerror(const char *s){
     fprintf(stderr, "Error: %s", s);
     return 0;
}

int main(){
     printf("Enter Expression (e.g. 2+1):\n");

     yyin = fopen("input.txt", "r");

     if(yyin == NULL){
          printf("File not found!\n");
          return 0;
     }
     yyparse();

     return 0;
}


