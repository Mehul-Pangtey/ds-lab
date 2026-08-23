#include <stdio.h>
#define MAX 100
int top=-1,front=-1,rear=-1;
int queue[MAX];
int stack[MAX];
void enqueue(int data)
{
    if(rear==MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    rear++;
    queue[rear]=data;
    if(front==-1)
        front=0;
}
int dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data=queue[front];
    front++;
    return data;
}
void push(int data)
{
    if(top==MAX-1)
    {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top]=data;
}                   
int pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    int data=stack[top];
    top--;
    return data;
}
int main(){
    int choice=0,data;
    while(choice!=3)
    {
        printf("1.Enqueue\n2.Dequeue\n3.exit");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                data=dequeue();
                if(data!=-1)
                    printf("Dequeued data: %d\n",data);
                break;
            case 3:printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
printf("reversing the queue using stack\n");
for(int i=front;i<=rear;i++)
{
    int data=dequeue();
    push(data);
}
for(int i=top;i>=0;i--)
{
    int data=pop();
    enqueue(data);
}
printf("Queue after reversing: ");
for(int i=front;i<=rear;i++)
{
    printf("%d ",queue[i]);
}
return 0;
}
