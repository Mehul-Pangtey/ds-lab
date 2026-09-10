#include <stdio.h>

#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

/* Push into a stack */
void push(int s[], int *top, int value)
{
    s[++(*top)] = value;
}

/* Pop from a stack */
int pop(int s[], int *top)
{
    return s[(*top)--];
}

/* Enqueue into queue */
void enq(int value)
{
    push(s1, &top1, value);
}

/* Dequeue from queue */
int deq()
{
    int x;

    /* If stack 2 is empty, move all elements from stack 1 */
    if (top2 == -1)
    {
        while (top1 != -1)
        {
            x = pop(s1, &top1);
            push(s2, &top2, x);
        }
    }

    return pop(s2, &top2);
}

int main()
{
    int choice, value, deleted;

    while (1)
    {
        printf("\nPress:\n");
        printf("1 to enqueue\n");
        printf("2 to dequeue\n");
        printf("3 to exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter element: ");
            scanf("%d", &value);

            enq(value);

            printf("Queue - ");

            /* Print queue from front to rear */
            if (top2 != -1)
            {
                for (int i = top2; i >= 0; i--)
                    printf("%d ", s2[i]);

                for (int i = 0; i <= top1; i++)
                    printf("%d ", s1[i]);
            }
            else
            {
                for (int i = 0; i <= top1; i++)
                    printf("%d ", s1[i]);
            }

            printf("\n");
        }
        else if (choice == 2)
        {
            if (top1 == -1 && top2 == -1)
            {
                printf("Queue Underflow\n");
            }
            else
            {
                deleted = deq();

                printf("Element deleted from queue - %d\n", deleted);

                printf("Queue after deletion- ");

                if (top2 != -1)
                {
                    for (int i = top2; i >= 0; i--)
                        printf("%d ", s2[i]);

                    for (int i = 0; i <= top1; i++)
                        printf("%d ", s1[i]);
                }
                else
                {
                    for (int i = 0; i <= top1; i++)
                        printf("%d ", s1[i]);
                }

                printf("\n");
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
