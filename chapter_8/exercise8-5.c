/*
 *
 * Exercise 8-5: Write a program that reads a character and prints out
 * whether or not it is a vowel or a consonant
 *
 *
 */

#include<stdio.h>

int main() {

    char ch ;
    char buff[1];
    puts("Is a character a vowel or consonant?\n");
    while(1) { 
        puts("Enter a Character:\t'#' to exit ");
        gets(buff);
        sscanf(buff , "%c", &ch);
        if (ch == '#')  
            break;
        switch (ch) {   // VOWELS 
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                printf("\t%c is a vowel\n", ch);
                break;
            default:    // EVERYTHING ELSE A CONSONANT 
                printf("\t%c is a consonant\n", ch);
        }
    }
	return (0);
}
