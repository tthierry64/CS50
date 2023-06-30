// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "dictionary.h"

int total_words = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // We use a cursor which traverses the linked list from the head to the end of a bucket.
    //it goes word to word (meaning node to node) and compare the word analyzed with the word in the bucket
    // If the cursor points to NULL, the end of the list of the bcket is reached.
    int hash_value = hash(word);
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //return toupper(word[0]) - 'A';

    //lets do the math : calculate the total sum of the ascii value of each letter of the word analized
    //each bucket of the hash table will be a % of N
    int asciitotal = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        asciitotal += tolower(word[i]);
    }
    return asciitotal % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //Open a dictionnary in a temporary file to be read
    FILE *read_f = fopen(dictionary, "r");
    //Check if it can be opened
    if (read_f == NULL)
    {
        printf("The dictionary cannot be opened to be read");
        return false;
    }
    /*Read the file until the EOF string is reached meaning the end of the file.
    Each read word must be copied in a temporary node. Thus it could be stored
    in the hash table. Before that we need to creat the key refferd to the hash table*/
    char read_word[LENGTH + 1];
    while (fscanf(read_f, "%s", read_word) != EOF)
    {
        node *tmp_node = malloc(sizeof(node));
        if (tmp_node == NULL)
        {
            return false;
        }
        strcpy(tmp_node->word, read_word);
        //Initializing the fisrt node of a bucket
        tmp_node->next = NULL;

        // Creation of the hash value according to the hash function
        //Place the new node in the correct bucket = correct table[hash_value]
        int hash_value = hash(read_word);
        //Place the first word in a "virgin" bucket
        if (table[hash_value] == NULL)
        {
            table[hash_value] = tmp_node;
        }
        else
        {
            tmp_node->next = table[hash_value];
            table[hash_value] = tmp_node;

        }
        total_words++;
    }
    fclose(read_f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (total_words > 0)
    {
        return total_words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //We need to free the memory of each "node word" ine each "i" bucket of the table
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
