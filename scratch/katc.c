/*  katc.c
 *  A simple version of cat in C language.
 *  This is the fgetc fputc version of kats
 *
 *  @author: Peter Suchsland
 *
 *
 *
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(int argc, char *argv[]) {

    FILE *file_in;
    char ch;
    size_t len = 0;
    ssize_t read;

    if (argc == 1 ) {   // No args given
        printf("Please enter a valid filename.\n");
        return(0);
    } else {  //  Use the first argument 
        file_in = fopen(argv[1], "rb"); // Needs an if-file-exists check
    }

    while(1) {
        ch = fgetc(file_in);
        if (ch == EOF) 
            break;
        fputc(ch, stdout);
    }

    fclose(file_in);
    return(0);
}
