#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/**
 *main - Entry point
 *Return: 0
 */
int main(void)
{
for (int hundreds = '0'; hundreds <= '9'; hundreds++)
{
for (int tens = hundreds + 1; tens <= '9'; tens++)
{
for (int ones = tens + 1; ones <= '9'; ones++)
{
putchar(hundreds);
putchar(tens);
putchar(ones);
if (hundreds != '7')
{
putchar(',');
putchar(' ');
}
}
}
}
putchar('\n');
return (0);
}
