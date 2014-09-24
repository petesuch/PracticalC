/* 
 * 
 * Exercise 7-1: Write a program to convert English units to metric
 * (i.e., miles to  kilometers, gallons to liters, etc.).
 * Include a specification and a code design.
 *
 *
 * Menu Loop : '999' to quit
 * 1) Miles to Kilometers (1:1.60934)
 * 2) Kilometers to miles (1:0.621371)
 * 3) Meters to feet (1:3.28084)
 * 4) Feet to Meters (1:0.3048)
 * 5) Inches to milimeters (1:25.4)
 * 6) Milimeters to Inches (1:0.0393701) 
 * 7) Gallons to Liters (1:3.78541)
 * 8) Liters to Gallons (1:0.264172)
 * 9) Gallons to cups (1:16)
 * 10) Cups to Gallons (1:0.0625)
 * 11) Gallons to Ounces (1:128)
 * 12) Ounces to Gallons (1:0.0078125)
 * 13) Cups to ounces (1:8)
 * 14) Ounces to Cups (1:0.125)
 * 15) Tablespoons to ounces (1:0.5)
 * 16) Ounces to Tablespoons (1:2)
 *
 *
 * User Enters: '9 1' to convert 1 Gallon to Cups
 * Program prints:
 * >>1 Gallon =  16 cups<<
 *
 *
 *
 */

#include<stdio.h>
#include<string.h>

int main() {
    int choice = 0;
    float value = 0.0;
    char line[20] ="";
    char str1[20] = "";
    char str2[20] ="";
    float conversion = 0.0;

    while(1) {
        printf("\nEnter a choice :               999 to EXIT\n");
        puts(" 1) Miles to Kilometers  \t\t9) Gallons to Cups");
        puts(" 2) Kilometers to Miles  \t\t10) Cups to Gallons");
        puts(" 3) Meters to Feet       \t\t11) Gallons to Ounces");
        puts(" 4) Feet to Meters       \t\t12) Ounces to Gallons");
        puts(" 5) Inches to Milimeters \t\t13) Cups to Ounces");
        puts(" 6) Milimeters to Inches \t\t14) Ounces to Cups"); 
        puts(" 7) Gallons to Liters    \t\t15) Tablespoons to Ounces"); 
        puts(" 8) Liters to Gallons    \t\t16) Ounces to Tablespoons"); 

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d %f", &choice, &value); 
        if (choice == 999) { 
            printf("Exiting ... Bye! \n");
            break;
        }
        switch (choice) {
            case 1: {
                strcpy(str1, "Miles");
                strcpy(str2, "Kilometers");
                conversion = 1.60934; 
                break;
            }
            case 2: {
                strcpy(str1, "Kilometers");
                strcpy(str2, "Miles");
                conversion = 0.621371; 
                break;
            }
            case 3: {
                strcpy(str1, "Meters");
                strcpy(str2, "Feet");
                conversion =3.28084; 
                break;
            }
            case 4: {
                strcpy(str1, "Feet");
                strcpy(str2, "Meters");
                conversion =0.3048 ; 
                break;
            }
            case 5: {
                strcpy(str1, "Inches");
                strcpy(str2, "Milimeters");
                conversion =25.4; 
                break;
            }
            case 6: {
                strcpy(str1, "Milimeters");
                strcpy(str2, "Inches");
                conversion =0.0393701 ; 
                break;
            }
            case 7: {
                strcpy(str1, "Gallons");
                strcpy(str2, "Liters");
                conversion =3.78541 ; 
                break;
            }
            case 8: {
                strcpy(str1, "Liters");
                strcpy(str2, "Gallons");
                conversion =0.264172 ; 
                break;
            }
            case 9: {
                strcpy(str1, "Gallons");
                strcpy(str2, "Cups");
                conversion =16; 
                break;
            }
            case 10: {
                strcpy(str1, "Cups");
                strcpy(str2, "Gallons");
                conversion =0.0625 ; 
                break;
            }
            case 11: {
                strcpy(str1, "Gallons");
                strcpy(str2, "Ounces");
                conversion = 128; 
                break;
            }
            case 12: {
                strcpy(str1, "Ounces");
                strcpy(str2, "Gallons");
                conversion = 0.0078125 ; 
                break;
            }
            case 13: {
                strcpy(str1, "Cups");
                strcpy(str2, "Ounces");
                conversion =8 ; 
                break;
            }
            case 14: {
                strcpy(str1, "Ounces");
                strcpy(str2, "Cups");
                conversion =0.125; 
                break;
            }
            case 15: {
                strcpy(str1, "Tablespoons");
                strcpy(str2, "Ounces");
                conversion =0.5; 
                break;
            }
            case 16: {
                strcpy(str1, "Ounces");
                strcpy(str2, "Tablespoons");
                conversion =2; 
                break;
            }
            default: {
                puts("!!! You must enter a number choice between 1-16 !!!");
                puts("!!! Followed by a value to convert !!!");
                break;
            }
        }
        printf("\n>>>%.2f %s = %.3f %s<<<\n", value, str1, value*conversion, str2);
    }
    return(0);
}
