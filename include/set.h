/* 
 * Sets are a type of associative container in which each element has to be unique
 * Properties:
 *  1. Storing Order - the set stores the elements in sorted order
 *  2. Values Characteristics - all the elements in a set have unique values
 *  3. Values Nature - The value of the element cannot be modified once it is added to 
 *      the set, though it is possible to remove and then add the modified value of that
 *      element. Thus, the values are immutable
 *  4. Search Technique - Sets follow the Binary Search Tree implementation
 *  5. Arranging order - The values in a set are unindexed
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef SET_H
#define SET_H

/********Structs********/
typedef struct set{

    struct set* self;

    size_t size;
    int* array;

    void (*pfn_insert)(int, struct set*);
    void (*pfn_print)(struct set*);

}set_t;
/********Structs********/


/*  Prototypes  */
set_t* set_constructor(int start_elems[], size_t length);

void set_insert(int val, set_t* self);

void set_print(set_t* self);

void set_destructor(set_t*);

#endif

