#include <stdlib.h>

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
 * string_nconcat - concatenate s1 and n bytes of s2; return ptr to string
 * @s1: string 1
 * @s2: string 2
 * @n: n bytes to concat from string 2
 * Return: pointer to concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
int i, j, len_1, len_2;
char *ptr;
len_1 = s1 != NULL ? _strlen(s1) : 0;
len_2 = s2 != NULL ? _strlen(s2) : 0;
if ((int)n >= len_2)
{
n = len_2;
}
ptr = malloc(len_1 + n + 1);
if (ptr == NULL)
{
return (NULL);
}
for (i = 0; i < len_1; i++)
{
ptr[i] = s1[i];
}
for (j = 0; j < (int)n; j++)
{
ptr[i] = s2[j];
i++;
}
ptr[i] = '\0';
return (ptr);
}
