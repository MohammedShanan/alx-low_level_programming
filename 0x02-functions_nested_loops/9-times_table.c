#include"main.h"

/**
 * times_table - print multiplication table
 */

void times_table(void)
{
int rows, columns, product;
for (rows = 0; rows <= 9; rows++)
{
for (columns = 0; columns <= 9; columns++)
{
product = rows * columns;
if (columns == 0)
{
_putchar('0');
}
else if (product <= 9)
{
_putchar(',');
_putchar(' ');
_putchar(' ');
_putchar('0' + product);
}
else
{
_putchar(',');
_putchar(' ');
_putchar('0' + product / 10);
_putchar('0' + product % 10);
}
}
_putchar('\n');
}   
}