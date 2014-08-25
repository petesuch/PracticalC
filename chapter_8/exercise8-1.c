/*
 *
 * Exercise 8-1: Print a checker board (8-by-8 grid). Each square should be 5 -by-3
 * characters wide
 *
 */

#include <stdio.h>
#include <string.h>

int main() {
    int len = 8; // 8 x 8 grid
    int box =3; // box is 3 lines high
    int c,d,e =0; // counters
    char corner = '+';
    char vertical = '|';
    char spaces[5] ; 
    char horizontal[5];

    strcpy (horizontal, "-----");
    strcpy (spaces, "     ");
    
    // start drawing ...
    for (e= 0; e < len; e++) {
        for (c = 0; c < len; c++) {
            printf("%c", corner);
            printf("%s", horizontal);
        }
        printf("%c\n", corner);

        for (d = 0; d < box; d++) {
             
            for (c = 0; c < len; c++) {
                printf("%c", vertical);
                printf("%s", spaces);
            }
            printf("%c\n", vertical);
        }
    }
    //  Final line 
    for (c = 0; c < len; c++) {
        printf("%c", corner);
        printf("%s", horizontal);
    }
    printf("%c\n", corner);

    return (0);
}
