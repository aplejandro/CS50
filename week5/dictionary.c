// Implements a dictionary's functionality
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>


#include "dictionary.h"
#define HASH_SIZE 63266
unsigned int wordsCount = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

void deleteList(struct node *head);
void moveToFront(struct node **head_ref);

// Number of buckets in hash table
const unsigned int N = HASH_SIZE;
int col=0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    char copy[LENGTH + 1];
    strcpy(copy, word);
    int l=strlen(copy);
        for (int i=0;i < l; i++)
        {
            copy[i] = tolower(copy[i]);
        }
    int x = hash(copy);
    if (table[x]==NULL)
    {
        return false;
    }
    // Accessing linked list first node
    node* n = table[x];
    while (n)
    {
        // If word is found at head of linked list return true
        if (strcasecmp(n->word, word) == 0)
        {
            if
            //moveToFront(&table[x]);
            return true;
        }
        n = n->next;
    }
    return false;
}

void moveToFront(struct node **head_ref)
{
    /* If linked list is empty, or it contains only one node,
      then nothing needs to be done, simply return */
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    /* Initialize second last and last pointers */
    struct node *secLast = NULL;
    struct node *last = *head_ref;

    /*After this loop secLast contains address of second last
    node and last contains address of last node in Linked List */
    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }

    /* Set the next of second last as NULL */
    secLast->next = NULL;

    /* Set next of last as head node */
    last->next = *head_ref;

    /* Change the head pointer to point to last node now */
    *head_ref = last;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hash Function taken from http://www.cse.yorku.ca/~oz/hash.html
  const char *str = word;
  unsigned long hashValue = 0;
  int c;

  while ((c = *str++))
  {
    hashValue = ((hashValue << 5) + hashValue) + c; /* hash * 33 + c */
  }

  return hashValue % HASH_SIZE;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = NULL;
    file = fopen(dictionary, "r");
    if (!file){
        return false;
    }
    char readString[LENGTH + 1];
    int index;
    while(fscanf(file, "%s", readString) != EOF)
    {
        index = hash(readString);
        node* n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        else
        {
            strcpy(n->word, readString);
            n->next = NULL;
            if (table[index] == NULL)
            {
                table[index] = n;
            }
            else
            {
                col++;
                n->next = table[index];
                table[index] = n;
            }
        }
        wordsCount++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    printf("Col = %d\n",col);
    return wordsCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int index = 0; index < HASH_SIZE; index++)
    {
        // Point to first node in linked list
        if (table[index] == NULL)
        {
            continue;
        }
        else
        {
            deleteList(table[index]);
        }
    }
    return true;
}

void deleteList(struct node *head)
{
    if (head != NULL)
    {
        deleteList(head->next);
        free(head);
    }
    return;
}