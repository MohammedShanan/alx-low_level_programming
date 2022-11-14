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

/**
 *  insert_to_buff - insert the result of the addition to the buffer
 * @result: result of the addition
 * @r: buffer
 * @len_r: size of the buffer
 * Return: buffer
 */
char *insert_to_buff(char *result, char *r, int len_r)
{
    int i = 0, len_result = _strlen(result);
    if (len_result + 1 > len_r)
    {
        return (0);
    }
    while (i <= len_result)
    {
        r[i] = result[i];
        i++;
    }
}

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer for the result
 * @size_r: size of the buffer
 * Return: result buffer on success, 0 on error
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len_n1 = _strlen(n1);
    int len_n2 = _strlen(n2);
    int sum, len_buff, carry;
    char *buff;
    sum = carry = 0;
    len_buff = len_n1 > len_n2 ? len_n1 + 1 : len_n2 + 1;
    buff = malloc(len_buff + 1);
    buff[len_buff] = '\0';
    len_n1--, len_n2--, len_buff--;
    while (len_buff)
    {
        if (len_n1 < 0 && len_n2 >= 0)
        {
            sum = (n2[len_n2--] - '0') + carry;
        }
        else if (len_n2 < 0 && len_n1 >= 0)
        {
            sum = (n1[len_n1--] - '0') + carry;
        }
        else if (len_n1 >= 0 && len_n2 >= 0)
        {
            sum = (n1[len_n1--] - '0') + (n2[len_n2--] - '0') + carry;
        }
        carry = sum / 10;
        buff[len_buff--] = (sum % 10) + '0';
    }
    if (carry == 1)
    {
        buff[0] = '1';
    }
    else
    {
        buff++;
    }
    return (insert_to_buff(buff, r, size_r));
}
