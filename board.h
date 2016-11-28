/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards 
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include "shared.h"
#include "helpers.h"
#include <stdio.h>

/** @file board.h contains constants, data structures and prototypes
 * for the managing of the @ref game_board
 **/

#ifndef BOARD_H
#define BOARD_H
/**
 * the width of the game board
 **/
#define BOARDWIDTH 3

/**
 * the height of the game board
 **/
#define BOARDHEIGHT 3

/**
 * the width of the entire board when displayed - required by putline()
 **/
#define TICTACTOEWIDTH 15

/**
 * the width of a column when displayed - requried by putspaces()
 **/
#define COLUMNWIDTH 3

/**
 * create a new type called a game_board which is a 2d array of @ref cell
 * where its width is @ref BOARDWIDTH and its height is @ref BOARDHEIGHT
 **/
typedef enum cell game_board[BOARDHEIGHT][BOARDWIDTH];

/**
 * initialises the game board to an empty board.
 **/
void init_board(game_board *);

/** 
 * displays the game board as per the assignment requirement
 * ``display board''
 **/ 
 void display_board(game_board); 
 #endif
