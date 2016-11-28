#include "options.h"

/**
 * @file options.c contains the implementations of all functions for implementing
 * the options as specificied in the assignment specification
 **/

/**
 * @param checker datastructure that holds all data for managing the system
 * @return @ref TRUE when we successfully spellcheck a file and @ref FALSE
 * otherwise
 **/
BOOLEAN spell_check(struct checker_system* checker)
{
        return FALSE;
}

/**
 * @param checker datastructure that holds all the data for the system
 **/
BOOLEAN add_word(struct checker_system* checker)
{
        return FALSE;
}

/**
 * @param checker datastructure that holds all the data for the system
 **/
BOOLEAN del_word(struct checker_system* checker)
{
        return FALSE;
}

/**
 * @param checker datastructure that maintains the data for the system
 **/
BOOLEAN stats_report(struct checker_system * checker)
{
	return FALSE;
}

/**
 * @param checker the datastructures that help us manage the overall system
 **/
BOOLEAN clear_stats (struct checker_system * checker)
{
        return FALSE;
}

/**
 * @param checker the datastructures that help us manage the system
 **/
BOOLEAN save_and_exit(struct checker_system* checker)
{
        return FALSE;
}

/**
 * @param checker the datastructures that help us manage the system
 **/
BOOLEAN quit(struct checker_system* checker)
{
	return FALSE;
}
