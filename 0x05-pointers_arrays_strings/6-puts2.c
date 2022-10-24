#include"main.h"

/**
 * _puts2 - prints every other character of a string, starting with the first character, followed by a new line
 * @str: string to print
 */

void puts2(char *str)
{
int i;
i = 0;
while (*str)
{
if (i % 2 == 0)
{
_putchar(*str);
}
i++;
str++;
}
_putchar('\n');
}
