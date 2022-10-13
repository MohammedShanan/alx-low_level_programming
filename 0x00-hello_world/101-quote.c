#include <stdio.h>

/**
 *main - Entry point
 *Return: Always 1
 */

int main(void)
{
	char arr[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	fwrite(arr, sizeof(arr) - 1, 1, stdout);
	return (1);
}
