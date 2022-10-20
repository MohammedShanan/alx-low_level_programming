#include "main.h"

/**
 * print_square - print a square of #'s given size
 * @size: size to draw
 */

void print_square(int size)
{
int i, j;
if (size <= 0)
{
_putchar('\n');
}
for (i = 0; i < size; i++)
{
j = 0;
while (j < size)
{
_putchar('#');
j++;
}
_putchar('\n');
}
}
