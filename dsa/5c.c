#include <stdio.h>
#define max 100

int dq[max];
int front = -1, rear = -1;

void iend(int data);
void ifront(int data);
void pfront();
void pend();
void dfront();
void dend();
void isfull();
void isempty();

int main() {
    int ch = 0, data; // Initialised ch to prevent stray stack errors
    while (ch != 9) {
        printf("\n1.insert from front\n2.insert from end\n3.delete from front\n");
        printf("4.delete from end\n5.is empty\n6.is full\n7.display from front\n8.display from end\n9.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("enter data to enter in front:");
                scanf("%d", &data);
                ifront(data);
                break;

            case 2:
                printf("enter data to enter in end:");
                scanf("%d", &data);
                iend(data);
                break;

            case 3: dfront(); break;
            case 4: dend(); break;
            case 5: isempty(); break;
            case 6: isfull(); break;
            case 7: pfront(); break;
            case 8: pend(); break;
            case 9: printf("exitingg....\n"); break;
            default: printf("enter a valid choice\n");
        }
    }
    return 0;
}

void ifront(int data) {
    if (front == 0) {
        printf("Cannot insert at front (no space ahead)\n");
    } else if (front == -1) { // Added 'else' to prevent execution flow fall-through
        front = 0;
        rear = 0;
        dq[front] = data;
    } else {
        front--;
        dq[front] = data;
    }
}

void iend(int data) {
    if (rear == max - 1) {
        printf("cannot insert at end\n");
    } else {
        if (rear == -1) {
            rear = 0;
            front = 0;
            dq[rear] = data;
        } else {
            dq[++rear] = data;
        }
    }
}

void dfront() {
    if (front == -1) {
        printf("empty queue\n");
    } else {
        printf("element removed:%d\n", dq[front]);
        if (front == rear) {
            front = -1;
            rear = -1; 
        } else {
            front++;
        }
    }
}

void dend() {
    if (rear == -1) {
        printf("empty\n");
    } else {
        printf("deleted element:%d\n", dq[rear]);
        if (rear == front) {
            front = -1;
            rear = -1;
        } else {
            rear--;
        }
    }
}

void isfull() {
    if (rear == max - 1) // Fixed: Linear queue limit met when rear hits maximum capacity
        printf("full queue\n");
    else
        printf("queue is not full\n");
}

void isempty() {
    if (front == -1) 
        printf("empty queue\n"); // Fixed string from "full queue" to "empty queue"
    else
        printf("queue is not empty\n");
}

void pfront() {
    if (front == -1) {
        printf("empty queue\n");
    } else {
        printf("values from front: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", dq[i]);
        }
        printf("\n");
    }
}

void pend() {
    if (rear == -1) {
        printf("empty queue\n");
    } else {
        printf("values from end: ");
        for (int i = rear; i >= front; i--) {
            printf("%d ", dq[i]);
        }
        printf("\n");
    }
}
