#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  ctoi - change char to int
 * @c: charater to be changed
 * Return: an integere
 */
int ctoi(char c)
{
    char *num = malloc(2);
    num[0] = c;
    num[1] = '\0';

    return (atoi(num));
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
    int len_n1 = strlen(n1);
    int len_n2 = strlen(n2);
    int sum, len_buff, carry;
    sum = carry = 0;
    len_buff = len_n1 > len_n2 ? len_n1 + 1 : len_n2 + 1;
    if (size_r < len_buff)
    {
        return (0);
    }
    r = realloc(r, len_buff + 1);
    r[len_buff] = '\0';
    len_n1--, len_n2--, len_buff--;
    while (len_buff)
    {
        if (len_n1 < 0 && len_n2 >= 0)
        {
            sum = ctoi(n2[len_n2--]) + carry;
        }
        else if (len_n2 < 0 && len_n1 >= 0)
        {
            sum = ctoi(n1[len_n1--]) + carry;
        }
        else if (len_n1 >= 0 && len_n2 >= 0)
        {
            sum = ctoi(n1[len_n1--]) + ctoi(n2[len_n2--]) + carry;
        }
        carry = sum / 10;
        r[len_buff--] = (sum % 10) + '0';
        sum = 0;
    }
    if (carry == 0)
    {
        return (++r);
    }
    r[0] = carry + '0';
    return (r);
}
