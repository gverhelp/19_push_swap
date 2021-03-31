#include "include/push_swap.h"

void    swap(int *a, int *b)
{
    int tmp;

    tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int     partition(int *arr, int low, int high)
{
    int pivot;
    int i;
    int j;

    i = low - 1;
    j = low;
    pivot = arr[high];
    while (j <= (high - 1))
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void    quick_sort(int *arr, int low, int high)
{
    int pi;

    pi = 0;
    if (low < high)
    {
        pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main(void)
{
    int *arr;
    int a;

    a = 0;
    arr[0] = 30;
    arr[1] = 10;
    arr[2] = 60;
    arr[3] = 20;
    arr[4] = 90;
    arr[5] = 70;
    arr[6] = 40;
    arr[7] = 80;

    a = sizeof(arr);
    quick_sort(arr, 0, a - 1);


    a = 0;
    while (a < sizeof(arr))
    {
        printf("%d\n", arr[a]);
        a++;
    }
    return (0);
}