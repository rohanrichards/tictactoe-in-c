/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include "main.h"

/** @mainpage CPT220 - Assignment 1 documentation.
 *
 * This is the main html documentation of assignment 1 for CPT220 - Programming
 * in C for study period 4, 2015. You will find here a description of the
 * functions that you need to implement for your assignment.
 *
 * Please note that this should not be your first stop when starting your
 * assignment. Please read the assignment 1 specifications that are available
 * on blackboard before reading this documentation. The purpose of this
 * documentation is to clarify the actual individual requirements.
 *
 * This site presents you with the documentation for each function that you
 * need to implement broken down by the file that they exist in. Please go to
 * the <b>Files</b> tab and click on the file you wish to get more information
 * about and then click on that file. An explanation of each function
 * implemented in that file will be displayed.
 * 
 **/

/**
 * @file main.c this file contains the main function call and any supporting
 * functions you may choose to implement such as for management of the main
 * menu.
 **/

/**
 * Entry point into the program - displays the main menu and controls the
 * overall flow of the program. Please interpret all comments without code in
 * this as hints at getting started with implementing this program - they are
 * the "larger dotpoints* for how the main menu is meant to work.
 **/
int main(void)
{
        /* variable that holds the menu choice selected by the user */
        enum menuchoice choice = SHOW_MENU;

        /* scoreboard where the most recent games played is stored */
        score scoreboard[NUM_SCORES];

        /* structs representing the data for the human and computer players */
        struct player computer, human;
        enum cell playerToken;
        
        enum input_result ioResponse = FAILURE;

        /* a pointer to the winner - this will be NULL if the game was a draw 
         * or the human player chose to quit the game half way through
         */
        struct player *winner;
        
        /* initialise the scoreboard */
        init_scoreboard(scoreboard);
        
        /*
         * this is the menu loop, it redraws the menu and 
         * contains the other loops depending on menu_choice choice
         */
        while(choice == SHOW_MENU)
        {
            clearScreen();
            drawMenu();
            choice = handleMenuInput();

            while(choice == PLAY_GAME)
            {
                /* play game option chosen */

                /* init RNG using current time */
                srand(time(0));
                
                /* get player name and init human struct */
                ioResponse = init_human_player(&human, &playerToken);
                
                /*player name entered correctly*/
                if(ioResponse == SUCCESS)
                {
                    init_computer_player(&computer, playerToken);   
                    winner = play_game(&human, &computer);

                    if(winner == NULL)
                    {
                        /*we get here if game was draw or exited by user*/
                        choice = SHOW_MENU;
                        continue;
                    }
                    else
                    {
                        /* try to add the winner to the scoreboard */
                        if(add_to_scoreboard(scoreboard, winner))
                        {
                            printf("%s was added to the scoreboard!\n",
                                    winner->name);
                            choice = SHOW_MENU;
                            sleep(2);
                            continue;
                        }
                        else
                        {
                            printf("Sorry, %s didnt fit on the scoreboard!\n",
                                    winner->name);
                            choice = SHOW_MENU;
                            sleep(2);
                            continue;
                        }
                    }
                }
                else if(ioResponse == RTM)
                {
                    /* player didnt enter name but used quit option*/
                    choice = SHOW_MENU;
                    continue;
                } 
            }

            while(choice == SHOW_HIGHSCORE)
            {
                display_scores(scoreboard);
                choice = SHOW_MENU;
            }

            while(choice == QUIT_GAME)
            {
                /* 
                 * just breaks out of the menu loop
                 * which should fall through to exit_success below
                 */
                break;
            }

        }        
    return EXIT_SUCCESS;
}
