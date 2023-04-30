#include "sort_array.h"
#define SIZE(X) (sizeof(X) / sizeof(X[0]))

int main()
{
    int arr1[] = {1,2,3,45,5,65,66,21};
    printf("size of array is %lu\n", SIZE(arr1));

    int len = (int)SIZE(arr1);
    selectionSort(arr1, len);

    for (int i=0; i<len; ++i)
    {
        printf("%d, ", arr1[i]);
    }
    printf("\n");

    return 0;
}
