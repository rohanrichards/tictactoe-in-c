/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "shared.h"

/** @file helpers.h contains the constants and data structure definitions
 * required for any functions defined in @ref helpers.c
 **/ 
 
 #ifndef HELPERS_H 
 #define HELPERS_H

/**
 * enumeration that represents the various outcomes of an i/o operation
 **/
enum input_result
{
        /**
         * the input/output operation failed
         **/
        FAILURE,

        /**
         * the input/ouput operation succeeded
         **/
        SUCCESS,

        /**
         * the user pressed ctrl-d or 'enter' at the beginning of a line
         **/
        RTM
};

#define SCREENHEIGHT 100

/*
 * Extra characters required for user input
 * usually nul terminator + newline character from fgets
 */
#define I_EXTRA 2

BOOLEAN checkForOverflow(char *, int);
void read_rest_of_line(void);
void clearScreen(void);
#endif
