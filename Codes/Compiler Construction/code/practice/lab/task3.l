%{

int num = 0, word = 0;
%}

%%
p.*q {printf("Valid");}
.* {printf("Invalid");}

%%

int yywrap(){return 1;}

int main(){

     yylex();

     printf("Num: %d", num);
     printf("Word: %d", word);

     return 0;
}