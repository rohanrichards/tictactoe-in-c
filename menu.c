#include "menu.h"

/**
 * @file menu.c contains the function implementations for managing the menu
 * system
 **/

/**
 * @param menu the array of menu items passed in to be initialized
 **/
void init_menu(struct menu_item * menu)
{
    int loopCounter;

    BOOLEAN (*menuFunctions[NUM_MENU_ITEMS])(struct checker_system*) = 
    {
        spell_check,
        add_word,
        del_word,
        stats_report,
        clear_stats,
        save_and_exit,
        quit
    };
    char * menuText[NUM_MENU_ITEMS] = 
    {
        "(1) Spell check a file",
        "(2) Add a new word to the dictionary",
        "(3) Delete a word from the dictionary",
        "(4) Display word stats",
        "(5) Clear word stats",
        "(6) Save dictionary and exit",
        "(7) Quit without saving"
    };
    memset(menu, 0, sizeof(struct menu_item) * NUM_MENU_ITEMS);

    for(loopCounter = 0; loopCounter < NUM_MENU_ITEMS; loopCounter++)
    {
        menu[loopCounter].checker_func = menuFunctions[loopCounter];
        strcpy(menu[loopCounter].text, menuText[loopCounter]);
    }
}

/**
 * @param menu the menu array to display the contents of 
 **/
void display_menu(struct menu_item * menu)
{
}
