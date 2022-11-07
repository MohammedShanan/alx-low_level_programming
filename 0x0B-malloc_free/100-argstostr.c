#include <stdlib.h>
#include <stdio.h>
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
 * argstostr - concatenates all the arguments of your program
 * @ac: argc
 * @av: arguments
 * Return: pointer to array
 */
char *argstostr(int ac, char **av)
{
int i, j, indx, len = 0;
char *new_str;
if (ac == 0 || av == NULL)
{
return (NULL);
}
while (i < ac)
{
len += _strlen(av[i]);
i++; 
}
len += ac + 1;
new_str = malloc(sizeof(char) * len);
for (i = 0; i < ac; i++)
{
for (j = 0; j < _strlen(av[i]); j++)
{
new_str[indx++] = av[i][j];
}
new_str[indx++] = '\n';
}
return (new_str);
}