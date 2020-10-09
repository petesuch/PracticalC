/*
 *
 * Exercise 8-6: Write a program that converts numbers to words. 
 * For example, 895 results in "eight nine five".
 *
 *
 */

#include<stdio.h>
#include<stdlib.h> // For exit
#define SIZE 3 // How many Digits to Convert

int main() {

    int i = 0; // iterator for character array
    char ch ;
    char buff[SIZE];
    puts("Convert a number into Words? Why Not? 612 --> Six One Two\n");
    while(1) { 
        puts("\nEnter a Three Digit Number to Convert into Words: (Enter '#' To EXIT)");
        gets(buff);
        printf("\t--->");
		for (i = 0 ; i < SIZE; i++) {
            ch = buff[i];
            if (ch == '#')
                exit(0);    
                switch (ch) {   //  What digit do we have?  
                    case '0':
                        printf("Zero ");
                        break;
                    case '1':
                        printf("One ");
                        break;
                    case '2':
                        printf("Two ");
                        break;
                    case '3':
                        printf("Three ");
                        break;
                    case '4':
                        printf("Four ");
                        break;
                    case '5':
                        printf("Five ");
                        break;
                    case '6':
                        printf("Six ");
                        break;
                    case '7':
                        printf("Seven ");
                        break;
                    case '8':
                        printf("Eight ");
                        break;
                    case '9':
                        printf("Nine ");
                        break;
                    default:    // 
                        printf("\t...ooops! ->%c is not a number!! \n", ch);
                }   // Switch
        }   // for 
    }   // while
	return (0);
}
