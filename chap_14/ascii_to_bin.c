/*
 *
 * Exercise 14-4: Write a program that reads an ASCII file containing a
 * list of  numbers and writes a binary file containing the same list. 
 * Write a program that goes the other way so that you can check your work.
 * 
 */

#include<sys/types.h> /* file defines for UNIX filesystem */
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
///////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {

    FILE  *in_file_p;

    int   out_file_p;  // Integer for a File Descriptor  (open)
    ///FILE   *out_file_p;  // Pointer for (fwrite)

    char  infile[80];
    char  outfile[80];
    char  buffer[4];  //  MUST be 4 for int
    int   read_size;
///////////////////////////////////////////////////////////////////////////
////    USAGE
    if (argc != 3 ) {
        fprintf(stderr,"USAGE: ascii_to_bin infile outfile \n");
        exit(81);
    } 
////    CLEAN UP

    strcpy(infile, argv[1]);
    infile[strlen(infile)] = '\0'; // remove end garbage

    strcpy(outfile, argv[2]);
    outfile[strlen(outfile)] = '\0'; // remove end garbage

////    Open for Ascii Reading

    in_file_p = fopen(infile, "rt");  
    if (in_file_p == NULL) {
        fprintf(stderr, "Problem finding file: %s\n", infile);
        exit(8);
    }    
////    Open for Binary Writing

    out_file_p = open(outfile, O_WRONLY|O_TRUNC|O_CREAT, 0666);  
    ///out_file_p = fopen(outfile, "wb");  
    if (out_file_p < 0) {
        fprintf(stderr, "Error:Unable to open %s\n", outfile);
        exit(8);
    }
    
    while (fgets(buffer, sizeof(buffer), in_file_p) != NULL) {
        read_size = sizeof(buffer);
        write(out_file_p, buffer, (unsigned int)read_size);
        ///fwrite(buffer,read_size,1,out_file_p);

    }    

    fclose(in_file_p);
    close(out_file_p);
    ///fclose(out_file_p);
    return (0);
    }
