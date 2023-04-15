#include "hashtable.h"
#include "Str.h"
#define SIZE(x) (sizeof(x) / sizeof(x[0]))


int main()
{

    table_t* new_map = create_table();
    insert_item(new_map, 2, 1000);
    insert_item(new_map, 4, 1000);
    insert_item(new_map, 8, 1000);
    insert_item(new_map, 23, 19040);
    insert_item(new_map, 46, 340);
    insert_item(new_map, 41, 340);
    printf("item got value %d\n", get_item(new_map, 16));
    hashtable_Destructor(new_map);
    //printf("value stored inside is %d\n", new_map->items[2500]->value);
    //printf("Key stored inside is %d\n", new_map->items[2500]->key);

    //printf("Value at Key %d is: %d\n", 50, get_item(new_map, 50));
    //printf("Value at Key %d is: %d\n", 45, get_item(new_map, 45));
    //print_item(new_map, 50);
    //print_item(new_map, 500);
    return 0;
}


/*  STRING MAIN.C
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
 * */
