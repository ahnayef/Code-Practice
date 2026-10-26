%{
%}

%%
stop        {return 0;}
a[a-zA-Z0-9]*b        {printf("Valid");}
.*          {printf("Invalid");}
%%


int yywrap(){
     return 1;
}

int main(){
     yylex();
     return 0;
}