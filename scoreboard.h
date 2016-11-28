/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards 
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include <stdio.h>
#include "shared.h"
#include "player.h"

/**
 * @file scoreboard.h contains the data structures and constants to support
 * managing the scoreboard in @ref scoreboard.c
 **/
#ifndef SCOREBOARD_H
#define SCOREBOARD_H

/* need both */
#include <string.h>
#include <strings.h>

/**
 * the number of scores stored in the score list
 **/
#define NUM_SCORES 10

/**
 * an alias for struct player -> a player struct in a sense holds the data
 * for a score
 **/
typedef struct player score;

/**
 * initialize the scoreboard to be empty
 **/
void init_scoreboard(score *);

/**
 * add the player (score) passed in to the scoreboard sorted by name
 **/
BOOLEAN add_to_scoreboard(score *, struct player*);

/**
 * display the scores in the scoreboard. Stop when you come to an empty 
 * score
 **/
void display_scores(score *);
#endif
