#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

/********Structs********/
typedef struct hash_item{
    int key;
    int value;
    struct hash_item* next;
}item_t;


typedef struct hash_table{
    // Array of item_t pointers
    struct hash_item** items;

    int size;
    int count;
}table_t;
/***********************/


table_t* create_table();

void hashtable_Destructor(table_t*);

// Add a new key, value pair to the table
void insert_item(table_t*, int, int);

// Hash function will be passed a key
unsigned int hash_function(unsigned int);

int get_item(table_t*, int);

void print_item(item_t*);

#endif
