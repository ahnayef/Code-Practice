%{
%}



%%
[a-zA-Z]+ {printf("Word: %s\n", yytext);}
[0-9]+ {printf("Int: %s\n", yytext);}
[^a-zA-Z0-9]+ {}
%%

int yywrap() {return 1;}

int main()
{
    yylex();
    return 0;
}