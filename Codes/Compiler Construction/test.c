#include<stdio.h>
#include<string.h>

int main(){

/*
Build a tokenizer
Input: C program

Output: 
Tokens: 
int --> keyword
main --> identifier
( --> Parenthesis
) --> Parenthesis
temp --> identifier
= --> Operator
10 --> Numerical
; --> Spacial character
if --> keyword
( --> Parenthesis
> --> Operator
{ --> Bracket
return --> keyword

*/

// Take multiline input from user
     char str[1000];
     printf("Enter a C program:\n");


     while(1){
          char line[100];
          fgets(line, sizeof(line), stdin);
          if(strcmp(line, "END\n") == 0) break;
          strcat(str, line);
     }
     
     char *keywords[] = {"int", "return", "if", "else", "while", "for", "do", "switch", "case", "break", "continue", "default", "union", "struct", "typedef", "enum", "const", "volatile", "static", "extern", "register", "auto", "sizeof", "goto", "inline", "restrict", "signed", "unsigned", "long", "short", "float", "double", "char", "void"};
     char *identifier[] = {"main", "temp", "num", "count", "sum", "avg", "max", "min", "i", "j", "k", "x", "y", "z", };
     char *operators[] = {"+", "-", "*", "/", "=", ">", "<", "==", "!=", ">=", "<=", "&&", "||", "!", "&", "|", "^"};
     char *special_chars[] = {";", ",", "(", ")", "{", "}", "[", "]"};

     
     for(int i = 0; i < strlen(str); i++){
          
     }

     
     
     


     return 0;


}

