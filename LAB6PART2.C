// SELECTION PROBLEM USING GREEDY METHOD 
#include <stdio.h>
int main()
{
    int n, i, j;
    int start[100], finish[100];
    int temp;
    printf("Enter number of activities: ");
    scanf("%d", &n);
    printf("Enter start time of each activity:\n");
    for (i = 0; i < n; i++)
    {
        printf("Activity %d: ", i + 1);
        scanf("%d", &start[i]);
    }
    printf("Enter finish time of each activity:\n");
    for (i = 0; i < n; i++)
    {
        printf("Activity %d: ", i + 1);
        scanf("%d", &finish[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (finish[i] > finish[j])
            {
                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }
    printf("\nSelected activities:\n");
    printf("Activity 1 ");
    int last = 0;
    for (i = 1; i < n; i++)
    {
        if (start[i] >= finish[last])
        {
            printf("Activity %d ", i + 1);
            last = i;
        }
    }
    return 0;
}