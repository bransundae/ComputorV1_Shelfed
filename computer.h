#ifndef COMPUTER_H
#define COMPUTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

//HASH MAP
struct node {
    char *key;
    char *val;
    struct node *next;
};

struct table{
    int size;
    struct node **list;
};

//PARSING
void            itoa_isnegative(int *n, int *neg);
char	        *ft_itoa(int n);
int             delim(char *str, char **delim);
int             count_words(char *str, char **args);
char            *malloc_word(char *str, char **args);
char            **ft_split(char *str, char **args);
int             str_len(char *strlen);
char            **half_split(char *str);

//HASH MAP
struct table    *create_hash_table(int size);
int             hash_code(struct table *t, char *key);
void            hash_Insert(struct table *t, char *key, char *val);
char            *hash_lookup(struct table *t, char *key);

//MATH PARSER
char    *quad_reduce(char *str);

#endif