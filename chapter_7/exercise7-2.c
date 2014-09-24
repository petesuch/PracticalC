 /*  Exercise 7-2: Write a program to perform date arithmetic such as how many days
  *  there are between 6/6/90 and 4/3/92. Include a specification and a code design
  *
  *  User is prompted to enter a start date and end date in MM/DD/YYYY format. 
  *  Program gives answer in days.
  *
  * January (1) : 31 days
  * February (2) : 28 days
  * March (3) : 31 days
  * April (4) : 30 days
  * May (5) : 31 days
  * June (6) : 30 days
  * July (7) : 31 days 
  * August (8) : 31 days
  * September (9) : 30 days
  * October (10) : 31 days
  * November (11) : 30 days
  * December (12) : 31 days
  * 
  * ToDo:
  *     Entry checking 
  *
  */

#include <stdio.h>
#include <string.h>

int dim[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int leapcalc(int year) {
    if (((year % 4 == 0 ) && ( year % 100 != 0)) || ( year % 400 == 0)) {
        return(1); // True ... year is a leap year
    }
    else {
        return(0); // False
    }
}

int daynmbr(int day, int month, int year) {
///// Calculate the Day Number for any Date
    int count =0;
    int c = 0;
    int dn = 0;
    for ( c = 0; c < month-1; c++ ) {
        if ((leapcalc(year)) && (c == 1)) {
            count += 29;
        }
        else {
            count += dim[c]; 
        }
    }
    dn = count + day;
    //printf(">>Day Number: dn  %d\n", dn);
    return(dn);
}



int main() {
    int start_mos, start_day, start_yr, end_mos, end_day, end_yr;
    int d2d=0, dlim=0, dliy=0, diby =0; 
    char start_date[11]; 
    char end_date[11]; 
    puts("Enter a Start date (eg: 9/10/2013)");

    gets(start_date);
    sscanf(start_date, "%d/%d/%d", &start_mos, &start_day, &start_yr); 
    puts("Enter the End date (eg: 10/11/2014)");
    gets(end_date);
    sscanf(end_date, "%d/%d/%d", &end_mos, &end_day, &end_yr); 
    // ///////////////////////////////////////////////////////////////////
    
    // ///////////////////////////////////////////////////////////////////
    // Days left in month for start_day dlim
    if ((leapcalc(start_yr)) && (start_mos == 2)) {
        dlim = (29 - start_day);
    }
    else {
        dlim = dim[start_mos-1] - start_day; 
    }
    // ///////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////
    // Calculate days left in year dliy for start_day
    int c = 0; 
    for ( c = start_mos; c < 12; c++) {
        if ((leapcalc(start_yr)) && (c == 1))  {
            dliy += 29;
        }
        else dliy += dim[c]; 
    }
    dliy = dliy + dlim;
    // ///////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////
    // Calculate Number of days in between first and last years diby 
    for ( c = (start_yr+1); c < end_yr; c++) {
        diby += 365; 
        if (leapcalc(c)) {
            diby++;  // Add one day for leap year between first/last years
        }
    } 
    
    // ///////////////////////////////////////////////////////////////////
    // Final Calculation
    if (start_yr == end_yr)  {
        d2d=daynmbr(end_day,end_mos,end_yr)-daynmbr(start_day,start_mos,start_yr);
    }
    // Add days left in year with day number and days in between
    else {
        d2d = dliy + diby + daynmbr(end_day,end_mos,end_yr);
    } 
    printf("\nThe Difference between %s and %s is %d days.\n", start_date, end_date, d2d);
    // ///////////////////////////////////////////////////////////////////

    return(0);
}

