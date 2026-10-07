%{
    Library 
%}

/*options noyywrap*/


%%
[0-9]+    { printf("Integer: %s\n", yytext); }
[a-zA-Z]+   { printf("Word: %s\n", yytext); }

%%

int yywrap(){

     return 1;
}

int main(){
     yylex();
     return 0;
}