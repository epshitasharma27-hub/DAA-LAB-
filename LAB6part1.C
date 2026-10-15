// implement quick sort and arrange the following elements in ascending order 2,3,9,0,-2,30,40,-40,5,45 use 1st element as pivot element 
#include <stdio.h>
int quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[low];
        int i = low;
        int j = high;
        int temp;
        while (i < j)
        {
            while (a[i] <= pivot && i < high)
                i++;
            while (a[j] > pivot)
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
    return 0;
}
int main()
{
    int a[] = {2, 3, 9, 0, -2, 30, 40, -40, 5, 45};
    int n = 10;

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}