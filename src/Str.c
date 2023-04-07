#include "Str.h"


string_t* Constructor(char* start_string, size_t start_size)
{
    string_t* new_str = (string_t*)malloc(1 * sizeof(string_t));
    // Set the self pointer to the address of new string
    new_str->self = new_str;

    // Allocate memory for the actual string data
    new_str->characters = (char*)malloc(start_size * sizeof(char));
    for (int i=0; i<start_size; i++)
    {
        new_str->characters[i] = start_string[i];
    }
    // Set size of the start_string minus 1 discounting '\0'
    new_str->str_len = start_size - 1;

    // Assigning the function pointers
    new_str->pfn_set = &pfn_set;
    new_str->pfn_get = &pfn_get;
    new_str->pfn_plus = &pfn_plus;
    new_str->pfn_print = &pfn_print;

    return new_str;
}


void pfn_plus(string_t* self, size_t input_len, char* input_str)
{
    unsigned long new_size = input_len + self->str_len;
    self->characters = (char*)realloc(self->characters, sizeof(char) * new_size);
    for (int i=0; i<input_len; i++)
    {
        self->characters[i + self->str_len] = input_str[i];
    }
    // Update the size of the string
    self->str_len = new_size - 1;
}


char pfn_get(string_t* self, size_t index)
{
    if (index >= self->str_len)
    {
        printf("Attempting to access a member out of bounds\n");
        return (char)'0';
    }

    else
        return self->characters[index];
}


void pfn_set(string_t* self, size_t index, char new_char)
{
    if (index >= self->str_len)
        printf("Attempting to access a member out of bounds\n");
    else
        self->characters[index] = new_char;
}


void pfn_print(string_t* self)
{
    printf("printing stored string\n");
    for (int i=0; i < self->str_len; i++)
    {
        printf("%c", self->characters[i]);
    }
    printf("\n");
}

// Destructor to dispose of the used memory
void Destructor(string_t* self)
{
	// This order is important
	free(self->characters);
	free(self);
}
