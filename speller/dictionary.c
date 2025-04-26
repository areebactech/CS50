// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"
int strcasecmp(const char *s1, const char *s2);

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int no_words = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word);
    node *cursor = table[hash_value];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)

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
    unsigned int hash_value = 0;
    int i = 0;

    // Iterate through each character in the word (up to 3 characters)
    while (word[i] != '\0' && i < 3)
    {
        // Convert each character to uppercase, then incorporate it into the hash value
        hash_value = (hash_value * 26) + (toupper(word[i]) - 'A');
        i++;
    }

    // Return the hash value mod N to ensure it fits within the table size
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    FILE *dict_file = fopen(dictionary, "r");
    if (dict_file == NULL)
    {
        printf("was not able to open dictionary\n");
        return false;
    }
    char buffer[45];

    while (fscanf(dict_file, "%s", buffer) != EOF)
    {
        node *new_word = malloc(sizeof(node));
        int hash_value = hash(buffer);
        strcpy(new_word->word, buffer);
        new_word->next = table[hash_value];
        table[hash_value] = new_word;
        no_words++;
    }
    fclose(dict_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    return no_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
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
