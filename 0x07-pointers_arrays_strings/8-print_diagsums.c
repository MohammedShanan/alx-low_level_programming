#include "main.h"
#include<stdio.h>

/**
 * print_diagsums - print sums of diagonals in matrix
 * @a: matrix
 * @size: size of matrix
 */

#include <stdio.h>
void print_diagsums(int *a, int size)
{
int i = 0, j = size + 1, sum1 = 0, sum2 = 0;
while (i < size * size)
{
sum1 += a[i];
i += j;
}
j = size - 1;
i = size * size - size;
while (i > 0)
{
sum2 += a[i];
i -= j;
}
printf("%i, %i\n", sum1, sum2);
}