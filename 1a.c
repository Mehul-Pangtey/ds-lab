#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n, k;
        scanf("%d", &n);

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        scanf("%d", &k);

        // Left rotate by k positions
        for (int i = 0; i < k; i++)
        {
            int first = arr[0];

            for (int j = 0; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }

            arr[n - 1] = first;
        }

        // Print rotated array
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");
    }

    return 0;
}