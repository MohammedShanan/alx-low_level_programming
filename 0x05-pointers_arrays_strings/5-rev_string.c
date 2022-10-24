#include "main.h"
#include <stdio.h>

int _putchar(char c)
{
return fwrite(&c, sizeof(c), 1, stdout);
}

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
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: string to reverse
 */

void rev_string(char *s)
{
int i, len;
len = _strlen(s) - 1;

while (i < len)
{
swap_char((s + i), (s + len));
len--;
i++;
}
_putchar('\n');
}
