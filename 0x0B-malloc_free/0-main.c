#include "main.h"
#include <stdio.h>
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

int num_of_words(char *text)
{
    int i, j = 0;
    for (i = 0; text[i]; i++)
    {
        if (text[i] == ' ')
        {
            j++;
        }
    }
    return j + 1;
}
char *rm_ext_space(char *s)
{
    int i, indx = 0, len = _strlen(s) + 1, len_tmp = 0;
    char *tmp = malloc(len);
    char *new_s;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0' || len_tmp == 0))
        {
            continue;
        }
        tmp[len_tmp++] = s[i];
    }
    tmp[len_tmp] = '\0';
    new_s = malloc(len_tmp);
    for (indx = 0; indx <= len_tmp; indx++)
    {
        new_s[indx] = tmp[indx];
    }
    free(tmp);
    return (new_s);
}

char **strtow(char *str)
{
    char **arr;
    int i = 0, j = 0, num_words;
    if (str == NULL || *str == '\0')
    {
        return (NULL);
    }
    str = rm_ext_space(str);
    num_words = num_of_words(str);
    arr = malloc(num_words * sizeof(char *));
    if (arr == NULL)
    {
        free(arr);
        return (NULL);
    }

    while (i <= num_words)
    {
        if (str[j] == ' ' || str[j] == '\0')
        {
            arr[i][j] = '\0';
            i++, j++;
            continue;
        }
        arr[i][j] = str[j];
        j++;
    }
    return (arr);
}

/**
 * print_tab - Prints an array of string
 * @tab: The array to print
 *
 * Return: nothing
 */
void print_tab(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; ++i)
    {
        printf("%s\n", tab[i]);
    }
}

/**
 * main - check the code for ALX School students.
 *
 * Return: 1 if an error occurred, 0 otherwise
 */
int main(void)
{
    char **tab;

    tab = strtow("      ALX School         #cisfun      ");
    if (tab == NULL)
    {
        printf("Failed\n");
        return (1);
    }
    print_tab(tab);
    return (0);
}