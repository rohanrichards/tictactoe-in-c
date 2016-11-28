/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan M Richards 
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
#include "game.h"
#include "player.h"

/**
 * @file game.c contains the functions required for management of the game
 * while it is being played.
 **/

/**
 * @param human a pointer to the human player struct
 * @param computer a pointer to the computer player struct
 * @return a pointer to the winning player or NULL if there was no
 * winner
 **/
struct player * play_game(struct player * human, struct player * computer)
{
     /*struct to hold who's currently taking a turn*/
    struct player * currentPlayer;
    struct player * idlePlayer;   
    game_board board;
    enum input_result ioResult;
    enum game_result winnerCheck = GR_NOWINNER;
    
    /*
     * set the player who was given the nought token to get the first turn
     */
    if(human->token == C_NOUGHT)
    {
        currentPlayer = human;
        idlePlayer = computer;
    }
    else
    {
        currentPlayer = computer;
        idlePlayer = human;
    }

    init_board(&board);

    /*
     * this could be considered the actual game loop
     */
    while(winnerCheck == GR_NOWINNER)
    {
        display_board(board);
        printf("%s's turn\n", currentPlayer->name);
        
        ioResult = take_turn(board, currentPlayer);

        if(ioResult == RTM)
        {
            /* exits to menu */
            return NULL;
        }   

        display_board(board);
        
        winnerCheck = test_for_winner(board, currentPlayer->token);
        if(winnerCheck != GR_NOWINNER)
        {
            /* this means winner/draw so we exit the game loop*/
            break;
        } 
        
        swap_players(&currentPlayer, &idlePlayer);
    }
    if(winnerCheck == GR_DRAW)
    {
        printf("GAME WAS A DRAW!\n");
        sleep(2);
        return NULL;
    }
    else
    {
        /* return the winner for the highscore function*/
        printf("THE WINNER WAS: %s!\n", currentPlayer->name);
        sleep(2);
        return currentPlayer;
    }
}

/**
 * @param first the first player passed in
 * @param second the second player passed in
 **/
void swap_players(struct player** first, struct player** second)
{
    struct player * temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * @param board the game_board passed in
 * @param cur_token
 **/
enum game_result test_for_winner(game_board board, enum cell cur_token)
{
    int y,x;
    enum cell winnerType = C_EMPTY;
    BOOLEAN emptyCellFound = FALSE;
    
    /*
     * here we cycle through all the y cells, checking the x's
     * this is looking for horizontal wins
     * we use cur_token to filter out C_EMPTY
     * then cell1 == cell2 && cell1 == cell3
     */
    for(y = 0; y < BOARDHEIGHT; y++)
    {
        if(board[y][0] == cur_token &&
            board[y][0] == board[y][1] && board[y][0] == board[y][2])
        {
            winnerType = board[y][0];
        }
    }
    
    /*
     * same check as above but we check all the x cells against each y
     * this is for vertical wins
     */
    for(x = 0; x < BOARDWIDTH; x++)
    {
        if(board[0][x] == cur_token &&
            board[0][x] == board[1][x] && board[0][x] == board[2][x])
        {
            winnerType = board[0][x];
        }
    }

    /*
     * here we check each diagonal
     */
    if(board[0][0] == cur_token &&
        board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        winnerType = board[0][0];
    }
    else if(board[2][0] == cur_token &&
        board[2][0] == board[1][1] && board[2][0] == board[0][2])
    {
        winnerType = board[2][0];
    }

    /* 
     * now we simply confirm that the board still has some empty cells
     * this is to check for stalemate
     */
    for(y = 0; y < BOARDHEIGHT; y++)
    {
        for(x = 0; x < BOARDWIDTH; x++)
        {
            if(board[y][x] == C_EMPTY)
            {
                emptyCellFound = TRUE;
            }
        }
    }
    
    /*
     * finally just decide on the return value
     * GR_NOWINNER just means no winner *yet* and take another turn
     */
    if(winnerType == C_NOUGHT)
    {
        return GR_NOUGHT;
    }
    else if(winnerType == C_CROSS)
    {
        return GR_CROSS;
    }
    else if(winnerType == C_EMPTY && !emptyCellFound)
    {
        return GR_DRAW;
    }
    else
    {
        return GR_NOWINNER;
    }
}
