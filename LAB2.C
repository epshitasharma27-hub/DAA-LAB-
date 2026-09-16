// IMPLEMENT INSERTION SORT FOR 10,100,1000INPUTS AND CALCULATE THE TIME TAKEN
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n, i, j, key;
    clock_t start, end;
    double time;
    printf("Enter size : ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
    start = clock();
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Input size = %d\n", n);
    printf("Time taken = %f seconds\n", time);
    return 0;
}