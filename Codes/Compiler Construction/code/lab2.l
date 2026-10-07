%{
    #include <stdio.h>

    int word = 0, num = 0, other = 0;
%}

%%
stop        {return 0;}
[a-zA-Z]+   {word++;}
[0-9]+      {num++;}
.*          {other++;}
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

    printf("-------- Summary --------'\n");
    printf("Word count: %d\n", word);
    printf("Number count: %d\n", num);
    printf("Other token count: %d\n", other);

    return 0;
}