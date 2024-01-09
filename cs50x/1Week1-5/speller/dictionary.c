// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

int howmanywordsputintodictionary = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[676] = { NULL };

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    if (strlen(word) > LENGTH)
    {
        return false;
    }

    char lowercaseWord[LENGTH + 1];
    for (int i = 0; word[i]; i++)
    {
        lowercaseWord[i] = tolower(word[i]);
    }
    lowercaseWord[strlen(word)] = '\0'; // Null-terminate the lowercase word

    unsigned int hashkey = hash(lowercaseWord) % N; // Use modulo to ensure valid index

    node *cursor = table[hashkey];

    while (cursor != NULL)
    {
        if (strcasecmp(lowercaseWord, cursor->word) == 0)
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
    unsigned int hash = 0;

    hash = (N-(word[0]*word[1])); //comeback here later and make a more efficient code

    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("File failed to load\n");
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        for(int i = 0; word[i]; i++)
        {
            word[i] = tolower(word[i]);
        }

        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        strcpy(new_node->word, word);

        // Calculate hash value and insert new node at the beginning of the linked list
        unsigned int hash_key = hash(word) % N; // Use modulo to ensure valid index
        new_node->next = table[hash_key];
        table[hash_key] = new_node;
        new_node->next = NULL; // Initialize next pointer to NULL

        howmanywordsputintodictionary++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int dictionarysize = howmanywordsputintodictionary;
    // TODO
    return dictionarysize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (unsigned int i= 0; i < N; i++)
    {
        node *cursor2 = table[i];

        while (cursor2 != NULL)
        {
            node *tmp = cursor2;
            cursor2 = cursor2->next;
            free(tmp);
        }

        table[i] = NULL; // Set the table entry to NULL after freeing all nodes in the linked list
    }

    return true;
}
