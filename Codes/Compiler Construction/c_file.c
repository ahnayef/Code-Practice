#include<stdio.h>

int main(){

FILE *file;

// Create
file = fopen("test.txt", "w");

// Write in a file
fprintf(file, "Hello, World!\n");
fprintf(file, "This is a test file.\n");
fclose(file);

// Append
file = fopen("test.txt", "a");
fprintf(file, "Appending a new line.\n");
fclose(file);

// Read
file = fopen("test.txt", "r");

// Read multiple lines
char line[100];
while (fgets(line, 100, file) != NULL) {
    printf("%s", line);
}
fclose(file);
return 0;
}