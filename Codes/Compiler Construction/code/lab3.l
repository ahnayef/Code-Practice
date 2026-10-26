%{
%}

%%
stop        {return 0;}


"if"|"else"|"while"|"for"|"int"|"float"|"return"   { printf("KEYWORD\n"); }
[a-zA-Z_][a-zA-Z0-9_]*                              { printf("IDENTIFIER\n"); }
[0-9]+(\.[0-9]+)?                                    { printf("NUMBER\n"); }
"=="|"!="|"<="|">="|"&&"|"||"|[+\-*/%=<>!&|^~]      { printf("OPERATOR\n"); }



.*          {other++;}
%%


int yywrap(){

     return 1;
}

int main(){
     yylex();
     return 0;
}