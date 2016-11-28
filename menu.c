/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/

#include "menu.h"

/*
 * menu.c just handles the main menu functions
 */


/*
 * simply draws the main menu, usually called after clearScreen()
 */
void drawMenu(void)
{
    /*print the menu*/
    printf("Welcome to tick-tack-toe\n");
    printf("------------------------\n");
    printf("1. Play Game\n");
    printf("2. Display High Scores\n");
    printf("3. Quit Game\n");
    printf("------------------------\n");
}

/*
 * this handles the input from the main menu
 * uses fgets and strtol and returns the menu selection as an int 
 */
int handleMenuInput(void)
{
    enum input_result menuSuccess = FAILURE;
    char menuInput[MI_LENGTH + I_EXTRA];
    int menuInputAsInt = 0;
    char *end;

    printf("Enter your menu selection(1-3):");

    while(!menuSuccess)
    {
            if(fgets(menuInput, MI_LENGTH+I_EXTRA, stdin) == NULL)
            {
                /*
                 * catches ctrl+d (i think)
                 * set input as quit (3rd option)
                 * and break out of the loop
                 */
                 
                menuInputAsInt = 3;
                menuSuccess = TRUE;
                continue;
            }

            /*
             * check for overflow
             */
            if(checkForOverflow(menuInput, strlen(menuInput)))
            {
                clearScreen();
                drawMenu();
                printf("ERROR:\nPlease enter only one number:");
                menuSuccess = FAILURE;
                continue;
            }

            /*string to number conversion here*/
            menuInputAsInt = (int) strtol(menuInput,  &end, 10);
            
            /* 
             * make sure it was actually a number
             * no need to worry about the length
             * as it was forced into 1 char earlier
             */
            if(menuInput == end || *end != 0)
            {
                clearScreen();
                drawMenu();
                printf("ERROR:\nPlease enter a number:");
                menuSuccess = FAILURE;
                continue;
            }

            /*
             * make sure its within bounds
             */
            if(menuInputAsInt > 3 || menuInputAsInt < 1)
            {
                clearScreen();
                drawMenu();
                printf("ERROR:\nPlease enter a number between 1-3:");
                menuSuccess = FAILURE;
                continue;
            }

            menuSuccess = SUCCESS;
    }

    /*
    * menuInputAsInt will be 1-3 we need 0-2 returned
    * so return menuInputAsInt-1
    */    
    return (menuInputAsInt - 1);
}
