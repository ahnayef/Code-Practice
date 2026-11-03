%{


%}

%%
[a-z]+ {printf("Small");}
[A-Z]+ {printf("Capital");}

%%


int yywrap(){return 1;}

int main(){

     yylex();

     return 0;
}