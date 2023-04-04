//#include <stdio.h>
//#include <stdlib.h>
//#include <stddef.h>

#include "vector.h"


int main()
{
	int arr1[] = {7,5,32,2,2,2,89,9,9,9};

	vector_t* ref = constructor(arr1, sizeof(arr1)/sizeof(arr1[0]));

	for(int i=0; i<ref->len; i++)
		printf("%d ", ref->data[i]);

	ref->pfn_set(ref, 4, 100);
	set(ref, 6, 800);
	printf("\nAfter the newly set value\n");
	for(int i=0; i<ref->len; i++)
		printf("%d ", ref->data[i]);

	printf("\nafter appending\n");
	ref->pfn_append(ref, 66666);
	ref->pfn_append(ref, 77777);
	ref->pfn_append(ref, 88);
	for(int i=0; i<ref->len; i++)
		printf("%d ", ref->data[i]);
	printf("\n");
	return 0;
}
