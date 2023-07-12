#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    int age;
};

int main() {
    struct Student students[5] = {
        {1, "Amir Hamza", 22},
        {2, "Shafi", 21},
        {3, "Sakib", 21},
        {4, "Nasir", 21},
        {5, "Yahiya", 22}
    };


    printf("Details of student with roll number 2:\n");
    printf("Roll No: %d\n", students[1].rollNo);
    printf("Name: %s\n", students[1].name);
    printf("Age: %d\n", students[1].age);

    return 0;
}