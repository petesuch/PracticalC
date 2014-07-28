/*
 * Exercise 14-3: Write a program that reads a file containing a list of 
 * numbers, and then writes two files, one with all numbers divisible by 
 * three and another containing all the other numbers.
 *
 *
 */

///////////////////////////////////////////////////////////////////////////
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
///////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {

    FILE  *in_file_p;
    FILE  *out_file1_p;
    FILE  *out_file2_p;
    char  infile[80];
    char  outfile1[80];
    char  outfile2[80];
    char  string[20];  // line to evaluate for number
    int num_to_eval = 0;
    
    if (argc != 4 ) {       //  Usage 
        fprintf(stderr,"USAGE: tab-expander infile outfile1 outfile2\n");
        exit(81);
    } 
//  CLEAN UP 
    strcpy(infile, argv[1]);
    infile[strlen(infile)] = '\0'; // remove end garbage 

    strcpy(outfile1, argv[2]);
    outfile1[strlen(outfile1)] = '\0'; // remove end garbage 

    strcpy(outfile2, argv[3]);
    outfile2[strlen(outfile2)] = '\0'; // remove end garbage 

    in_file_p = fopen(infile, "rb");
    out_file1_p = fopen(outfile1,"wb+");
    out_file2_p = fopen(outfile2,"wb+");

    if (in_file_p == NULL) {
        fprintf(stderr, "Problem finding file: %s\n", infile);
        exit(80); 
    }
///////////////////////////////////////////////////////////////////////////
 
    while (fgets(string, sizeof(string), in_file_p) != NULL) {

        sscanf(string, "%d", &num_to_eval);
        printf("Number:%d\n", num_to_eval);

        if ( num_to_eval %3 == 0) {
            printf("\t-->>%d IS divisable by 3\n", num_to_eval);
            fprintf(out_file1_p, "%d\n", num_to_eval);
        } else {
            printf("\t-->>%d is NOT divisable by 3\n", num_to_eval);
            fprintf(out_file2_p, "%d\n", num_to_eval);
        }            
    }
 
    fclose(in_file_p);
    fclose(out_file1_p);
    fclose(out_file2_p);
    return(0);
}
