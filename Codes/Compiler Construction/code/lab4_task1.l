%{
    #include <stdio.h>
    int lines = 0, keywords = 0, identifier = 0, integer = 0, floating=0, operator =0, other = 0;
%}

%%
stop        {return 0;}
\n          {lines++;}
"int"|"float"|"double"|"if"|"else"|"while"|"for"|"return" {keywords++;}
[a-zA-Z_][a-zA-Z0-9_]* {identifier++;}
[0-9]      {integer++;}
[0-9]+\.[0-9]+    {floating++;}
"=="|"!="|"<="|">="|"&&"|"||"|"++"|"--" {operator++;}
[+\-*/=<>!&|] {operator++;}
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
    /* 
    //  printf("Lines: %d\n", lines);
    //  printf("Keywords: %d\n", keywords);
    //  printf("Identifiers: %d\n", identifier);
    //  printf("Integers: %d\n", integer);
    //  printf("Floating point numbers: %d\n", floating);
    //  printf("Operators: %d\n", operator);
    //  printf("Others: %d\n", other);
    */

    /* Keep output into output.txt*/
    freopen("output.txt", "w", stdout);
    printf("Lines: %d\n", lines);
    printf("Keywords: %d\n", keywords);
    printf("Identifiers: %d\n", identifier);
    printf("Integers: %d\n", integer);
    printf("Floating point numbers: %d\n", floating);
    printf("Operators: %d\n", operator);
    printf("Others: %d\n", other);

    return 0;
}