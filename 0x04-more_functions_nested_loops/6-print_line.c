#include "main.h"

/**
 * print_line - print the character "_" n times to draw a line
 * @n: number of _ to draw
 */

void print_line(int n)
{
int i = 0;
while (i < n)
{
_putchar("_");
i++;
}
_putchar("\n");
}

