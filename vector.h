#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	// Refers to the address of the vector object itself
	struct vector* self;
	int* data;
	int size;

	void (*pfn_set)(struct vector*, size_t, int);
	int (*pfn_get)(struct vector*, size_t);
}vector_t;
