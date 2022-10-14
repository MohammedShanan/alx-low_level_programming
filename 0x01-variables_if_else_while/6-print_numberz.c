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
int zero = '0';
int i;
for (i = zero; i <= '9'; i++)
{
putchar(i);
}
putchar('\n');
return (0);
}
