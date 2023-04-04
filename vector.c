#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	// Refers to the address of the vector object itself
	struct vector* self;
	int* data;
	int len;

	void (*pfn_set)(struct vector*, size_t, int);
	int (*pfn_get)(struct vector*, size_t);
	void (*pfn_append)(struct vector*, int);
}vector_t;


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
	return new;
}


int main()
{
	printf("address of get function is %p\n", &get);
	printf("address of get function is %p\n", get);
	int arr1[] = {7,5,32,2,2,2,89,9,9,9};
	//int arr1[] = {};
	printf("size is %d \n", sizeof(arr1)/sizeof(arr1[0]));
	vector_t* ref = constructor(arr1, sizeof(arr1)/sizeof(arr1[0]));
	printf("Length of the array is %d\n", ref->len);
	for(int i=0; i<ref->len; i++)
		printf("%d ", ref->data[i]);
	printf("\nThe new value after calling set function is\n");
	set(ref, 6, 800);
	for(int i=0; i<ref->len; i++)
		printf("%d ", ref->data[i]);
	return 0;
}
