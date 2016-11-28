#include <string.h>
#include "shared.h"
#include "options.h"
#include "checker.h"
#include "utility.h"

#ifndef MENU_H
#define MENU_H
/**
 * @file menu.h contains the declaration of datastructures and function 
 * prototypes required for managing the menu system
 **/

/**
 * the length of text for each menu item
 **/
#define MENU_TEXT_LEN 40
/**
 * how many items are in the menu
 **/
#define NUM_MENU_ITEMS 7

    /**
     * represents a menu item in our array with a pointer to the function that 
     * implements this job and a string that contains the menu text for this 
     * menu item
     **/
    struct menu_item
    {
         /** 
         * a pointer to the function that implements this menu item 
         **/
         BOOLEAN (*checker_func)(struct checker_system*);
         /** 
         * the text to be displayed for this menu item 
         **/
         char text[MENU_TEXT_LEN+1];
    };

    /**
     * function that initialises each element of the the menu array to:
     * <ul>
     *    <li>contain a pointer to the function that implements that menu item</li>
     *    <li>contain the text to be displayed for that menu item</li>
     * </ul>
     **/
void init_menu(struct menu_item *);

/**
 * function that displays the menu to the user
 **/
void display_menu(struct menu_item *);

#endif
