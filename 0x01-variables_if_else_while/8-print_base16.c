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
for (int i = zero; i <= '9'; i++)
{
putchar(i);
}
for (int i = a; i <= 'f'; i++)
{
putchar(i);
}
putchar('\n');
return (0);
}
