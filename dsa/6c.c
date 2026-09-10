#include <stdio.h>
#define max 5
int q[max];
int f = -1, r = -1;
void enq(int value)
{
    if ((r + 1) % max == f)
    {
        printf("Full queue\n");
        return;
    }
    if (f == -1)
    {
        f = 0;
        r = 0;
    }
    else
    {
        r = (r + 1) % max;
    }

    q[r] = value;
}

void deq()
{
    if (f == -1)
    {
        printf("Empty queue\n");
        return;
    }

    printf("Deleted: %d\n", q[f]);

    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % max;
    }
}

void disp()
{
    if (f == -1)
    {
        printf("Empty queue\n");
        return;
    }

    int i = f;

    while (1)
    {
        printf("%d ", q[i]);

        if (i == r)
            break;

        i = (i + 1) % max;
    }

    printf("\n");
}

int main()
{
    int ch = 0;

    while (ch != 4)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");

        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
            {
                int x;
                printf("Enter value: ");
                scanf("%d", &x);
                enq(x);
                break;
            }

            case 2:
                deq();
                break;

            case 3:
                disp();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
