/*
 *  Exercise 8-3: Write a program to average n numbers
 *
 *
 *
 */


#include<stdio.h>
#include<string.h>

int main() {
    int c = 0;
    int n = 0; // number of numbers
    char buf[10];
    float sum = 0.0;
    float num = 0.0;

    puts("How many numbers do you want to average?: ");
    gets(buf);
    sscanf(buf, "%d", &n);

    for (c = 0; c < n; c++) {
        printf("#%d: Enter Number to average: ", c+1);
        gets(buf);
        sscanf(buf, "%f", &num);
        sum+= num;
    }
    printf("\n\tThe Average is: %.2f \n", (float)sum/n);
    return(0);

}
