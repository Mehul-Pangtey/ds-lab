#include <stdio.h>
#define MAX_SIZE 10
void push(int *stack, int *top, int value){
    if(*top == MAX_SIZE-1){
        printf("Stack is full");
        return;
    }
    (*top)++;
    stack[*top] = value;
}
int pop(int *stack, int *top){
    if(*top == -1){
        printf("Stack is empty");
        return -1;
    }
    int value = stack[*top];
    (*top)--;
    return value;
}
void peek(int *stack, int *top){
    if(*top == -1){
        printf("Stack is empty");
        return;
    }
    printf("Top element is %d", stack[*top]);
}
void display(int *stack, int *top){
    if(*top == -1){
        printf("Stack is empty");
        return;
    }
    for(int i=0; i<=*top; i++){
        printf("%d ", stack[i]);
    }
}
int main() {
    int stack[MAX_SIZE];
    int top = -1;
    int choice=0, value;
    while(choice!=5){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    
    switch(choice){
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(stack, &top, value);
            break;
        case 2:
            value = pop(stack, &top);
            printf("Popped value is %d", value);
            break;
        case 3:
            peek(stack, &top);
            break;
        case 4:
            display(stack, &top);
            break;
        case 5:
            choice=5;
            break;
        default:
            printf("Invalid choice");
            break;
    }}
    return 0;
}
