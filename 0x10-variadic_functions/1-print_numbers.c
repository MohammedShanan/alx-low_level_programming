#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_numbers - print varying amount of numbers
 * @separator: delimiter
 * @n: amount of arguments in list
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
unsigned int i = 0;
va_list ap;
if (n <= 0)
{
return;
}
va_start(ap, n);
while (i < n)
{
printf("%d", va_arg(ap, int));
if (separator != NULL && i < n - 1)
{
printf("%s", separator);
}
i++;
}
va_end(ap);
printf("\n");
}
