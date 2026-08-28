#include<stdio.h>

int main(){
// For the block-structured C code given below, indicate the values assigned to w, x, y, and X.
int w, x, y ,z;

int i = 4; int  j = 5;

{
     int j = 7;
     i = 6;
     w=i+j;
}
x = i+j;

{
     int i = 8;
     y = i+j;
}

z= i+j;
     printf("w=%d\nx=%d\ny=%d\nz=%d\n", w, x, y, z);

     return 0;
}