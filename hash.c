#include "computer.h"

struct table    *create_hash_table(int size){
    struct table *t = (struct table *)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node **)malloc(sizeof(struct node*) * size);
    for (int i = 0; i < size; i++)
        t->list[i] = NULL;
    return t;
}

int hash_code(struct table *t, char *key){

    int hash = 0;
    int i = 0;
    while (key && key[i]){
        hash = (hash + key[i]) % *t->size;
        ++i;
    }

    return hash;
}

void hash_insert(struct table *t, char *key, char *val){
    int pos = hash_code(t, key);
    struct node *list = t->list[pos];
    struct node *temp = list;
    struct node *newNode;
    while(temp){
        if (temp->key == key){
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->val = val;
    newNode->next = list;
    t->list[pos] = newNode;
}

char *hash_lookup(struct table *t, char *key){
    int pos = hash_code(t, key);
    struct node *list = t->list[pos];
    struct node *temp = list;
    while(temp){
        if (temp->key == key){
            return temp->val;
        }
        temp = temp->next;
    }
    return NULL;
}