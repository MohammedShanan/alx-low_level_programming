#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers
 * @a: array
 * @n: number of elements
 */

void print_array(int *a, int n)
{
int i;
if (n <= 0)
{
printf("\n");
}
for (i = 0; i < n; i++)
{
printf("%i", a[i]);
i == n - 1 ? putchar('\n') : printf(", ");
}
}
