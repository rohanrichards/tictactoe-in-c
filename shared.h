/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
/**
 * @file shared.h contains data structure and constant definitions required
 * across the system
 **/

#ifndef SHARED_H
#define SHARED_H
/**
 * definition of the BOOLEAN data type as an enumeration
 **/
typedef enum
{
    FALSE, TRUE
} BOOLEAN;

/**
 * a cell is an enumeration but notice in this case that I have assigned 
 * "int" values for each element of the enumeration. Remember how an 
 * enumeration is a sequence of related integers?
 **/
enum cell
{
        /**
         * NOUGHT CHAR
         **/
        C_NOUGHT='0',
        /**
         * CROSS CHAR
         **/
        C_CROSS='X',
        /**
         * EMPTY CELL
         **/
        C_EMPTY=' ',
        /**
         * sentinel value we can return to indicate an invalid cell 
         * reference
         **/
        C_INVALID=-1
};

#endif
