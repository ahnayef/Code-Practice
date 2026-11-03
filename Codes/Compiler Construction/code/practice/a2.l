%{


%}


%%
[a-zA-Z]+ {printf("%s: Word\n", yytext);}
[0-9]+ {printf("%s: Int\n", yytext);}
[^a-zA-Z0-9]+ {}
%%


int yywrap(){return 1;}


int main(){

    yyin = fopen("input.txt", "r");

    if(yyin == NULL){
        printf("FILE NOT FOUND");
    }

    yylex();

     return 0;
}


