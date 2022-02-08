// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
//for the size function
int n;
// Number of buckets in hash table
const unsigned int N = 1000000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int i;
    char tmp[LENGTH+1];
    node *cursor;
    cursor=table[hash(word)];
    for (i = 0; i !='\0'; i += 1)
    {
    	tmp[i]=tolower(word[i]);
    }
    while (cursor!=NULL)
    {
    	if (strcmp(cursor->word,tmp))
    	{
    		return true;
    	}
    	cursor=cursor->next;
    }
	return false;
		
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
	unsigned long hash = 5381;
	int c;
	while ((c = toupper(*word++)))
	{
		hash = ((hash<<5) + hash) + c;
	}
	return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    int i;
    //for size function. initially set to 0
    n=0;
    unsigned int head;
    char dict_word[LENGTH + 1];
    
    node *bd;
    FILE *dict;
    dict=fopen("./dictionaries/large","r");
    if (dict==NULL)
    {
    	return false;
    }
 
    
    for (i = 0;fscanf(dict,"%s",dict_word)!=EOF ; i += 1)
    {		
    	head=hash(dict_word);
        bd=malloc(sizeof(node));
        if (bd==NULL)
        {
        	return false;
        }	
		strcpy(bd->word,dict_word);
		bd->next=table[head];
	
		table[head]=bd;
		//increases global variable n for the size function, as one word is loaded n increments
		n++;
    }
	fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
	if (n>0)
	{
		return n;
	}
	return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    int i;
    node *tmp;
    node *cursor;
    for (i = 0; i <= N; i += 1)
    {
    	tmp=cursor=table[i];
    	while (cursor!=NULL)
    	{
    		tmp=cursor;
    		cursor=cursor->next;
    		free(tmp);
    	}
    	if (i==N-1 && cursor==NULL)
    	{
    		return true;
    	}
    }
    return false;
}



































