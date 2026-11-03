%{

%}


%%

[a-zA-Z]+ {printf("%s(%d)", yytext, yyleng);}
[0-9]+ {printf("%s(%d)", yytext, yyleng);}
[^a-zA-Z0-9]+ {}
%%


int yywrap(){return 1;}

int main(){

     yylex();
     return 0;
}