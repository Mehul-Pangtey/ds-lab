#include <stdio.h>

#define MAX 10

int dq[MAX];
int front = -1;
int rear = -1;

void insertFront(int x)
{
    if (front == 0)
    {
        printf("Cannot insert at front\n");
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        dq[front] = x;
    }
    else
    {
        front--;
        dq[front] = x;
    }
}

void insertEnd(int x)
{
    if (rear == MAX - 1)
    {
        printf("Cannot insert at end\n");
    }
    else if (rear == -1)
    {
        front = 0;
        rear = 0;
        dq[rear] = x;
    }
    else
    {
        rear++;
        dq[rear] = x;
    }
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Deleted = %d\n", dq[front]);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void deleteEnd()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Deleted = %d\n", dq[rear]);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear--;
        }
    }
}

void isEmpty()
{
    if (front == -1)
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");
}

void isFull()
{
    if (front == 0 && rear == MAX - 1)
        printf("Deque is full\n");
    else
        printf("Deque is not full\n");
}

void printFront()
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Deque from Front: ");

        for (i = front; i <= rear; i++)
            printf("%d ", dq[i]);

        printf("\n");
    }
}

void printEnd()
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Deque from End: ");

        for (i = rear; i >= front; i--)
            printf("%d ", dq[i]);

        printf("\n");
    }
}

int main()
{
    int choice;
    int x;

    do
    {
        printf("\n1. Insert Front");
        printf("\n2. Insert End");
        printf("\n3. Delete Front");
        printf("\n4. Delete End");
        printf("\n5. Is Empty");
        printf("\n6. Is Full");
        printf("\n7. Print Front");
        printf("\n8. Print End");
        printf("\n9. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            insertFront(x);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &x);
            insertEnd(x);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteEnd();
            break;

        case 5:
            isEmpty();
            break;

        case 6:
            isFull();
            break;

        case 7:
            printFront();
            break;

        case 8:
            printEnd();
            break;

        case 9:
            printf("Program ended\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 9);

    return 0;
}