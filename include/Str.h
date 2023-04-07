#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


#ifndef STR_H
#define STR_H

typedef struct DynamicString{

    // Similar to the "self" in Python 
    struct DynamicString* self;
    char* characters;
    size_t str_len;

    // Function to set a value in the string
    void (*pfn_set)(struct DynamicString*, size_t, char);

    // Function to get a value in the string
    char (*pfn_get)(struct DynamicString*, size_t);

    // Similar to the "+" in Python for adding to string
    void (*pfn_plus)(struct DynamicString*, size_t, char*);

    void (*pfn_print)(struct DynamicString*);

}string_t;

// Function Prototypes
string_t* Constructor(char* start_string, size_t start_size);

void Destructor(string_t*);

void pfn_set(struct DynamicString*, size_t, char);

char pfn_get(struct DynamicString*, size_t);

void pfn_plus(struct DynamicString*, size_t, char*);

void pfn_print(string_t*);

#endif
