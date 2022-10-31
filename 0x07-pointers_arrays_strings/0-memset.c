#include<stdio.h>
/**
 * _memset - fills the first n bytes of the memory area pointed to by
 * s with the constant byte b
 * @s: address of the memory area to be changed
 * @b: character to fill the memory area
 * @n: number of bytes to be filled
 * Return: pointer to the memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	 unsigned int i;

	for (i = 0; *(s + i) && i < n; i++)
	{
		*(s + i) = b;
		printf("%c\n", *(s + i));
	}
	return (s);
}

