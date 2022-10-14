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
char zero = '0';
char a = 'a';
int i;
for (i = zero; i <= '9'; i++)
{
putchar(i);
}
for (i = a; i <= 'f'; i++)
{
putchar(i);
}
putchar('\n');
return (0);
}
