#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "shared.h"
#include "checker.h"


#ifndef UTILITY_H
#define UTILITY_H
/**
 * @file utility.h contains the data structure definitions and prototypes 
 * required for helper functions and i/o for the program
 **/
#define MAX_WORD_LEN 30
#define EXTRACHARS 2

/**
 * enumeration that defines the possible outcomes of an i/o operation
 **/
enum input_result
{
        /**
         * it was successful!
         **/
        SUCCESS,
        /**
         * it failed
         **/
        FAILURE,
        /**
         * the user pressed enter or ctrl-d on a new line
         **/
        RTM
};

/**
 * initialise the system to a known safe state
 **/
BOOLEAN system_init(struct checker_system *);

/**
 * load the specified dictionary file into a linked list
 **/
BOOLEAN load_data(struct checker_system*, const char *);

/**
 * free all data allocated for the system
 **/
void system_free(struct checker_system*);

#endif
