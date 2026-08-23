#include <stdio.h>

#define MAX 100

void push(char stack[], int *top, char value)
{
    (*top)++;
    stack[*top] = value;
}

char pop(char stack[], int *top)
{
    char value = stack[*top];
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
        char exp[MAX];
        char stack[MAX];
        int top = -1;
        int balanced = 1;

        fgets(exp, MAX, stdin);

        for (int i = 0; exp[i] != '\0'; i++)
        {
            char ch = exp[i];

            if (ch == '(' || ch == '{' || ch == '[')
            {
                push(stack, &top, ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (top == -1)
                {
                    balanced = 0;
                    break;
                }

                char open = pop(stack, &top);

                if ((ch == ')' && open != '(') ||
                    (ch == '}' && open != '{') ||
                    (ch == ']' && open != '['))
                {
                    balanced = 0;
                    break;
                }
            }
        }

        if (top != -1)
            balanced = 0;

        if (balanced)
            printf("Balanced\n");
        else
            printf("Unbalanced\n");
    }

    return 0;
}