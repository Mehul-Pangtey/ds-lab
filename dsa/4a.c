#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        char str[100];
        char stack[100];
        int top = -1;
        int i;

        scanf("%s", str);

        // Push characters into stack
        for (i = 0; i < strlen(str); i++)
        {
            top++;
            stack[top] = str[i];
        }

        // Pop characters to reverse
        while (top >= 0)
        {
            printf("%c", stack[top]);
            top--;
        }

        printf("\n");
    }

    return 0;
}
