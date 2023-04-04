#include "vector.h"


int main()
{
	int arr1[] = {7,5,32,2,2,2,89,9,9,9};

	vector_t* ref = constructor(arr1, sizeof(arr1)/sizeof(arr1[0]));

	// Testing the set operation
	ref->pfn_set(ref, 4, 100);

	// Testing the append operation
	ref->pfn_append(ref, 66666);
	ref->pfn_append(ref, 77777);
	ref->pfn_append(ref, 88);

	destructor(ref);

	return 0;
}
