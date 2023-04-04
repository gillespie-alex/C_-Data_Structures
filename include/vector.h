#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


#ifndef VECTOR_H
#define VECTOR_H

// Vector structure similar to C++ vector and Python List
typedef struct vector{
	// Refers to the address of the vector object itself
	struct vector* self;
	int* data;
	size_t len;

	void (*pfn_set)(struct vector*, size_t, int);
	int (*pfn_get)(struct vector*, size_t);

	// Function to append to the end of the vector
	void (*pfn_append)(struct vector*, int);

}vector_t;

// Constructor function
vector_t* constructor(int* start_array, size_t length);

void append(vector_t* self, int value);

// Retreives a value from the vector object
int get(vector_t* self, size_t index);

// Sets a value in the vector object
void set(vector_t* self, size_t index, int value);

// Destructor function
void destructor(vector_t* self);

#endif
