/*
 *
 *  Exercise 7-3: A serial transmission line can transmit 960 characters each second.
 *  Write a program that will calculate the time required to send a file, given
 *  the file's size. Try the program on a 400MB (419,430,400-byte) file.
 *  Use appropriate units.  (A 400MB file takes days.)
 *  
 *
 */


#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
 
int  main(int argc, char **argv)
{
    struct stat  st;
    while (argc-- > 1) {
        if (lstat(argv[argc], &st) == -1)
            fprintf(stderr, "%s\n", strerror(errno));
        else {
            fprintf(stdout, "Links\tUid\tGid\tSize\tName\n");
            fprintf(stdout, "%d\t%d\t%d\t%d\t%s\n", st.st_nlink,
            st.st_uid, st.st_gid, st.st_size,
            argv[argc]);
        }
    }
    return 0;
}
