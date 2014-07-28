/* file-line-count.c 
 *
 *  This program counts the number of lines in file and displays it.
 *
 *
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(int argc, char *argv[]) {

    FILE *in_file_ptr;
    char filename[80];
    int char_ct = 0;
    int line_ct =0;
    char ch = '\0';

    if (argc != 2 ) {       //  Usage 
        printf("USAGE: file-line-count filename \n");
        return(-1);
    } 

    strcpy(filename, argv[1]);
    filename[strlen(filename)] = '\0'; // remove end garbage 

    in_file_ptr = fopen(filename, "rb");

    if (in_file_ptr == NULL) {
        printf("did not find file: %s\n", filename);
        return(-2);
    }
 
//***********  fgetc  **************************/

    while(1) {
        ch = fgetc(in_file_ptr);
        if (ch == EOF) 
            break;
        if (ch == '\n') {
            // printf("[NEWLINE]");
            line_ct++;
        }

         printf("%c", ch);
        ++char_ct;
    }
        printf("Letter Count: %d\tLine Count: %d\n", char_ct, line_ct); 

    fclose(in_file_ptr);
    return(0);
}
