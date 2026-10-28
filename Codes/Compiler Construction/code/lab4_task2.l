%{
    #include <stdio.h>
%}

%%
stop        {return 0;}
\"[a-zA-Z0-9\\t\\n\\r]*\" {printf("String");}
\'.\' {printf("Char");}
.*          {printf("Invalid");}
%%

int yywrap()
{
    return 1;
}

int main()
{
    yyin = fopen("input.txt", "r");
    if (yyin == NULL)
    {
        printf("File not found!\n");
        return 0;
    }

    yylex();

    return 0;
}