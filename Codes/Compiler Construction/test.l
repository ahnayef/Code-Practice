%{
%}

alp [a-zA-Z]
num [0-9]


%%

{alp}+{num}* {printf("Valid.\n");}
{num}+{alp}* {printf("Invalid.\n");}
. {return 0;}

%%

int yywrap() {return 1;}

int main()
{
    yylex();
    return 0;
}