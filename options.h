#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "checker.h"
#include "shared.h"
#include "utility.h"
#include "list.h"
#ifndef OPTIONS_H
#define OPTIONS_H
#define ONE_LETTER 1

/**
 * @file options.h defines the main options that need to be implemented as part
 * of the assignment.
 **/

/**
 * performs a spellcheck over a file. Prompt the user for a file to spell check
 * and then open this file. You then want to tokenize this file at whitespace
 * characters and add each word to the word list. Also store in the word list
 * how many occurences of that word exist in the text file you are spell 
 * checking. 
 *
 * You then want to search for each word in the word list in the dictionary 
 * list. Print out each word that does not exist in the dictionary but exists in
 * the text.
 *
 * If the word does exist in the dictionary list, add the count for that word 
 * from the spell checked list to the dictionary list.
 *
 * This described the basic functionality for this function - please see the 
 * bonus marks section of the assignment specification for details on an 
 * optional extension to this option.
 **/
BOOLEAN spell_check(struct checker_system*);

/**
 * prompt the user for a new word to add to the dictionary. Validate that this
 * is a valid word (no punctuation, numbers or white space). If it is a valid
 * word, add it to the list. If it is not a valid word, reject it with an 
 * appropriate error message
 **/
BOOLEAN add_word(struct checker_system*);

/**
 * prompt the user for a word to delete from the dictionary. Next, search for 
 * the word in the dictionary. If it is not found then display an error 
 * message to indicate this and return FALSE. If it is found, delete it and 
 * return TRUE
 **/
BOOLEAN del_word(struct checker_system*);

/**
 * ask the user for a letter to print the stats about. Search the dictionary
 * for the letter specified and print out the stats (count of number of times
 * encountered) for each word starting with that letter.
 **/
BOOLEAN stats_report(struct checker_system *);

/**
 * reset the count for each word in the dictionary to 0
 **/
BOOLEAN clear_stats (struct checker_system *);

/**
 * save the dictionary back to the dictionary file and exit the program. Make
 * sure you free all memory used by the program and close all files.
 **/
BOOLEAN save_and_exit(struct checker_system*);

/**
 * Exit the program without saving the dictionary. Make sure you free all memory
 * used by the program as well as closing all files.
 **/
BOOLEAN quit(struct checker_system*);
#endif
