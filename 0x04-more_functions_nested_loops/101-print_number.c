#include "main.h"

/**
 * print_number - print an integer, without using long, arrays, or pointers
 * @n: number to be printed
 */

void print_number(int n)
{
    unsigned int tens = 1, num = n, digit;
    if (n < 0)
    {
        _putchar('-');
        num = num * -1;
}
while (tens * 10 <= num)
{
tens *= 10;
}
while (tens >= 1)
{
digit = (num / tens);
_putchar('0' + digit);
num = num % tens;
tens /= 10;
}
}
