#include "Str.h"
#define SIZE(x) (sizeof(x) / sizeof(x[0]))


int main()
{
    char my_str[] = "Hello";
    string_t* new_str = Constructor(my_str, sizeof(my_str)/sizeof(my_str[0]));
    new_str->pfn_print(new_str->self);
    new_str->pfn_set(new_str->self, 2, (char)'Y');
    new_str->pfn_print(new_str->self);

    printf("%c", new_str->pfn_get(new_str->self, 2));
    // Out of Range
    printf("%c", new_str->pfn_get(new_str->self, 90));
    printf("\n");

    // Appending
    char temp[] = "abc";
    new_str->pfn_plus(new_str->self, SIZE(temp), temp);
    new_str->pfn_print(new_str->self);
    printf("new size is %ld\n", new_str->str_len);

    // Clear memory
    Destructor(new_str);
}
