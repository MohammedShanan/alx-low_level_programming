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
char z = 'z';
int i;
for (i = z; i >= 'a'; i--)
{
putchar(i);
}
putchar('\n');
return (0);
}
