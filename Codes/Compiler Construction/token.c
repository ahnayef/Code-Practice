#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char word[])
{
    char keywords[][15] = {
        "int", "float", "char", "double",
        "if", "else", "for", "while",
        "return", "void", "do", "switch",
        "case", "break", "continue"};

    int n = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }

    return 0;
}


int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>' || ch == '%' || ch == '!' || ch == '&' || ch == '|')
        return 1;

    return 0;
}

int isSpecial(char ch)
{
    if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == ';' || ch == ',')
        return 1;

    return 0;
}


int main()
{
    char str[1000];
    char word[100];

    printf("code:\n");

    while (fgets(str, sizeof(str), stdin))
    {
        int i = 0;

        while (str[i] != '\0')
        {

            if (isspace((unsigned char)str[i]))
            {
                i++;
                continue;
            }

            else if (str[i] == '"')
            {
                int j = 0;
                word[j] = str[i];
                j++;
                i++;

                while (str[i] != '"' && str[i] != '\0')
                {
                    word[j] = str[i];
                    j++;
                    i++;
                }

                word[j] = str[i];
                j++;
                i++;
                word[j] = '\0';

                printf("%s --> String Literal\n", word);
            }

            else if (isdigit((unsigned char)str[i]))
            {
                int j = 0;

                while (isdigit((unsigned char)str[i]))
                {
                    word[j] = str[i];
                    j++;
                    i++;
                }

                word[j] = '\0';
                printf("%s --> Numerical Value\n", word);
            }

            else if (isalpha((unsigned char)str[i]) || str[i] == '_')
            {
                int j = 0;

                while (isalpha((unsigned char)str[i]) || isdigit((unsigned char)str[i]) || str[i] == '_')
                {
                    word[j] = str[i];
                    j++;
                    i++;
                }

                word[j] = '\0';

                if (isKeyword(word)){
                     printf("%s --> Keyword\n", word);

                }
                else{

                     printf("%s --> Identifier\n", word);
                }
            }

            else if (isSpecial(str[i]))
            {
                printf("%c --> Special Character\n", str[i]);
                i++;
            }

            else if (isOperator(str[i]))
            {
                printf("%c --> Operator\n", str[i]);
                i++;
            }

            else
            {
                i++;
            }
        }
    }

    return 0;
}