// LARGEST ELEMENT OF AN ARRAY 
#include <stdio.h>
int main()
{
    int a[100], n, i, largest;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    largest = a[0];
    for(i = 1; i < n; i++)
    {
        if(a[i] > largest)
        {
            largest = a[i];
        }
    }
    printf("Largest element in the array: %d\n", largest);
    return 0;
}