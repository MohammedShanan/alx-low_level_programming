#include <stdio.h>

/**
 *main - prints all arguments it receives
 * @argc: argument counter
 * @argv: pointer to array of arguments
 *Return: 0
 */

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; argv[i]; i++)
    {
        printf("%s\n", argv[i]);
    }
    printf("\n");
    return (0);
}
