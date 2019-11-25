#ifndef COMPUTOR_H
#define COMPUTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

//HASH MAP
typedef struct List {
    char *key;
    char *value;
    struct List *next;
} List;

typedef struct HashTable{
    unsigned int size;
    List **array;
} HashTable;

//HASH MAP
HashTable   *ht_create(unsigned int size);
unsigned int hash(const char *key, unsigned int size);
int ht_put(HashTable *hashtable, const char *key, const char *value);
void node_handler(HashTable *hashtable, List *node);
char    *ht_get(HashTable *hashtable, const char *key);
void    ht_free(HashTable *hashtable);

//PARSING
void            itoa_isnegative(int *n, int *neg);
char	        *ft_itoa(int n);
int             delim(char *str, char **delim);
int             count_words(char *str, char **args);
char            *malloc_word(char *str, char **args);
char            **ft_split(char *str, char **args);
int             str_len(char *strlen);
char            **half_split(char *str);
void            ht_print(HashTable *hashtable);

//MATH PARSER
char    *quad_reduce(char *str);

#endif