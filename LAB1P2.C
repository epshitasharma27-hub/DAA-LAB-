// SUM OF AN ELEMENTS IN AN ARRAY AND ITS AVERAGE 
#include <stdio.h>
int main()
{
    int a[100], n, i, sum = 0;
    float average;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    average = (float)sum / n;
    printf("Sum of array elements: %d\n", sum);
    printf("Average of array elements: %.2f\n", average);
    return 0;
}