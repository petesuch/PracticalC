/*  bin_to_ascii.c 
 *
 * Exercise 14-4: Write a program that reads an ASCII file containing a
 * list of  numbers and writes a binary file containing the same list. 
 * VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
 * This program goes the other way so that you can check your work.
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
#include<sys/types.h> /* file defines for UNIX filesystem */
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
// #define O_BINARY 0
///////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {

    int    in_file_p;   // A number for a File Descriptor  (open)
    FILE   *out_file_p;  

    char  infile[80];
    char  outfile[80];

    unsigned char  buffer[4];  // line to evaluate for number

    int   read_size;
///////////////////////////////////////////////////////////////////////////
////    USAGE
    if (argc != 3 ) {
        fprintf(stderr,"USAGE: bin_to_ascii infile outfile \n");
        exit(81);
    } 
////    CLEAN UP
    strcpy(infile, argv[1]);
    infile[strlen(infile)] = '\0'; // remove end garbage
    strcpy(outfile, argv[2]);
    outfile[strlen(outfile)] = '\0'; // remove end garbage
    
////    Open for Binary Reading
    in_file_p = open(infile, O_RDONLY|O_BINARY);
    if (in_file_p < 0) {
        fprintf(stderr, "Error:Unable to open %s\n", infile);
        exit(8);
    }
    
////    Open for Ascii Writing
    out_file_p = fopen(outfile, "w");  
    if (out_file_p == NULL) {
        fprintf(stderr, "Problem finding file: %s\n", outfile);
        exit(8);
    }    
///////////////////////////////////////////////////////////////////////////
////    Reading and Writing Starts Here
    while (1) {
        read_size = read(in_file_p, buffer, sizeof(buffer));
        if (read_size == 0) 
            break; /* end of file */
        if (read_size < 0) {
            fprintf(stderr, "Error:Read error\n");
            exit(8);
        }
        fprintf(out_file_p, "%s", buffer);
    }    

    close(in_file_p);
    fclose(out_file_p);
    return (0);
    }
