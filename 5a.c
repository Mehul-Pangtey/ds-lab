#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void Create()
{
    front = -1;
    rear = -1;
    printf("Queue Created\n");
}

void EnQueue(int k)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = k;
        printf("Inserted %d\n", k);
    }
}

void DeQueue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element = %d\n", queue[front]);
        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void IsEmpty()
{
    if (front == -1)
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");
}

void Size()
{
    if (front == -1)
        printf("Size = 0\n");
    else
        printf("Size = %d\n", rear - front + 1);
}

void Display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    Create();

    do
    {
        printf("\n1. EnQueue");
        printf("\n2. DeQueue");
        printf("\n3. IsEmpty");
        printf("\n4. Size");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            EnQueue(value);
            break;

        case 2:
            DeQueue();
            break;

        case 3:
            IsEmpty();
            break;

        case 4:
            Size();
            break;

        case 5:
            Display();
            break;

        case 6:
            printf("Program Ended\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 6);

    return 0;
}
