
#include "variadic_functions.h"
/**
 * print_char - prints char
 * @ap: argument parameter
 */

void print_char(va_list ap)
{
    printf("%c", va_arg(ap, int));
}
/**
 * print_int - prints int
 * @ap: argument parameter
 */
void print_int(va_list ap)
{
    printf("%d", va_arg(ap, int));
}
/**
 * print_float - prints float
 * @ap: argument parameter
 */
void print_float(va_list ap)
{
    printf("%f", va_arg(ap, double));
}
/**
 * print_string - prints string
 * @ap: argument parameter
 */
void print_string(va_list ap)
{
    char *s;

    s = va_arg(ap, char *);

    if (s == NULL)
    {
        printf("(nil)");
        return;
    }
    printf("%s", s);
}
/**
 * print_all - print varying input of ints, chars, floats, and strings
 * @format: an array of chars signifying which data type to print
 */
void print_all(const char *const format, ...)
{
    va_list ap;
    int i = 0, j;
    char *sep = "";
    pts arr[] = {
        {'c', print_char},
        {'i', print_int},
        {'f', print_float},
        {'s', print_string},
        {'\0', NULL}};
    va_start(ap, format);
    while (format[i] != '\0' && format != NULL)
    {
        j = 0;
        while (arr[j].id != '\0')
        {
            if (arr[j].id == format[i])
            {
                printf("%s", sep);
                arr[j].f(ap);
                sep = ", ";
            }
            j++;
        }
        i++;
    }
    va_end(ap);
    printf("\n");
}
