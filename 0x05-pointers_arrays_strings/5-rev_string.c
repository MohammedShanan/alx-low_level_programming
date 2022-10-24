#include "main.h"

/**
 * swap_char - swaps the values of two integers
 * @a: char to swap
 * @b: char to swap
 */

void swap_char(char *a, char *b)
{
char tmp;
tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
int len;
len = 0;
while (*s)
{
len++;
s++;
}
return (len);
}

/**
 * rev_string - reverse a string
 * @s: string to reverse
 */

void rev_string(char *s)
{
int i, j;
j = _strlen(s) - 1;
i = 0;
while (i < j)
{
swap_char((s + i), (s + j));
j--;
i++;
}
}
