/* array_to_zero.c
 *
 *
 * Exercise 13-1: Write a program that uses pointers to set each element of an
 * array to zero.
 *
 *
 *
 *
 */

#include<stdio.h>
#define SZ 15 // Some arbitray size

int main() {

	int my_arr[SZ]; // Int Array
	int *my_ptr;    // Int Pointer
    int c = 0;

    printf("Before Initialization:\n");
    for (c = 0; c < SZ; c++) {
		printf("my_arr[%d] = %d\n", c, my_arr[c]);
	}

    printf("After Initialization:\n");
	my_ptr = my_arr;
	for (c = 0; c < SZ; c++) {
		*my_ptr++ = 0;  // Here's the pointer being used to set array
		printf("my_arr[%d] = %d\n", c, my_arr[c]);
	}
		
	return(0);
}
