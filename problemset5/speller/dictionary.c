// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

/*
This will likely not work but I will program it as if it will
This is due to the premade 'speller.c' file
This contains a linux only #include sys/resource.h and I am running this on a windows machine
If you try to compile this on a linux machine it should work (hopefully)
*/

// Represents a node in a hash table
typedef struct node
{
    char *word;
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
#define N 5490

// Hash table
node *table[N];

void initialise(){
    for(int i = 0; i < N; i++){
        table[i] = NULL;
    }
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *tmp = table[index];
    while(tmp != NULL && strcmp(tmp->word, word) != 0){
        return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int length = strlen(word);
    unsigned int hashValue = 0;
    for(int i = 0; i < length; i++){
        hashValue += word[i];
    }
    return hashValue;
}
int wordCount = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    initialise();
    FILE *f = fopen(dictionary, "r");
    if(f == NULL){
        return false;
    }

    char *buffer;
    int wordCount = 0;
    while(fgets(buffer, LENGTH, f)){
        wordCount++;
        node *n = malloc(sizeof(node));
        if(n == NULL){
            fclose(f);
            free(n);
            return false;
        }
        int index = hash(buffer);
        n -> word = buffer;
        n -> next = table[index];
        table[index] = n;
    }
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < N; i++){
        cursor = table[i];
        while (cursor != NULL){
           tmp = cursor;
            cursor = cursor->next;
           free(tmp);
        }
    }
    return true;
}
