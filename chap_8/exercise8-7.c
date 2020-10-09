/*
 *
 *
 *  Exercise 8-7: The number 85 is pronounced "eighty-five," not
 *  "eight five."  Modify the previous program to handle the numbers
 *  through 100 so that all numbers come out as we really say them.
 *  For example, 13 would be "thirteen" and 100 would be  "one hundred"
 *
 *
 *
 *
 *
 */


#include<stdio.h>
#include<stdlib.h> // For exit
#define SIZE 3 // How many Digits to Convert

void print_teens(int num) {  // Prints out Numbers between 10 to 19 using switch/case
    switch (num) {
        case 10:
            printf("Ten");
            break;
        case 11:
            printf("Eleven");
            break;
        case 12:
            printf("Twelve");
            break;
        case 13:
            printf("Thirteen");
            break;
        case 14:
            printf("Fourteen");
            break;
        case 15:
            printf("Fifteen");
            break;
        case 16:
            printf("Sixteen");
            break;
        case 17:
            printf("Seventeen");
            break;
        case 18:
            printf("Eighteen");
            break;
        case 19:
            printf("Nineteen");
            break;
    }
}

void print_tees(int num) { // Prints out Numbers between 20 to 99 using a char array
    int ones_digit;
    int tens_digit;
    char *ones_array[] = { "", "One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine" };
    char *tens_array[] = { "", "", "Twenty", "Thirty", "Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
    tens_digit = (num /10)%10;
    ones_digit = num %10;
    printf("%s %s", tens_array[tens_digit], ones_array[ones_digit]);
}

int main() {

    int i = 0; // iterator for character array
    int num = 0;
    char buff[SIZE];
    char *singles_array[] = { "Zero", "One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine"};
    
    puts("Converts a number 0-100 into Words? (e.g. 97) --> Ninety Seven_\n");

    while(1) { 
        puts("\n\nEnter a Number between 0-100 to Convert into Words: (Enter 999 To EXIT)\n");
        gets(buff);
        sscanf(buff, "%d", &num);

        if (num == 999) break;      // EXIT PROGRAM

        if (( 0 <= num) && (num < 10)) {    // Low Numbers
            printf("%s", singles_array[num]);
        }
        if  ((10 <= num) && (num  <= 19)) { // Teens 
            print_teens(num);
        }
       if  ((20 <= num) && (num <= 99)) { // 20 to 99
            print_tees(num);
        }
        if (num == 100)  {
            printf("One Hundred");
        } 

    }   // while
	return (0);
}
