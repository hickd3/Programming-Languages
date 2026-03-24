/*
* Dean Hickman
* CS333
* 5/20/24
* sort.c
*
*
*/

/* Write a program that sorts a random array in a way that the even numbers appear first and the odd numbers appear later. */

/**
 * Given an array of random integers, sort it in such a way that the even 
 * numbers appear first and the odd numbers appear later. The even numbers 
 * should be sorted in descending order and the odd numbers should be sorted 
 * in ascending order.
 *
 * Ying Li
 * 08/02/2016
 */

#include <stdio.h>
#include <stdlib.h>

/* the comparator funciton used in qsort */
int comparator (const void *p, const void *q) {
	// Dean's code here
        int left = *(const int *)p;
        int right = *(const int *)q; 
    

     /* We are using the bitwise AND and this allows us to use the conditional while evaluating booleans and integer values at the same time */

    //see if botha re odd then place the lesser first
    if ((left & 1) && (right & 1))
        return (left - right);
  
    //both values are even then place the greater first
    if (!(left & 1) && !(right & 1))
        return (right - left);
  
    //if the left value is the only even put it first
    if (!( left & 1))
        return -1;
  
    //if the left value is odd then put the right value first
    return 1;
}

int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
	
	int size = sizeof(ary) / sizeof(int);
	
	qsort((void *) ary, size, sizeof(int), comparator);
	
	printf("The sorted array is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	
	return 0;
}
