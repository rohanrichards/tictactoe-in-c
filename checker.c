/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #3
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "checker.h"
#include "list.h"
#include "menu.h"
#include "string.h"
/**
 * @mainpage This is the main html documentation of assignment 3 for
 * CPT220 - Programming in C for study period 4, 2015. You will find
 * here a description of the functions that you need to implement for
 * your assignment.
 *
 * Please note that this should not be your first stop when starting
 * your assignment. Please read the assignment 1 specifications that
 * are available on blackboard before reading this documentation. The
 * purpose of this documentation is to clarify the actual individual
 * requirements.
 *
 * This site presents you with the documentation for each function
 * that you need to implement broken down by the file that they exist
 * in. Please go to the Files tab and click on the file you wish to
 * get more information about and then click on that file. An
 * explanation of each function implemented in that file will be
 * displayed.
 **/

/**
 * @file checker.c
 * contains the main function and any related helper files
 **/

/**
 * the entry point for your program. From here you should initialise 
 * datastructures and load data into the system and then manage the menu
 * loop. Once the user has decided to quit, you should make sure any resources
 * required by the system are released and cleaned up. 
 **/
int main(int argc, char** argv)
{
        /* array of menu items including the text for each menu item and a 
         * pointer to the callback function
         */
        struct menu_item menu[NUM_MENU_ITEMS];
        BOOLEAN quit = FALSE;
        /* holds all the data for our system */
        struct checker_system checker;

        /* pointer to the file path from argv[1] */
        char * filePath;

        /* check for the correct number of command line argumens */
        if(argc !=2)
        {
            printf("Error: Wrong number of args\n");
            printf("Correct format is ./checker [relative/path/to/file.txt]\n");
            return EXIT_FAILURE;
        }

        /* set our filePath pointer to the argv pointer */
        filePath = argv[1];
        
    	/* set up the checker and the menu  */
        system_init(&checker);
        init_menu(menu);

        /* load the data into the system */
        load_data(&checker, filePath);

        /* print out the size of our dictionary */
        printf("words loaded from dictionary file: %zu\n", 
            checker.list->num_words);
        
        /* initialize the menu data structure */
                /* get choice from the user */
	                /* run the requested checker function */
                        
        return EXIT_SUCCESS;
}
