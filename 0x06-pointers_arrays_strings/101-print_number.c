#include "main.h"

/**
 * print_number - print an integer, without using long, arrays, or pointers
 * @n: number to be printed
 */

void print_number(int n)
{
unsigned int digit, positive = n;
double tens = 1;
if (n < 0)
{
positive = n * -1;
_putchar('-');
}

while (tens * 10 <= positive)
{
tens *= 10;
}

while (tens >= 1)
{
digit = positive / tens;
_putchar(digit + '0');
positive = positive % 10;
tens /= 10;
}
}
