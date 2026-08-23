#include <stdio.h>

int main()
{
    int arr[10][10];
    int n;
    int start = 0, end;
    int i, j;
    int istep, jstep;
    int temp;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    end = n - 1;

    printf("Enter matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Rotate layer by layer
    while(start < end)
    {
        i = start;
        j = start;

        // Store top-left element
        temp = arr[i][j];

        // Initially move down
        istep = 1;
        jstep = 0;

        while(1)
        {
            // Reached bottom-left
            if(i == end && j == start)
            {
                istep = 0;
                jstep = 1;
            }

            // Reached bottom-right
            if(i == end && j == end)
            {
                istep = -1;
                jstep = 0;
            }

            // Reached top-right
            if(i == start && j == end)
            {
                istep = 0;
                jstep = -1;
            }

            // Stop before overwriting top-left
            if(i == start && j == start + 1)
            {
                break;
            }

            arr[i][j] = arr[i + istep][j + jstep];

            i = i + istep;
            j = j + jstep;
        }

        // Put saved element in its new position
        arr[i][j] = temp;

        // Move to next inner layer
        start++;
        end--;
    }

    printf("\nRotated Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
