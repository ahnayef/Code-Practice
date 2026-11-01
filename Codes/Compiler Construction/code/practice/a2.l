%{


%}


%%
[a-zA-Z]+ {printf("%s: Word\n", yytext);}
[0-9]+ {printf("%s: Int\n", yytext);}
%%


int yywrap(){return 1;}


int main(){
     yyin = fopen("input.txt", "r");

     if (yyin == NULL)
    {
        printf("File not found!\n");
        return 0;
    }

    yylex();

     return 0;
}


