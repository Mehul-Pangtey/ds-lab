#include <stdio.h>
#include <ctype.h>

#define MAX 100

void push(int stack[], int *top, int value)
{
    (*top)++;
    stack[*top] = value;
}

int pop(int stack[], int *top)
{
    int value = stack[*top];
    (*top)--;
    return value;
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();

    while (T--)
    {
        char exp[200];
        int stack[MAX];
        int top = -1;

        fgets(exp, sizeof(exp), stdin);

        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == ' ')
                continue;

            // If it is a number
            if (isdigit(exp[i]))
            {
                push(stack, &top, exp[i] - '0');
            }

            // If it is an operator
            else
            {
                int b = pop(stack, &top);
                int a = pop(stack, &top);

                if (exp[i] == '+')
                    push(stack, &top, a + b);

                else if (exp[i] == '-')
                    push(stack, &top, a - b);

                else if (exp[i] == '*')
                    push(stack, &top, a * b);

                else if (exp[i] == '/')
                    push(stack, &top, a / b);
            }
        }

        printf("%d\n", pop(stack, &top));
    }

    return 0;
}