%{

int cnt=0, var1=0, var2=0;
char op;
%}


%%
[0-9]+ {
     if(cnt == 0){
          var1 = atoi(yytext);
     }else{
          var2 = atoi(yytext);
     }
     cnt++;
}

"+"|"-" {op = *yytext;}

\n {
     if(op=='+'){
          printf("Sum:%d", var1+var2);
     }else{
          printf("Sub:%d", var1-var2);
     }
}

%%



int yywrap(){return 1;}

int main(){

     yylex();

     return 0;
}