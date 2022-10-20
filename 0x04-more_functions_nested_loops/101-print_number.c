#include "main.h"

/**
 * print_number - print an integer, without using long, arrays, or pointers
 * @n: number to be printed
 */

void print_number(int n)
{
unsigned int digit, num = n;
double tens = 1;
if (n < 0)
{
num = n * -1;
_putchar('-');
}

while (tens * 10 <= num)
tens *= 10;
while (tens >= 1)
{
digit = num / tens;
_putchar(digit + '0');
num = (num - (tens * digit));
tens /= 10;
}
}
