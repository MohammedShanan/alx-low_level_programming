#include "main.h"

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
 * puts_half - prints half of a string, followed by a new line
 * @s: string to reverse
 */

void puts_half(char *str)
{
int len;
char *half_str; 
len = _strlen(str);
half_str = len / 2 + str;
while (*half_str)
{
_putchar(*half_str);
half_str++;
}
_putchar('\n');
}
