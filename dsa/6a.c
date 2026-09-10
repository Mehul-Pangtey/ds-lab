#include <stdio.h>

#define MAX 100

int q1[MAX], q2[MAX];
int front1 = 0, rear1 = -1;
int front2 = 0, rear2 = -1;

/* Queue 1 / Queue 2 enqueue */
void enq(int q[], int *rear, int value)
{
    q[++(*rear)] = value;
}

/* Queue 1 / Queue 2 dequeue */
int deq(int q[], int *front, int rear)
{
    if (*front > rear)
        return -1;

    return q[(*front)++];
}

/* Push element into stack */
void push(int value)
{
    int x;

    /* Put new element into queue 2 */
    enq(q2, &rear2, value);

    /* Move all elements of queue 1 to queue 2 */
    while (front1 <= rear1)
    {
        x = deq(q1, &front1, rear1);
        enq(q2, &rear2, x);
    }

    /* Move everything back from queue 2 to queue 1 */
    while (front2 <= rear2)
    {
        x = deq(q2, &front2, rear2);
        enq(q1, &rear1, x);
    }

    /* Reset queue 2 */
    front2 = 0;
    rear2 = -1;
}

/* Pop element from stack */
int pop()
{
    return deq(q1, &front1, rear1);
}

/* Find size of stack */
int size()
{
    return rear1 - front1 + 1;
}

int main()
{
    int choice, value, popped;

    while (1)
    {
        printf("\nPress:\n");
        printf("1 to push\n");
        printf("2 to pop\n");
        printf("3 to find size\n");
        printf("4 to exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter element: ");
            scanf("%d", &value);

            push(value);

            printf("Stack - ");
            for (int i = front1; i <= rear1; i++)
                printf("%d ", q1[i]);

            printf("\n");
        }
        else if (choice == 2)
        {
            if (size() == 0)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                popped = pop();

                printf("Element popped from stack - %d\n", popped);

                printf("Stack after pop operation - ");
                for (int i = front1; i <= rear1; i++)
                    printf("%d ", q1[i]);

                printf("\n");
            }
        }
        else if (choice == 3)
        {
            printf("Size of stack - %d\n", size());
        }
        else if (choice == 4)
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

