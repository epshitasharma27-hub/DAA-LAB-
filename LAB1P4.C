// REVERSE AN ARRAY
#include <stdio.h>
int main()
{
    int a[100], n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Reverse of array:\n");
    for(i = n - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    return 0;
}