#include "variadic_functions.h"
void print_char(va_list ap)
{
printf("%c", va_arg(ap, int));
}
void print_int(va_list ap)
{
printf("%i", va_arg(ap, int));
}

void print_float(va_list ap)
{
printf("%f", va_arg(ap, double));
}

void print_string(va_list ap)
{
char *s = va_arg(ap, char *);
if (s != NULL)
{
printf("%s", s);
return;
}
printf("(nil)");
}
/**
 * print_all - print varying input of ints, chars, floats, and strings
 * @format: an array of chars signifying which data type to print
 */
void print_all(const char *const format, ...)
{
va_list ap;
int i = 0, j = 0;
char *sep;
void (*func)(va_list);
pts arr[] = {
{'c', print_char},
{'i', print_int},
{'f', print_float},
{'s', print_string},
{'\0', NULL}};
va_start(ap, format);
while (format[i] && format != NULL)
{
j = 0;
while (arr[j].id != '\0')
{
if (arr[j].id == format[i])
{
printf("%s", sep);
func = arr[j].f;
func(ap);
sep = ", ";
}
j++;
}
i++;
}
printf("\n");
va_end(ap);
}
