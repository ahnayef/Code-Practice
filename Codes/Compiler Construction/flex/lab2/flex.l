%{
//     Library 
%}



%%
[0-9]+    { printf("Integer"); }
[a-zA-Z]+   { printf("Word"); }
[+\-*/=<>!&]|"=="|"!="|"<="|">="|"&&"|"||"|"++"|"--" {printf("Operator");}
.*           {printf("Invalid");}

%%

int yywrap(){

     return 1;
}

int main(){


     yylex();
     return 0;
}