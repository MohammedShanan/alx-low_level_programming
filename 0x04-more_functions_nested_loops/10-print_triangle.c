#include "main.h"

/**
 * print_triangle - print triangle with #'s with given size
 * @size: size of triangle to draw
 */

void print_triangle(int size)
{
int i, spaces, hashes;
if (size <= 0)
{
_putchar('\n');
}
for (i = 1; i <= size; i++)
{
spaces = 0;
hashes = 0;
while (spaces < size - i)
{
_putchar(' ');
spaces++;
}
while (hashes < i)
{
_putchar('#');
hashes++;
}
_putchar('\n');
}
}
