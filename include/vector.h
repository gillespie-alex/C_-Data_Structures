#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


#ifndef VECTOR_H
#define VECTOR_H


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

void append(vector_t* self, int value);

int get(vector_t* self, size_t index);

void set(vector_t* self, size_t index, int value);

vector_t* constructor(int* start_array, size_t length);

void destructor(vector_t* self);

#endif
