%{
%}



%%
[a-zA-Z]+ {printf("%s: Word\n", yytext);}
[0-9]+ {printf("%s: Int\n", yytext);}
%%

int yywrap() {return 1;}

int main()
{
    yylex();
    return 0;
}