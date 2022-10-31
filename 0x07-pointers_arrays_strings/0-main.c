#include "main.h"
#include <stdio.h>
void print_diagsums(int *a, int size)
{
	int i = 0, j = size + 1, sum1 = 0, sum2 = 0;
	int x;
	while (i < size * size)
	{
		x = *(a + i);
		sum1 += x;
		i += j;
	}
	i -= j;
	i -= size - 1;
	j = size - 1;
	while (i > 0)
	{
		x = *(a + i);
		sum2 += x;
		i -= j;
	}
	printf("%i, %i\n", sum1, sum2);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int c3[3][3] = {
		{0, 1, 5},
		{10, 11, 12},
		{1000, 101, 102},
	};
	printf("c3 is %p\n", c3);
	int c5[5][5] = {
		{0, 1, 5, 12124, 1234},
		{10, 11, 12, 123521, 12512},
		{1000, 101, 102, 12545, 214543435},
		{100, 1012451, 11102, 12545, 214543435},
		{10, 12401, 10452, 11542545, 1214543435},
	};
	print_diagsums((int *)c3, 3);
	print_diagsums((int *)c5, 5);
	return (0);
}