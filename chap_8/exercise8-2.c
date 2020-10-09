/*
 *
 *
 * Exercise 8-2: The total resistance of n resistors in parallel is:
 * 1/R = 1/r1 + 1/r2 + ... 1/rn
 *
 * Write a program to compute the total resistance for any number 
 * of parallel resistors.
 * 
 *
 */

#include<stdio.h>

int main() {
    int i = 0;
    int n = 0 ;
    char buff[10];
    float val =0.0;
    float inv_resistance = 0.0;

    puts("*** Total resistance of Resistors in parallel ***\n");
    puts("Enter the number of resistors in parallel\n");
    gets(buff);
    sscanf(buff, "%d", &n);
    
    for ( i = 1; i <=n; i++) {
        printf("%d: Enter a value for a resistor:\n-->", i);
        gets(buff);
        sscanf(buff, "%f", &val);
        inv_resistance+= (1/val);
    }
    printf("\tTotal Resistance is %.3f Ohms\n", 1/inv_resistance);
    return(0);
}
