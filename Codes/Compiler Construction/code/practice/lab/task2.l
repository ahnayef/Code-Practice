%{

int num = 0, word = 0;
%}

%%
[a-zA-Z]+ {num++;}
[0-9] {words++;}

%%

int yywrap(){return 1;}

int main(){

     yylex();

     printf("Num: %d", num);
     printf("Word: %d", word);

     return 0;
}