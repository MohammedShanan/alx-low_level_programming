#include <stdio.h>

/**
 *main - prints all arguments it receives
 *Return: 0
 */

int main(char *argv[])
{
    int i;
    for (i = 0; argv[i]; i++)
    {
        printf("%s\n", argv[i]);
    }
    printf("\n");
    return (0);
}
