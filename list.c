#include "list.h"

/**
 * @file list.c contains implementation of functions for managing the word lists
 * used by the program.
 **/

BOOLEAN listAdd(struct word_list * list, struct word * newWord)
{
    struct list_node * prev = NULL, * curr, * newNode;
    if( ( newNode = malloc(sizeof(struct list_node)) ) == NULL)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    /* set up the new node with its default data */
    newNode->next = NULL;
    newNode->data = newWord;

    /* check if the list is empty and this is the first entry */
    if(list->num_words == 0)
    {
        printf("adding first word: %s\n", newNode->data->word);
        list->head = newNode;
        list->num_words += 1;
        printf("new head set: %s\n", list->head->data->word);
        return TRUE;
    }

    /* 
     * this new node is not the first in the list
     * so we have to grab the first node to traverse the list
     */
    printf("num_words is: %i, ", list->num_words);
    printf("current head is %s, ", list->head->data->word);
    curr = list->head;

    /*
     * now we have to traverse the list, comparing each word
     * to make sure its added into the list alphabetically
     */
   
    printf("comparing: %s with %s gives: %i, ",
        curr->data->word, newWord->word, 
        strcmp(curr->data->word, newWord->word));
    while(curr != NULL && strcmp(curr->data->word, newWord->word) > 0)
    {
        printf("looped at least once, ");
        prev = curr;
        curr = curr->next;
    }

    /* did we get to the end of the list? */
    if(curr == NULL)
    {
        /* add our new node to the end of the list */
        prev->next = newNode;
        list->num_words += 1;
        return TRUE;
    }
    /* inserting before first element */
    else if(prev == NULL)
    {
        newNode->next = list->head;
        list->head = newNode;
        list->num_words += 1;
        return TRUE;
    }
    /* insert between prev and curr */
    else
    {
        prev->next = newNode;
        newNode->next = curr;
        list->num_words += 1;
        return TRUE;
    }
    
    /* if we get here I dunno what went wrong */
    printf("Unknown list insertion error");
    return FALSE;
}

BOOLEAN listDelete(struct word_list * list, char * searchWord)
{
    return FALSE;
}

void listFree(struct word_list * list)
{

}

void listPrintAll(struct word_list * list)
{
   struct list_node * curr;

   curr = list->head;

   printf("word list : \n");
   printf("head word : %s\n", curr->data->word);
   while(curr->next != NULL)
   {
       printf("%s, ", curr->data->word);
       curr = curr->next;
   }
   printf("\n");
}

#ifdef WITH_LEVENSHTEIN
/**
 * @param first the first string to compare
 * @param first_len the number of characters in the first string to compare
 * @param second the second string to compare
 * @param second_len the number of characters in the second string to compare
 * @return the minimum number of edits required to turn the first string into
 * the second string 
 **/
int levenshtein(const char * first, int first_len, 
                const char * second, int second_len)
{
        int shorten_both, shorten_first, shorten_second;

        /* if either string is shorter than the threshold, difference is 
           inserting all chars from the other
         */
        if (first_len < THRESHOLD) return second_len;
        if (second_len < THRESHOLD) return first_len;
        printf("%s:%s\n", first, second);
        /* if the difference in the length of the strings is greater than the 
         * threshold, they are not similar
         */
        if(abs(strlen(first) - strlen(second)) > THRESHOLD)
        {
                return INT_MAX;
        }

        /* if last letters are the same, the difference is whatever is
         * required to edit the rest of the strings
         */
        if (first[first_len] == second[first_len])
                return levenshtein(first, first_len - 1, second, 
                                   second_len - 1);

        /* else try:
         *      changing last letter of first to that of second; or
         *      remove last letter of first; or
         *      remove last letter of second,
         * any of which is 1 edit plus editing the rest of the strings
         */
        shorten_both = levenshtein(first, first_len - 1, second, 
                                   second_len - 1);
        shorten_first = levenshtein(first, first_len,     second, 
                                    second_len - 1);
        shorten_second = levenshtein(first, first_len - 1, second, 
                                     second_len    );
        return (shorten_both <= shorten_first) ? 
                ((shorten_both <=  shorten_second) ? 
                 shorten_both + 1 : shorten_second + 1)
                : shorten_first + 1;
}
#endif/* WITH_LEVENSHTEIN */
