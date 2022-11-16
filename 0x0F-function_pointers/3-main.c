#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"
/**
 * main - when user runs main,
 * user should give two integers and an operator and
 * main will calculate the math using a function pointer.
 * prints sum, difference, product, dividend, or remainder
 * @argc: argument counter
 * @argv: arguments
 * Return: 0 on sucess
 */
int main(int argc, char *argv[])
{
    int a, b, res;
    int (*fun)(int, int);
    if (argc != 4)
    {
        err;
        exit(98);
    }
    a = atoi(argv[1]);
    b = atoi(argv[3]);
    fun = get_op_func(argv[2]);
    if (fun == NULL)
    {
        err;
        exit(99);
    }
    if ((argv[2][0] == '%' || argv[2][0] == '/') && argv[3][0] == '0')
    {
        err;
        exit(100);
    }
    res = fun(a, b);
    printf("%i\n", res);
    return (0);
}
