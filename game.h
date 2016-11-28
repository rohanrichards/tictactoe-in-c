/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards 
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "board.h"
#include "helpers.h"

/**
 * @file game.h contains the data structure definitions and function
 * prototypes required for the management of a game in play
 **/
#ifndef GAME_H
#define GAME_H
/**
 * forwards declaration of @ref player so that this module can accept
 * pointers to @ref player as a parameter
 **/
struct player;

/**
 * enumeration that defines that different states that a game can be in
 **/
enum game_result
{
        GR_NOUGHT, GR_CROSS, GR_DRAW, GR_NOWINNER
};

/** Manages the game loop.
 *
 * Firstly you want to initialise the ranom number generator. Next
 * you want to initialise the game board to empty.  After this, you
 * want to initialise the
 **/ 
 
 struct player * play_game(struct player * , struct player * );

/** implements a classic swap of two player pointers so that at
 * exit from this function the pointers point to the other player.
 **/

void swap_players(struct player**, struct player**);

/**
 * tests for a winner in the horizontal, vertical and diagonal directions
 **/
enum game_result test_for_winner(game_board, enum cell);
#endif
