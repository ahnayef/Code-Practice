#include<stdio.h>

int main(){

// getchar();

char str[100];
// scanf("%[^\n]s", str);
// or
// fgets(str, 100, stdin);
// or
// gets(str);

// char str1[100];
// fgets(str1, 100, stdin);
// printf("%s", str1);

// multiline string input

char ch;

int i = 0;
while ((ch = getchar()) != EOF)
{
    str[i] = ch;
    i++;
}
str[i] = '\0';

printf("%s", str);





return 0;
}