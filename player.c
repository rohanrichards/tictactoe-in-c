/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include "player.h"

/**
 * @file player.c contains functions to manage the @ref player data structure
 * which represents either a @ref HUMAN or @ref COMPUTER player
 **/

/**
 * @param human a pointer to the human player's struct @param token a pointer
 * to where a copy of the human player's token is stored so it can be accessed
 * later @return a result status indicating whether i/o was successful or not
 * or if the user pressed enter or ctrl-d on an empty line.
 **/
enum input_result init_human_player(struct player * human, enum cell * token)
{
    char playerName[NAMELEN+I_EXTRA];
    enum input_result ioResult = FAILURE;
    enum cell randomNumber;

    while(ioResult == FAILURE)
    {
        /* get the players name and check for overflow*/
        printf("Enter your name (max 20 letters):");
        if(fgets(playerName, NAMELEN+I_EXTRA, stdin) == NULL)
        {
            /*
             * should catch ctrl+d
             */
            return RTM;
        }

        if(checkForOverflow(playerName, strlen(playerName)))
        {
            printf("ERROR - Too Long\n");
            continue;
        }
        
        /*catch any RTM attempts*/
        if(playerName[0] == '\n' || playerName[0] == 0)
        {
            return RTM;
        }

        /* name entered succesfully - will exit loop*/
        ioResult = SUCCESS;
    }

    /* successful name input */
    memset(human, 0, sizeof(struct player));
    strcpy(human->name, playerName);
    human->type = HUMAN;

    /*pick random cross or nought*/
    randomNumber = rand()%2;
    if(randomNumber)
    {
        human->token = C_NOUGHT; 
        *token = C_NOUGHT;
    }
    else
    {
        human->token = C_CROSS;
        *token = C_CROSS;
    }
    
    return SUCCESS;
}

/**
 * @param computer a pointer to the computer player struct @param token the
 * token for the human player - the computer one needs to be the opposite
 * @return an indication of i/o success or failure which in this case can be
 * safely ignored as there is no i/o. It is only part of the interface so that
 * human and computer functions are called in a uniform way.
 **/
enum input_result init_computer_player(struct player * computer, enum cell token)
{
    memset(computer, 0, sizeof(struct player));
    
    strcpy(computer->name, "Computer");
    computer->type = COMPUTER;
    
    if(token == C_NOUGHT)
    {
        computer->token = C_CROSS;
    }
    else
    {
        computer->token = C_NOUGHT;
    }
    return SUCCESS;
}

/**
 * @param player the player to display the name of @return a pointer to the
 * player's name
 **/
const char * player_to_string(const struct player* player)
{
        return player->name;

}

/**
 * @param board the gameboard to insert the token into @param player a pointer
 * to the player struct that represents the current player.  @return a value
 * indicating whether any i/o operations were successful
 **/
enum input_result take_turn(game_board board, struct player * player)
{
    char move[MOVELEN+I_EXTRA];
    char * toke1,* toke2;
    int moveX;
    int moveY;
    const char * delimFirst = ",";
    BOOLEAN moveSuccess = FALSE;
    
    if(player->type == HUMAN)
    {
        while(!moveSuccess)
        {
            printf("please enter your move (e.g a,1):");
            if(fgets(move, MOVELEN+I_EXTRA, stdin) == NULL)
            {
                /*
                 * catch ctrl+d
                 */
                return RTM;
            }
            
            if(checkForOverflow(move, strlen(move)))
            {
                printf("ERROR - too many characters\n");
                continue;
            }

            /* 
             *catch RTM command
             */
            if(move[0] == 0 || move[0] == '\n')
            {
                return RTM;
            }
            
            /*
             * tokenizaterize!
             */
            toke1 = strtok(move, delimFirst);
            toke2 = strtok(NULL, delimFirst);

            /*
             * rediculously complicated error checking!
             * first we check for null, catches anything missing commas etc.
             * then make sure the tokens are just one character catches
             * if the comma is in the wrong place etc.
             * see if we have two numbers or two letters
             */
            if( (toke1 == NULL || toke2 == NULL) ||
                (strlen(toke1)!=1 || strlen(toke2) != 1) ||
                (isdigit(*toke1) && isdigit(*toke2)) ||
                (isalpha(*toke1) && isalpha(*toke2)))
            {
                printf("ERROR - invalid input (x,y) or (y,x)\n");
                continue;
            }
            
            /*
             * check and set tokens in the correct order
             * required order is LETTER -> NUMBER
             */
            if(isdigit(*toke1))
            {
                char * temp = toke1;
                toke1 = toke2;
                toke2 = temp;
            }
            
            /*
             * make sure our letter is lower case or we get wrong number
             */
            *toke1 = tolower(*toke1);
            
            /*
             * now check tokens are within bounds
             */
            if((*toke1 < 'a' || *toke1 > 'c') ||
               (*toke2 < '1' || *toke2 > '3'))
            {
                printf("ERROR - out of bounds (a-c) (1,3)\n");
                continue;
            }
            
            /*
             * time to make them both into zero based numbers (0-2)
             */
            *toke1 -= 'a';
            *toke2 -= '1';

            /*
             * check if the space is empty
             */
            if(board[(int)*toke2][(int)*toke1] != C_EMPTY)
            {
                printf("ERROR - must move to empty cell\n");
                continue;
            }

            /*
             * if we get here then we can use tokens for the move
             * and the move is a success
             */
            moveSuccess = TRUE;
        }
        
        /*
         * we can FINALLY set the board location to the players token
         */
        board[(int)*toke2][(int)*toke1] = player->token;
        return SUCCESS;
    }
    else
    {
        /* computer turn logic in here */
        moveSuccess = FALSE;
        printf("Computer taking turn...\n");

        while(!moveSuccess)
        {
            moveX = rand()%3;
            moveY = rand()%3;

            if(board[moveY][moveX] != C_EMPTY)
            {
                continue;
            }

            board[moveY][moveX] = player->token;
            moveSuccess = TRUE;
        }
        sleep(2);
        return SUCCESS;
    }
}

