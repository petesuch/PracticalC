/*  hi-bit_remove.c
 *
 *
 * Exercise 14-5: Write a program that copies a file and removes all characters with
 * the high bit set (((ch & 0x80) != 0)).
 *
 *
 *
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(int argc, char *argv[]) {


    FILE  *in_file_p;
    FILE  *out_file_p;
    char  infile[40];
    char  outfile[40];
    char ch = '\0';
    int  hbcount =0;
    if (argc != 3 ) {       //  Usage 
        fprintf(stderr,"USAGE: hi_bit_remove infile outfile\n");
        exit(81);
    } 
  
 //  CLEAN UP 
    strcpy(infile, argv[1]);
    infile[strlen(infile)] = '\0'; // remove end garbage 

    strcpy(outfile, argv[2]);
    outfile[strlen(outfile)] = '\0'; // remove end garbage 

	in_file_p = fopen(infile, "rb");
	out_file_p = fopen(outfile, "wb+");

    while(1) {
        ch = fgetc(in_file_p);
        if (ch == EOF) {
            break;
        }
		if (((ch & 0x80) != 0)) {
            hbcount++;
			// printf("This is a high bit character: %x\n", ch);
		} else {
			// printf("%c", ch);
			fputc(ch, out_file_p);
		}
    }
    printf("Found %d High Bit Characters in the file\n", hbcount);
	fclose(in_file_p);
	fclose(out_file_p);
	return(0);
}
