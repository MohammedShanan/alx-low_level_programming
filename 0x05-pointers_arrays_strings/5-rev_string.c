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
 * rev_string - reverse a string
 * @s: string to reverse
 */

void rev_string(char *s)
{
int i, j;
char tmp;
j = _strlen(s) - 1;

while (i < j)
{
tmp = s[i];
s[i] = s[j];
s[j] = tmp;
i++, j--;
}
}
