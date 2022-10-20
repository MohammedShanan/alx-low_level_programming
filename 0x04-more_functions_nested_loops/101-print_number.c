#include "main.h"

/**
 * print_number - print an integer, without using long, arrays, or pointers
 * @n: number to be printed
 */

void print_number(int n)
{
unsigned int tens = 1;
char digit;
if (n < 0)
{
_putchar('-');
n = n * -1;
}
while (tens * 10 <= n)
{
tens *= 10;
}
while (tens >= 1)
{
digit = '0' + (n / tens);
_putchar(digit);
n = n % tens;
tens /= 10;
}
}
