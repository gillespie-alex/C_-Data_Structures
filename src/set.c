#include "set.h"
#include "sort_array.h"

#define MAX_SIZE 1000


// Global Variable for holding the new length after dropped elements
static size_t new_length; 


static int* drop_repeated_elements(int arr[], size_t length)
{
    static int result[MAX_SIZE];
    // Clear out the memory
    for (int i=0; i<MAX_SIZE; ++i)
        result[i] = 0;

    int index = 0;
    // increase the index after inserting to the beginning
    result[index++] = arr[0];

    bool flag = true;
    for (int i=1; i<length; ++i)
    {
        for (int j=0; j<length; ++j)
        {
            // This indicates it is already in result array 
            if (arr[i] == result[j])
                flag = !flag;
        }

        if (flag)
        {
            result[index] = arr[i];
            index++;
        }
        flag = true;
    }
    
    new_length = index;

    return result;
}


set_t* set_constructor(int start_elems[], size_t length)
{
    set_t* set_ptr = (set_t*)malloc(1 * sizeof(set_t));

    // Set the 'self' pointer
    set_ptr->self = set_ptr;

    // Drop all repeated elements
    int* dropped_elems = drop_repeated_elements(start_elems, length);


    // Sort the elements with the newly found length (does sorting in place)
    selectionSort(dropped_elems, new_length);
    set_ptr->array = dropped_elems;

    set_ptr->size = new_length;

    set_ptr->pfn_insert = set_insert;
    set_ptr->pfn_print = set_print;

    return set_ptr;
}


void set_insert(int val, set_t* self)
{
    return;
}

void set_print(set_t* self)
{
    printf("Elements in set are:\n");
    for (int i=0; i<self->size; ++i)
        printf("%d ", self->array[i]);
    printf("\n");
    printf("Size of the set is: %lu\n", self->size);
    
}

