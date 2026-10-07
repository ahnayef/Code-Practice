%{
//     Library 
%}



%%
[0-9]+    { printf("Integer"); }
[a-zA-Z]+   { printf("Word"); }
.*           {printf("Invalid");}
%%

int yywrap(){

     return 1;
}

int main(){

     yyin = fopen("input.txt", "r");
     if(yyin == NULL){
          printf("File Not found");
          return 0;
     }
     yylex();
     return 0;
}