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
 * num_of_words - count the number of words in a string
 * @text: string
 * Return: number of words
 */
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
return (j + 1);
}
/**
 * rm_ext_space - remove extra spaces from a string
 * @s: string
 * Return: string
 */

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
if (new_s == NULL)
{
return (NULL);
}
for (indx = 0; indx <= len_tmp; indx++)
{
new_s[indx] = tmp[indx];
}
free(tmp);
return (new_s);
}

/**
 * strtow - splits a string into words
 * @str: string
 * Return: an array of words
 */

char **strtow(char *str)
{
char **arr;
char *tmp;
int i = 0, j = 0, num_words, len_w = 0, indx = 0;
if (str == NULL || *str == '\0')
{
return (NULL);
}
tmp = rm_ext_space(str);
if (tmp == NULL)
{
return (NULL);
}
num_words = num_of_words(tmp);
arr = malloc((num_words + 1) * sizeof(char *));
if (arr == NULL)
{
free(arr);
return (NULL);
}
while (i < num_words)
{
if (tmp[indx] == ' ' || tmp[indx] == '\0')
{
arr[i] = malloc(len_w + 1);
for (j = 0; len_w; j++)
{
arr[i][j] = tmp[indx - len_w];
len_w--;
}
arr[i][j] = '\0';
i++, indx++;
continue;
}
indx++, len_w++;
}
arr[i] = NULL;
return (arr);
}
