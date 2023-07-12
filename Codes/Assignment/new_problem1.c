#include <stdio.h>

struct studentData
{
    int roll;
    char name[100];
    int age;
} student[5];

int main()
{

    for (int i = 0; i < 5; i++)
    {
        printf("Student %d Roll: ", i + 1);
        scanf("%d", &student[i].roll);
        printf("Student %d Name: ", i + 1);
        scanf("\n");
        scanf("%[^\n]s", &student[i].name);
        printf("Student %d age: ", i + 1);
        scanf("%d", &student[i].age);
    }

    printf("\n\nStudent 2 Name: %s\n", student[1].name);
    printf("Student 2 Roll: %d\n", student[1].roll);
    printf("Student 2 Age: %d\n\n", student[1].age);
}