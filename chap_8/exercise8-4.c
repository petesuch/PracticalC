/*
 *
 * Exercise 8-4: Write a program to print out the multiplication table
 *
 */

#include<stdio.h>
#define SIZE 10

int main() {
    int x = 0;
    int y = 0;

    for ( x = 1; x <= SIZE; x++ ) {
        for ( y = 1; y <= SIZE; y++) {
            printf("%d*%d=%d\t",x, y, x*y); 
        }
        printf("\n");
    }
    return(0);
}
