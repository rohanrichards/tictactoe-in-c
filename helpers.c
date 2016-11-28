/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include "helpers.h"

/**
 * @file helpers.c contains all functions used in this program that don't
 * nicely fit into another module. For example, input/output functions and
 * validation functions.
 **/


/**
 * Checks @param string to see if the last character is a newline (\n).
 * @param is the length of the string (usually strlen() )
 * @return BOOLEAN TRUE if there is overflow, after clearing the overflow
 * @return BOOLEAN FALSE if no overflow, after removing the newline char
**/
BOOLEAN checkForOverflow(char * string, int len)
{
    BOOLEAN rs = FALSE;

    if(string[len-1] == '\n')
    {
        string[len-1] = 0;
    }
    else
    {
        read_rest_of_line();
        rs = TRUE;
    }
    return rs;
}

/**
 * clears the input buffer when there is leftover input in the buffer. 
 * This function should only be called when there is leftover input in the 
 * incoming buffer. Please refer to the fgets manpage (man fgets) on the 
 * university linux servers.
 **/
void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch != '\n' && ch != EOF);
    clearerr(stdin);
}

void clearScreen(void)
{
    int i = 0;
    for(i = 0; i < SCREENHEIGHT; i++)
    {
        printf("\n");
    }
}
