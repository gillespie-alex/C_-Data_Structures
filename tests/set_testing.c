#include "set.h"
#define SIZE(X) (sizeof(X) / sizeof(X[0]))

static void print_arr(int arr[], size_t len)
{
    for (int i=0; i<len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{
    int temp[] = {3,4,49,5,6,69,6,7, 8, 4, 32, 8, 32, 100, 99, 99, 99, 1};
    printf("Original Array looks like:\n");
    size_t size_temp = SIZE(temp);
    print_arr(temp, size_temp);
    printf("size of the newly created array is %lu\n", size_temp);

    printf("New Set looks like:\n");
    set_t* me = set_constructor(temp, size_temp);
    me->pfn_print(me->self);


    int temp1[] = {1,5,5,5,90,87,87,65};
    printf("Original Newish Array looks like:\n");
    size_t size_temp1 = SIZE(temp1);
    print_arr(temp1, size_temp1);
    printf("size of the newly created array is %lu\n", size_temp1);

    printf("New Set looks like:\n");
    set_t* me2 = set_constructor(temp1, size_temp1);
    me2->pfn_print(me2->self);
    return 0;
}
