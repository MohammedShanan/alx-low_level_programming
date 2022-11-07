#include<stdlib.h>
#include"main.h"
/**
 * _strcat - concatenate two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */

char *_strcat(char *dest, char *src)
{
int i;
i = 0;
while (dest[i])
{
i++;
}
while (*src)
{
*(dest + i) = *src;
i++, src++;
}
*(dest + i) = '\0';
return (dest);
}

/**
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to concatenated string
 */

char *str_concat(char *s1, char *s2)
{
char *new_str;
if (s1 == NULL && s2 == NULL)
{
return (NULL);
}
new_str = _strdup(s1);
if (!new_str)
{
return (NULL);
}

return (_strcat(new_str, s2));
}
