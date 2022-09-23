/*
 * kats.c
 * 
 * This is the fputs fgets version.   
 * 
 * A very simple version of cat.  Takes no arguments other than a valid text file.
 * 
 * @author: Peter Suchsland
 *
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {

    FILE *file_in;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc == 1 ) { 
       fputs("Please enter a valid filename.\n", stdout); 
        return(0);
    } else {  //  Take the first argument to command line
        file_in = fopen(argv[1], "rb");
    }

    char string[100];

    while (fgets(string, sizeof(string), file_in) != NULL) 
        fputs(string, stdout); // write to console
    
    fclose(file_in);
    return(0);
}

