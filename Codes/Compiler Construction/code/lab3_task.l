%{
%}

%%
stop        {return 0;}
"int"|"float"|"double"|"if"|"else"|"while"|"for"|"return" {printf("Keyword");}
[a-zA-Z_][a-zA-Z0-9_]* {printf("Identifier");}
[0-9][\.0-9]*      {printf("Number");}
"=="|"!="|"<="|">="|"&&"|"||"|"++"|"--" {printf("Operator");}
[+\-*/=<>!&|] {printf("Operator");}
.*          {printf("Unknown");}
%%


int yywrap(){
     return 1;
}

int main(){
     yylex();
     return 0;
}