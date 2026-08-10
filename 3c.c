#include <stdio.h>

#define MAX 1000

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
        char str[MAX];
        int stack[MAX];
        int top = -1;
        int maxLength = 0;

        fgets(str, MAX, stdin);

        // Base index
        push(stack, &top, -1);

        for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
        {
            if (str[i] == '(')
            {
                push(stack, &top, i);
            }
            else if (str[i] == ')')
            {
                pop(stack, &top);

                if (top == -1)
                {
                    // No matching opening bracket
                    push(stack, &top, i);
                }
                else
                {
                    int length = i - stack[top];

                    if (length > maxLength)
                        maxLength = length;
                }
            }
        }

        printf("%d\n", maxLength);
    }

    return 0;
}