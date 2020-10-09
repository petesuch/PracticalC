/* tab-expander.c 
 *
 *  This program finds tabs and replaces them with space
 *
 * Write a program to copy a file, expanding all tabs to multiple
 * spaces 
 *
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(int argc, char *argv[]) {

    FILE  *in_file_ptr;
    FILE  *out_file_ptr;
    char  infilename[80];
    char  outfilename[80];
    int  char_ct = 0;
    int  tab_ct =0;
    char ch = '\0';

    if (argc != 3 ) {       //  Usage 
        fprintf(stderr,"USAGE: tab-expander infile outfile\n");
        exit(81);
    } 

    strcpy(infilename, argv[1]);
    // infilename[strlen(infilename)] = '\0'; // remove end garbage 

    strcpy(outfilename, argv[2]);
    // outfilename[strlen(outfilename)] = '\0'; // remove end garbage 

    in_file_ptr = fopen(infilename, "rb");
    out_file_ptr = fopen(outfilename,"wb+");

    if (in_file_ptr == NULL) {
        fprintf(stderr, "Problem finding file: %s\n", infilename);
        exit(80); 
    }
 
//***********  fgetc  **************************/
    while(1) {
        ch = fgetc(in_file_ptr);
        if (ch == EOF) 
            break;
        if (ch == '\t') {
            fputs("    ", out_file_ptr); // 4 spaces on output
            // printf("    "); // 4 spaces on output to stdout
            // printf("t"); // show a t instead of tab
            tab_ct++;
        } else {
            fputc(ch, out_file_ptr);
            // printf("%c", ch); // to stdout if desired
            ++char_ct;
        } 
    }
    printf("File: %s  created with %d Tabs changed\n", outfilename, tab_ct); 

    fclose(in_file_ptr);
    fclose(out_file_ptr);
    return(0);
}
