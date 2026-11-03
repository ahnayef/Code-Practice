%{

int num = 0, word = 0;
%}

%%
[0-9] {printf("Int\n");}
[.0-9][0-9]* {printf("Float\n");}

%%

int yywrap(){return 1;}

int main(){

     yylex();

     printf("Num: %d", num);
     printf("Word: %d", word);

     return 0;
}