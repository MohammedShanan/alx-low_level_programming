#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - print sums of diagonals in matrix
 * @a: matrix
 * @size: size of matrix
 */

#include <stdio.h>
void set_string(char **s, char *to)
{
	*s = to;
}
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s0 = "Bob Dylan";
	char *s1 = "Robert Allen";

	printf("%s, %s\n", s0, s1);
	set_string(&s1, s0);
	printf("%s, %s\n", s0, s1);
	return (0);
}