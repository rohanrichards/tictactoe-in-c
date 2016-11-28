#include "utility.h"
#include "list.h"

/**
 * @file utility.c contains implementations of helper functions and i/o functions
 * for the program
 **/

/**
 * clear the input buffer when the user has entered more data than allowed.
 * You should only call this when you have detected leftover input in the 
 * input buffer
 **/
static void read_rest_of_line(void)
{
	int ch;
	while(ch = getc(stdin), ch != '\n' && ch != EOF)
		;
	clearerr(stdin);
}

/**
 * @param checker the datastructure that holds all the data for the
 * system
 **/
BOOLEAN system_init(struct checker_system * checker)
{
    struct word_list * list;

    if( ( list = malloc( sizeof( struct word_list ) ) ) == NULL)
    {
        perror("Memory Allocation Error");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->num_words = 0;
    list->type = T_DICT;

    checker->list = list;
    checker->word_file = NULL;
    
    return TRUE;
}

/**
 * @param checker the datastructure that maintains all the information 
 * about the system
 * @param filename the filename to load the dictionary from
 **/
BOOLEAN load_data(struct checker_system* checker, const char * filename)
{
    FILE * file;
    char str[MAX_WORD_LEN + EXTRACHARS];

    /* try to open the file to check its there */
    if( (file = fopen( filename, "r" ) ) == NULL)
    {
        perror("File Error");
        exit(EXIT_FAILURE);
    }

    printf("dictionary file found, path is: %s\n", filename);
    
    while( ( fgets(str, MAX_WORD_LEN + EXTRACHARS, file) ) != NULL )
    {
        struct word * newWord;
        BOOLEAN wordValid = FALSE;

        /* validate the word */
        wordValid = TRUE;

        /* if valid malloc and initialize the newWord struct */
        if(wordValid)
        {
            /* remove the newline */
            str[strlen(str) - 1] = 0;
            /*printf("%s, ", str);*/
            newWord = calloc(1, sizeof(struct word) + ( sizeof(char *) * strlen(str) ) );
            newWord->word = str;
            newWord->count = 0;
            /* add word struct to word list */
            listAdd(checker->list, newWord);
        }
        /* else reject the file and exit */
        else
        {
            fprintf(stderr, "Error, file contains invalid words");
        }
    }
    /*listPrintAll(checker->list);*/
    fclose(file);
    return TRUE;
}

/**
 * @param checker the datastructure used to manage the system
 **/
void system_free(struct checker_system* checker)
{
}

