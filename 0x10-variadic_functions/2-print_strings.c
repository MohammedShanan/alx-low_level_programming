#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_strings - print varying amount of strings
 * @separator: delimiter
 * @n: amount of arguments in list
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
unsigned int i = 0;
va_list ap;
char *s;
if (n == 0)
{
return;
}
va_start(ap, n);
while (i < n)
{
s = va_arg(ap, char *);
if (s == NULL)
{
printf("(nil)", s);
}
else
{
printf("%s", s);
}
if (separator != NULL && i < n - 1)
{
printf("%s", separator);
}
i++;
}
va_end(ap);
printf("\n");
}
