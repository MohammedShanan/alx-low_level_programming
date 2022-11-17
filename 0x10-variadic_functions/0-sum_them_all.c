#include "variadic_functions.h"

/**
 * sum_them_all - return sum when given unknown amount of arguments
 * @n: integers to add
 * Return: sum
 */

int sum_them_all(const unsigned int n, ...)
{
unsigned int i = 0;
int sum = 0;
va_list ap;
if (n == 0)
{
return (0);
}
va_start(ap, n);
while (i < n)
{
sum += va_arg(ap, int);
i++;
}
va_end(ap);
return (sum);
}
