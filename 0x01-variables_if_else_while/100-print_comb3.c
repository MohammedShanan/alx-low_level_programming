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
int tens;
int ones;
for (tens = '0'; tens <= '9'; tens++)
{
for (ones = tens + 1; ones <= '9'; ones++)
{
putchar(tens);
putchar(ones);
if (tens != '8')
{
putchar(',');
putchar(' ');
}
}
}
putchar('\n');
return (0);
}
