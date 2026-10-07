#include<stdio.h>

int main(){

     int a =10;
     int*ptr = &a;
     printf("Value of a: %d\n", a);
     printf("Address of a: %p\n", &a);
     printf("Value of ptr: %p\n", ptr);
     printf("Value pointed by ptr: %d\n", *ptr);

     // Dynamic memory allocation
     // malloc, calloc, realloc, free
     int *arr;
     arr = (int*)malloc(5 * sizeof(int));
     


return 0;
}