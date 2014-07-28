/*
 *	Exercise 13-2: Write a function that takes a single string 
 *	as its argument and returns a pointer to the first nonwhite 
 *	character in the string
 *
 */

#include<stdio.h>
#include<string.h>

//  This Function finds the first white-space character and returns
//  the remainder of the string including the space.
char * find_space(char *sometext) {
	while ((*sometext) !=' ' && (*sometext) != '\t' ) {
        ++sometext; 
	}
    return(++sometext);
}
/////////////////////////////////////////////////////////////////////
int main()
{
	char sometext[256] = "";
    char * find_space(char *sometext);

    puts("Enter some text with or without a space:\n");
    gets(sometext);
    printf("Text you Entered:\n\t\t>>%s<<\n", sometext);
    printf("Remainder of Text:\n\t\t>>%s<<\n", find_space(sometext));
	
	return(0);
}
