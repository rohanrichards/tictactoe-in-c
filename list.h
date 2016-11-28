#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "shared.h"
#include "utility.h"


#ifndef LIST_H
#define LIST_H
/**
 * @file file that contains the data structures for managing the word lists 
 * used by the program.
 **/

/**
 * what kind of list is this?
 **/
enum list_type
{
        /**
         * a dictionary list loaded from a dictionary file
         **/
        T_DICT,
        /**
         * a spell checking list loaded from a file you are spell checking
         **/
        T_CHECK
};

/**
 * words are the data in our list
 **/
struct word
{
        /**
         * the actual word itself
         **/
        char * word;
        /**
         * how many times we have encountered that word
         **/
        unsigned count;
};

/**
 * nodes are the links in our list
 **/
struct list_node
{
        /**
         * a pointer to the next list_node in the list
         **/
        struct list_node * next;
        /**
         * a pointer to the data node 
         **/
        struct word * data;
};

/**
 * the list itself it carries around all the data for maintaining the linked
 * list
 **/
struct word_list
{
        struct list_node * head;
        size_t num_words;
        enum list_type type;
};

BOOLEAN listAdd(struct word_list *, struct word *);

BOOLEAN listDelete(struct word_list *, char *);

void listFree(struct word_list *);

void listPrintAll(struct word_list *);

#ifdef WITH_LEVENSHTEIN
#define THRESHOLD 2
/**
 * defines the "edit distance" between two words. The levenshtein algorithm
 * is a well-known algorithm for finding the edit distance between two words - 
 * how many changes do I need to make to one word to make it the other word.
 **/
int levenshtein(const char * , int , const char * , int );
#endif /* WITH_LEVENSHTEIN */

#endif/* LIST_H */
