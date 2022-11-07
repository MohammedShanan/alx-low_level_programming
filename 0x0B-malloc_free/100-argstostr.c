#include<stdlib.h>
#include<stdio.h>
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
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to concatenated string
 */

char *str_concat(char *s1, char *s2)
{
    char *new_str;
    int i = 0, j = 0;
    s1 = s1 == NULL ? "" : s1;
    s2 = s2 == NULL ? "" : s2;
    new_str = malloc(_strlen(s1) + _strlen(s2) + 1);
    if (!new_str)
    {
        return (NULL);
    }
    while (i < _strlen(s1)) /* concatenate */
    {
        *(new_str + i) = *(s1 + i);
        i++;
    }
    while (j < _strlen(s2))
    {
        *(new_str + i) = *(s2 + j);
        i++, j++;
    }
    return (new_str);
}

char *argstostr(int ac, char **av)
{
    int i;
    char *new_str = "";
    char *tmp;
    if (ac == 0 || av == NULL)
    {
        return (NULL);
    }
    for (i = 0; i < ac; i++)
    {
        tmp = str_concat(av[i], "\n");
        printf("tmp is %s new is %s\n", tmp, new_str);
        new_str = str_concat(new_str, tmp);
    }
    return (new_str);
}