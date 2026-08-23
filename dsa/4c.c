#include <stdio.h>

int stack[100];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char expression[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(expression, 100, stdin);

    while (expression[i] != '\0' && expression[i] != '\n')
    {
        // Ignore spaces
        if (expression[i] == ' ')
        {
            i++;
        }

        // Read complete number
        else if (expression[i] >= '0' && expression[i] <= '9')
        {
            int num = 0;

            while (expression[i] >= '0' && expression[i] <= '9')
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }

            push(num);
        }

        // Operator
        else if (expression[i] == '+' ||
                 expression[i] == '-' ||
                 expression[i] == '*' ||
                 expression[i] == '/')
        {
            int b = pop();
            int a = pop();

            if (expression[i] == '+')
                push(a + b);
            else if (expression[i] == '-')
                push(a - b);
            else if (expression[i] == '*')
                push(a * b);
            else if (expression[i] == '/')
                push(a / b);

            i++;
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
