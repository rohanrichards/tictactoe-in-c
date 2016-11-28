/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include "scoreboard.h"

/**
 * @file scoreboard.c contains the implementation of functions to manage the
 * scoreboard
 **/

/**
 * @param scoreboard the scoreboard to initialise to an empty board
 **/
void init_scoreboard(score * scoreboard)
{
    memset(scoreboard, 0, sizeof(score)*NUM_SCORES);    
}

int compareStrings(const void *a, const void *b)
{

    return strcasecmp(((const score *) a)->name, ((const score *) b)->name);
}

/**
 * @param scoreboard the scoreboard to add the score to
 * @param winner the new score to add too the scoreboard
 * @return TRUE when a score is successfully added and FALSE otherwise
 **/
BOOLEAN add_to_scoreboard(score * scoreboard, struct player * winner)
{
    int entryCount = 0, i;
    
    /*
     * this little loop just counts the number of entries in the array
     * the count is used later in qsort as (size)
     * if we find an empty slot in the scoreboard then we just drop in
     * the newest winner to the empty slot and then sort the board
     */
    for(i = 0; i < NUM_SCORES; i++)
    {
        if(scoreboard[i].name[0] == 0)
        {
            entryCount++;
            scoreboard[i] = *winner;
            qsort(scoreboard, entryCount, sizeof(score), compareStrings);
            return SUCCESS;
        }

        entryCount++;
    }
    /* 
     * if we get here all 10 slots are full 
     * so we have to compare the *winner to last entry
     */
    if(strcmp(winner->name, scoreboard[NUM_SCORES-1].name) < 0)
    {
        /* new score name < last scoreboard name */
        scoreboard[NUM_SCORES-1] = *winner;
        qsort(scoreboard, entryCount, sizeof(score), compareStrings);
        return SUCCESS;
    }
    
    /* 
     * if we get to here the new winners name was too low
     * and the name didnt fit on the scoreboard
     */

    /* now we just have to sort the array */
    qsort(scoreboard, entryCount, sizeof(score), compareStrings);
    return FAILURE;
}

/**
 * @param scoreboard the scoreboard to display
 **/
void display_scores(score * scoreboard)
{
    int i;
    score * currentScore;
    char playerName[50], playerType[50], playerToken[50];
    
    /* used to capture RTM input */
    char dunceString[100];

    clearScreen();

    printf("TicTacToe Winners\n");
    printf("-----------------\n");
    printf("%-20s|%-15s|%-15s\n", "Name", "Player Type", "Token Type");
    printf("----------------------------------------"
            "-------------\n");
    for(i = 0; i < NUM_SCORES; i++)
    {
        currentScore = &(scoreboard)[i];
        
        /* check if name value is empty */
        if(currentScore->name[0] == 0)
        {
            strcpy(playerName, "-");
        }
        else
        {
            strcpy(playerName, currentScore->name);
        }
        
        /* check if type value is empty or print string version */
        if(currentScore->type == HUMAN)
        {
            strcpy(playerType, "Human");

        }
        else if(currentScore->type == COMPUTER)
        {
            strcpy(playerType, "Computer");
        }
        else
        {
            strcpy(playerType, "-");
        }
        
        /* check if token value is empty, or print string version */
        if(currentScore->token == C_NOUGHT)
        {
            strcpy(playerToken, "Noughts");
        }
        else if(currentScore->token == C_CROSS)
        {
            strcpy(playerToken, "Crosses");
        }
        else
        {
            strcpy(playerToken, "-");
        }

        printf("%-20s|%-15s|%-15s|\n", playerName, playerType, playerToken);
    }
    printf("Press [ENTER] or [CTRL+D] to return to menu...");
    if(fgets(dunceString, sizeof(dunceString), stdin) == NULL)
    {
        return;
    }
    checkForOverflow(dunceString, strlen(dunceString));
}
