#include "Str.h"
#define SIZE(STR) (sizeof(STR) / sizeof(STR[0]))

int main()
{
    char name[] = "Fiji";
    string_t* string = Constructor(name, SIZE(name)); 

    // Test the size of the string in constuctor
    printf("size is %lu\n", string->str_len);

    // Test the append '+' function
    string->pfn_plus(string->self, SIZE("_abc"), "_abc");

    // Test the print function
    string->pfn_print(string->self);
    printf("new size is %lu\n", string->str_len);

    // Test the set function
    string->pfn_set(string->self, 6, 'Y');
    string->pfn_print(string->self);

    // Test the set function with out of bounds input
    string->pfn_set(string->self, 60, 'Y');
    string->pfn_print(string->self);

    // Free up all the memory allocated
    Destructor(string->self);
    return 0;
}





