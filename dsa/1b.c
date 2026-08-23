#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n;
        scanf("%d", &n);

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int a, b;
        scanf("%d %d", &a, &b);

        int posa = -1;
        int posb = -1;
        int min = n;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == a)
            {
                posa = i;
            }

            if (arr[i] == b)
            {
                posb = i;
            }

            if (posa != -1 && posb != -1)
            {
                int distance = posa - posb;

                if (distance < 0)
                    distance = -distance;

                if (distance < min)
                    min = distance;
            }
        }

        printf("%d\n", min);
    }

    return 0;
}
