%{
    #include <stdio.h>
    int val1 = 0, val2 = 0;
    int cnt = 0;
    char operator;
%}

%%
[0-9]+  {
    if(cnt == 0) {
        val1 = atoi(yytext);
    }
    else if(cnt == 1) {
        val2 = atoi(yytext);
    }
    else {
        printf("Too many numbers!\n");
    }
    cnt++;
}
"+" {operator='+';}
"-" {operator='-';}
"/" {operator='/';}
"*" {operator='*';}

\n      {
    if(cnt == 2){
        if(operator == '+'){
          printf("Sum: %d\n", val1 + val2);
        }else if(operator == '-'){
          printf("Sub: %d\n", val1 - val2);
        }else if(operator == '*'){
          printf("Mul: %d\n", val1 * val2);
        }else{
          if(val2==0){
               printf("Div by 0");
          }else{
               printf("Div: %d\n", val1 / val2);
          }
        }
    }
    else {
        printf("Enter exactly 2 numbers\n");
    }
    cnt = val1 = val2 = 0;
}
.       ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    yylex();

    return 0;
}