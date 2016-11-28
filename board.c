/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards 
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include "board.h"

/**
 * @file board.c contains function implementations for managing the @ref
 * game_board
 **/

/**
 * @param board the game board to display
 **/
void init_board(game_board * board)
{
    int y,x;
    for(y = 0; y < BOARDHEIGHT; y++)
    {
        for(x = 0; x < BOARDWIDTH; x++)
        {
            (*board)[y][x] = C_EMPTY;
        }
    }
}

/**
 * @param board the game board to display
 **/
void display_board(game_board board)
{
    int y,x;

    clearScreen();

    printf("|---------------|\n");
    printf("|   | A | B | C |\n");
    printf("|---------------|\n");


    for(y = 0; y<BOARDHEIGHT; y++)
    {
        printf("| %i ",y+1);

        for(x = 0; x<BOARDWIDTH; x++)
        {
            printf("| %c ", board[y][x]);
        }
        printf("|\n");
        printf("|---------------|\n");

    }
}
