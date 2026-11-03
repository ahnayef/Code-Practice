%{
%}



%%
[_a-zA-Z][_a-zA-Z0-9]* {printf("Valid\b");}
.* {printf("Invalid\n");}
%%


int yywrap() {return 1;}

int main()
{
    yylex();
    return 0;
}