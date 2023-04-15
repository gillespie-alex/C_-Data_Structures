#include "hashtable.h"

#define MAP_SIZE (1000000U)

/* Prototypes */
static void free_item_llist(item_t*);


// Even if key is an integer, treat like char
unsigned int hash_function(unsigned int key) {
    return (MAP_SIZE % key);
}

table_t* create_table(void)
{
    // Pointer to the new table created
    table_t* new_table_ptr = (table_t*)malloc(1 * sizeof(table_t));
    new_table_ptr->size = MAP_SIZE;
    new_table_ptr->count = 0;

    // Initialize the array of item_t pointers
    new_table_ptr->items = (item_t**)calloc(new_table_ptr->size, sizeof(item_t*));
    return new_table_ptr;
}

// Private function
static item_t* create_item(int Key, int Val)
{
    item_t* new_item = (item_t*)malloc(1 * sizeof(item_t));
    new_item->key = Key;
    new_item->value = Val;
    new_item->next = NULL;

    return new_item;
}

void insert_item(table_t* map, int Key, int Val)
{
    unsigned int hash_value = hash_function(Key);
    //printf("Key:%d Val:%d and Hash:%u\n", Key, Val, hash_value);
    item_t* new_item = create_item(Key, Val);
    if (map->items[hash_value] == 0)
    {
        map->items[hash_value] = new_item;
    }
    // Traverse the linked list
    else
    {
        item_t* temp = map->items[hash_value];
        //temp = map->items[hash_value];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_item;
        // Free up temp
        //temp = NULL;
    }

    map->count += 1;
}

// Looks for Key if its in hash table and prints value
int get_item(table_t* map, int Key)
{
    unsigned int hash_value = hash_function(Key);
    if (map->items[hash_value] == 0)
    {
        printf("nothing in this key\n");
        return -9999999;
    }
    else
    {
        item_t* temp = map->items[hash_value];
        //temp = map->items[hash_value];
        while (temp->key != Key && temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp->value;
    }
}


// Need to use a double linked list or recursion to free up the memory
void hashtable_Destructor(table_t* map)
{
    for (int i=0; i<map->size; ++i)
    {
        if (map->items[i] == NULL)
            continue;
        free_item_llist(map->items[i]);
    }
    free(map->items);
    free(map);
}

void print_item(item_t* item)
{
    printf("Key:%d, Value:%d\n", item->key, item->value);
}

// Recursive function to clear up the memory of the linked list
static void free_item_llist(item_t* node)
{
    print_item(node);
    if (node->next == NULL)
    {
        free(node);
        return;
    }
    free_item_llist(node->next);
    free(node);
}
