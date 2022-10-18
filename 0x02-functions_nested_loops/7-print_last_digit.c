#include "main.h"

/**
 * print_last_digit - print last digit of integer
 * @n: integer argument
 * Return: last digit of number
 */

int print_last_digit(int n)
{
int last_dig;
last_dig = n % 10;
last_dig = last_dig > 0 ? last_dig : last_dig * -1;
_putchar('0' + last_dig);
return (last_dig);
}

