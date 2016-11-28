#include <stdlib.h>
#include <stdio.h>

#ifndef CHECKER_H
#define CHECKER_H
/**
 * @file checker.h contains any declarations and data structures required for 
 * checker.c
 **/

/**
 * forwards declaration of the word_list as we need to know about it in this 
 * file to declare some pointers
 **/
struct word_list;

/**
 * the heart of our system - contains a pointer to the word_list and a pointer
 * to the dictionary file name for saving later
 **/
struct checker_system
{
        /**
         * a pointer to our word list
         **/
        struct word_list * list;
        /**
         * the name of our dictionary file for saving later
         **/
        const char * word_file;
};

/*
 * Initializes a struct_checker with an empty/initialized struct word_list
 */
void init_checker(struct checker_system *);
#endif
