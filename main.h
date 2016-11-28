/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "game.h"
#include "player.h"
#include "scoreboard.h"
#include "helpers.h"

#include "menu.h"

#ifndef MAIN_H
#define MAIN_H

/**
 * This is used to handle menu navigation
 * the show menu option is hidden from the user and cannot be
 * actively selected, it is used by the system to handle RTM requests
 * and if in this state the menu is simply redrawn
**/
enum menuchoice
{
    PLAY_GAME,
    SHOW_HIGHSCORE,
    QUIT_GAME,
    SHOW_MENU
};
/**
 * @file main.h contains any data structures or constants you might want to
 * introduce to manage the main menu
 **/

#endif
