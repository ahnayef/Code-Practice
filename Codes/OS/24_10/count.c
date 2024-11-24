/*Copyright: Note that this program was written/prepared by last year CISC324-instructor Prof. Dorothea Blostein (Winter 2018)
/*In this year we are just using that program to implement the complete Lab.




/* This c program repeatedly does the following:
 *      - Read a value from file "nums".
 *      - Increment the value.
 *      - Write the value back to file "nums".
 */
#include <stdio.h>
#define NUM_INCREMENTS 5000

void main()
{
    FILE *filePointer; /* Used to access file "nums" */
    int value;         /* The value read from file "nums" */
    int i;             /* Loop counter */
    int scan_result;   /* The value returned by the fscanf function */

    /* Open file "nums".  Unix command "man fopen" describes fopen.  "r+" opens a file for
     * update (reading and writing).  If the file does not exist, fopen returns NULL.  In
     * that case, fopen with "w+", creates a file named "nums".   */
    filePointer = fopen("nums", "r+");
    if (filePointer == NULL)
    {
        filePointer = fopen("nums", "w+"); /* create a file "nums" and write zero into it */
        rewind(filePointer);
        fprintf(filePointer, "%6d", 0);
    }

    /* This loop executes 5000 times, reading a value, writing the incremented value. */
    for (i = 0; i < NUM_INCREMENTS; i++)
    {
        /* Rewind the file, and read a value.  See "man rewind", "man fscanf".  The fscanf is
         * in a loop, in case another process is in the middle of writing a value to "nums".
         * In that case, we cannot read a value and fscanf returns NULL (-1).    */
        rewind(filePointer);
        scan_result = 0;
        while (scan_result != 1)
        {
            scan_result = fscanf(filePointer, "%d", &value);
        }

        /* Write the new value to "nums". Use six characters, "%6d". This prevents a
         * mixup such as: the file contains 1265 and we write 698 so the result looks like
         * 6985 because the last digit was not overwritten or erased. */
        value++; /* increment the value */
        rewind(filePointer);
        fprintf(filePointer, "%6d", value);
    } /* for i */

    fclose(filePointer);
    printf("Count process is done\n");
} /* main */