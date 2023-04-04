//#include <stdio.h>
//#include <stdlib.h>
//#include <stddef.h>

#include "vector.h"

//typedef struct vector{
//	// Refers to the address of the vector object itself
//	struct vector* self;
//	int* data;
//	size_t len;
//
//	void (*pfn_set)(struct vector*, size_t, int);
//	int (*pfn_get)(struct vector*, size_t);
//
//	// Function to append to the end of the vector
//	void (*pfn_append)(struct vector*, int);
//
//}vector_t;


void append(vector_t* self, int value)
{
	printf("old length is %d and value is %d \n", self->len, value);
	self->data = realloc(self->data, (self->len + 1)*sizeof(int) );
	self->data[self->len] = value;
	self->len += 1;
	printf("new length is %d\n", self->len);
}

int get(vector_t* self, size_t index)
{
	// First check if the desired index is out of bounds of the vector
	int result = -999;
	if (index >= self->len)
		return result;
	result = *(self->data + index);
	return result;
}

void set(vector_t* self, size_t index, int value)
{
	if (index >= self->len)
		return;
	self->data[index] = value;
}


/*
 * All the user needs to pass an initial array from stack memory/size of array
 * And the constructor will handle everything else
 */
vector_t* constructor(int* start_array, size_t length)
{
	vector_t* new = (vector_t*)malloc(1 * sizeof(vector_t));
	new->self = new;
	new->len = length;

	// Initialize the data in the vector
	new->data = (int*)malloc(length * sizeof(int));
	for(int i=0; i<length; i++)
		new->data[i] = start_array[i];

	// Initialize the function pointers (methods)
	new->pfn_set = &set;
	new->pfn_get = &get;
	new->pfn_append = &append;
	return new;
}

// Destructor to dispose of the used memory
void destructor(vector_t* self)
{
	// This order is important
	free(self->data);
	free(self);
}


//int main()
//{
//	int arr1[] = {7,5,32,2,2,2,89,9,9,9};
//
//	vector_t* ref = constructor(arr1, sizeof(arr1)/sizeof(arr1[0]));
//
//	for(int i=0; i<ref->len; i++)
//		printf("%d ", ref->data[i]);
//
//	ref->pfn_set(ref, 4, 100);
//	set(ref, 6, 800);
//	printf("\nAfter the newly set value\n");
//	for(int i=0; i<ref->len; i++)
//		printf("%d ", ref->data[i]);
//
//	printf("\nafter appending\n");
//	ref->pfn_append(ref, 66666);
//	for(int i=0; i<ref->len; i++)
//		printf("%d ", ref->data[i]);
//	printf("\n");
//	return 0;
//}
