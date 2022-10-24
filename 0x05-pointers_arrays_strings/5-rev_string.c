#include "main.h"

/**
 * swap_int - swaps the values of two integers
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
    int i, len;
    len = _strlen(s) - 1;

    while (i < len)
    {
        swap_char((s + i), (s + len));
        len--;
        i++;
    }
}
